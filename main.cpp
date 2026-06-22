void garis(int panjang = 75, char karakter = '=') {
    for (int i = 0; i < panjang; i++) cout << karakter;
    cout << "\n";
}

void garis2(int panjang = 75, char karakter = '=') {
    for (int i = 0; i < panjang; i++) cout << karakter;
}

void sentences(string teks, string warna = RESET) {
    int isiLayar  = 73; 
    int sisaSpasi = isiLayar - (int)teks.length();
    int kiri      = sisaSpasi / 2;
    int kanan     = sisaSpasi - kiri;

    cout << "|";
    garis2(kiri, ' ');
    cout << warna << teks << RESET;
    garis2(kanan, ' ');
    cout << "|\n";
}

void sentencesLeft(string teks, int indentasi = 2, string warna = RESET) {
    int isiLayar = 73; 

    cout << "|";
    garis2(indentasi, ' '); 
    cout << warna << teks << RESET;

    int sisaSpasi = isiLayar - indentasi - (int)teks.length();
    if (sisaSpasi > 0) {
        garis2(sisaSpasi, ' ');
    }
    cout << "|\n";
}

void cetakBarisKosong(int jumlah = 1) {
    for (int i = 0; i < jumlah; i++) {
        cout << "|";
        garis2(73, ' ');
        cout << "|\n";
    }
}

void Header() {
    CLS;
    garis(75, '=');
    cout << "|                                                                         |\n";
    cout << "|          " << BLUE << "o" << RESET << "                                                  " << BLUE << "o" << RESET << "           |\n";
    cout << "|        " << BLUE << ".." << RESET << "    ____                 _   _             _        " << BLUE << ".." << RESET << "         |\n";
    cout << "|       " << BLUE << "_||_" << RESET << "  / ___|  ___ ___ _ __ | |_| |     __ _  | |__    " << BLUE << "_||_" << RESET << "        |\n";
    cout << "|      " << BLUE << "|    |" << RESET << " \\___ \\ / __/ _ \\ '_ \\| __| |    / _` | | '_ \\  " << BLUE << "|    |" << RESET << "       |\n";
    cout << "|     " << BLUE << "/      \\" << RESET << " ___) | (_|  __/ | | | |_| |___| (_| | | |_) |" << BLUE << "/      \\" << RESET << "      |\n";
    cout << "|    " << BLUE << "/________\\" << RESET << "____/ \\___\\___|_| |_|\\__|_____|\\__,_|_|_.__/" << BLUE << "/________\\" << RESET << "     |\n";
    cout << "|                                                                         |\n";
    garis(75, '=');
}

void cover() {
    Header();
    cout << "\n";
    cout << "                    Tekan [ENTER] untuk mulai meracik...";
    cin.get();
}

void cetakHeaderKonten(const string &judul) {
    CLS;
    garis(75, '=');
    sentences("SCENTLAB - SIMULASI MERACIK PARFUM", GREEN);
    garis(75, '=');
    sentences(">>> " + judul + " <<<", YELLOW);
    garis(75, '-');
}

void borderPilihan(string teks, string warna = RESET) {
    int isiLayar  = 43; 
    int sisaSpasi = isiLayar - (int)teks.length();
    int kiri      = sisaSpasi / 2;
    int kanan     = sisaSpasi - kiri;

    cout << "|"; garis2(15, ' ');
    garis2(43, '-');
    garis2(15, ' '); cout << "|\n";

    cout << "|"; garis2(14, ' ');
    cout << "|";
    garis2(kiri, ' ');
    cout << warna << teks << RESET;
    garis2(kanan, ' ');
    cout << "|";
    garis2(14, ' ');
    cout << "|\n";

    cout << "|"; garis2(15, ' ');
    garis2(43, '-');
    garis2(15, ' '); cout << "|\n";
}

int pilihMenu(const string opsi[], int jumlahOpsi, const string &judulHeader = "MENU", bool tampilSplash = false, bool merahkanTerakhir = true) {
    int posisi = 0;
    int tombol;

    while (true) {
        if (tampilSplash) {
            Header();
        } else {
            CLS;
        }
        garis(75, '=');
        sentences("SCENTLAB - SIMULASI MERACIK PARFUM", GREEN);
        sentences(">>> " + judulHeader + " <<<", YELLOW);
        garis(75, '-');
        sentences("Gunakan panah [Atas/Bawah], Enter untuk memilih opsi");
        garis(75, '-');
        cetakBarisKosong(1);

        for (int i = 0; i < jumlahOpsi; i++) {
            if (i == posisi) {
                if (i < jumlahOpsi - 1 || !merahkanTerakhir) {
                    borderPilihan(opsi[i], GREEN);
                } else {
                    borderPilihan(opsi[i], RED);
                }
            } else {
                borderPilihan(opsi[i], RESET);
            }
        }

        cetakBarisKosong(1);
        garis(75, '=');
        cout << flush;

        tombol = _getch();
        if (tombol == KEY_PREFIX_WIN || tombol == KEY_PREFIX_ALT) {
            tombol = _getch();
            if (tombol == KEY_UP) {
                posisi--;
                if (posisi < 0) posisi = jumlahOpsi - 1;
            } else if (tombol == KEY_DOWN) {
                posisi++;
                if (posisi >= jumlahOpsi) posisi = 0;
            }
        } else if (tombol == KEY_ENTER) {
            return posisi;
        }
    }
}

bool pilihYaTidak(const string &pesan) {
    string opsi[2] = { "Ya, Lanjutkan", "Tidak, Batalkan" };
    int hasil = pilihMenu(opsi, 2, pesan);
    return (hasil == 0);
}