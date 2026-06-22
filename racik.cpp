int pilihUkuranBotol() {
    string opsi[3] = { "Botol Kecil  (30 ml)", "Botol Sedang (50 ml)", "Botol Besar  (100 ml)" };
    int hasil = pilihMenu(opsi, 3, "KONFIGURASI UKURAN BOTOL", false, false);
    if (hasil == 0) return 30;
    else if (hasil == 2) return 100;
    else return 50;
}

void menuRacik(BibitParfum gudang[], int jml_gudang, ResepGaleri galeri[], int *jml_galeri) {
    if (*jml_galeri >= MAX_GALERI) {
        cetakHeaderKonten("MEJA RACIK");
        sentences("[!] Galeri sudah penuh!", RED);
        garis(75, '=');
        cin.get();
        return;
    }

    ResepGaleri botolBaru;
    botolBaru.kapasitas_maks = pilihUkuranBotol();
    botolBaru.total_volume = 0;
    botolBaru.total_harga  = 0;
    botolBaru.indeks_bahan = 0;

    bool tambahLagi = true;
    do {
        cetakHeaderKonten("MEJA RACIK - PROSES PERACIKAN");
        cout << "|   Status Botol: " << botolBaru.total_volume << " / " << botolBaru.kapasitas_maks<< " ml | Modal: Rp " << botolBaru.total_harga << "\n";
        cout << "|"; garis2(73, '='); cout << "|\n";
        tampilGudang(gudang, jml_gudang, false);

        int id_pilihan, takaran;
        bacaInt(id_pilihan, "ID Bahan yang ingin dimasukkan: ", 1, jml_gudang);
        bacaInt(takaran,    "Takaran Bahan (ml)            : ", 1, botolBaru.kapasitas_maks);

        int found = -1;
        for (int i = 0; i < jml_gudang; i++) {
            if (gudang[i].id == id_pilihan) { found = i; break; }
        }
        if (found == -1) cout << "|   [!] ID tidak valid.\n";
        else tambahBahan(&botolBaru, &gudang[found], takaran);

        if (botolBaru.total_volume >= botolBaru.kapasitas_maks) {
            cout << "|   [!] Botol racikan telah penuh.\n";
            break;
        }

        cout << "| \n|   Tekan [ENTER] untuk memproses...";
        cin.get();
        tambahLagi = pilihYaTidak("Tambah jenis bibit aroma lagi?");
    } while (tambahLagi && botolBaru.total_volume < botolBaru.kapasitas_maks);

    if (botolBaru.indeks_bahan == 0) return;

    bool beriNama = pilihYaTidak("Beri nama kustom/manual pada resep ini?");
    if (beriNama) {
        cetakHeaderKonten("BERI NAMA RACIKAN");
        botolBaru.nama_parfum = bacaString("Nama Parfum Kustom: ");
        cout << "| Deskripsi Vibes   : ";
        getline(cin, botolBaru.vibes);
    } else {
        autoNaming(&botolBaru);
    }

    if (pilihYaTidak("Simpan mahakarya racikan ini ke Galeri?")) {
        galeri[*jml_galeri] = botolBaru;
        (*jml_galeri)++;
        cetakHeaderKonten("BERHASIL");
        sentences("[+] Resep Berhasil Diamankan ke Galeri!", GREEN);
    } else {
        cetakHeaderKonten("BATAL");
        sentences("[X] Formula dibuang. Sisa stok bahan tidak kembali.", RED);
    }
    garis(75, '=');
    cout << "|   Tekan [ENTER] untuk kembali ke Menu Utama...";
    cin.get();
}