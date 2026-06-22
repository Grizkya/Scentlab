#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <conio.h>
#include <sstream>

using namespace std;

// ANSI Escape Code
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"
#define CLS cout << "\033[2J\033[H" << flush

// Konstanta Global
const int MAX_GUDANG     = 20;
const int MAX_GALERI     = 50;
const int MAX_KOMPOSISI  = 15;
const int KEY_PREFIX_WIN = 224;
const int KEY_PREFIX_ALT = 0;
const int KEY_UP         = 72;
const int KEY_DOWN       = 80;
const int KEY_ENTER      = 13;

struct BibitParfum {
    int    id;
    string nama;
    string aroma;
    int    stok_ml;
    int    harga_per_ml;
    bool   aktif;
};

struct Campuran {
    string nama_bahan;
    int    takaran_ml;
    int    subtotal_harga;
};

struct ResepGaleri {
    string   nama_parfum;
    string   vibes;
    int      kapasitas_maks;
    int      total_volume;
    int      total_harga;
    Campuran riwayat[MAX_KOMPOSISI];
    int      indeks_bahan;
};

void setGudang(BibitParfum &b, int id, const string &nama, const string &aroma, int stok, int harga) {
    b.id = id; b.nama = nama; b.aroma = aroma;
    b.stok_ml = stok; b.harga_per_ml = harga; b.aktif = true;
}

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

void inisialisasiGudang(BibitParfum gudang[], int *jml_gudang) {
    setGudang(gudang[0],  1,  "Bergamot",      "Fruity",   500, 2000);
    setGudang(gudang[1],  2,  "Sweet Pine",    "Fruity",   300, 1500);
    setGudang(gudang[2],  3,  "Pink Pepper",   "Spicy",    250, 1800);
    setGudang(gudang[3],  4,  "Lemon Zest",    "Fresh",    400, 1200);
    setGudang(gudang[4],  5,  "Jasmine",       "Floral",   400, 3000);
    setGudang(gudang[5],  6,  "Rose Absolute", "Floral",   350, 3500);
    setGudang(gudang[6],  7,  "Neroli",        "Fresh",    300, 2800);
    setGudang(gudang[7],  8,  "Patchouli",     "Oriental", 200, 2200);
    setGudang(gudang[8],  9,  "Vanilla",       "Sweet",    300, 2500);
    setGudang(gudang[9],  10, "Oud Wood",      "Woody",    150, 4500);
    setGudang(gudang[10], 11, "Sandalwood",    "Woody",    200, 4000);
    setGudang(gudang[11], 12, "Musk",          "Sweet",    400, 1800);
    *jml_gudang = 12;
}

void setCampuran(Campuran &c, const string &nama, int takaran, int subtotal) {
    c.nama_bahan = nama; c.takaran_ml = takaran; c.subtotal_harga = subtotal;
}

void inisialisasiGaleri(ResepGaleri galeri[], int *jml_galeri) {
    galeri[0].nama_parfum    = "Ocean Breeze";
    galeri[0].vibes          = "Fresh & Aquatic";
    galeri[0].kapasitas_maks = 50;
    galeri[0].total_volume   = 40;
    setCampuran(galeri[0].riwayat[0], "Bergamot",   25, 25 * 2000);
    setCampuran(galeri[0].riwayat[1], "Lemon Zest", 15, 15 * 1200);
    galeri[0].indeks_bahan   = 2;
    galeri[0].total_harga    = (25 * 2000) + (15 * 1200);

    galeri[1].nama_parfum    = "Midnight Velvet";
    galeri[1].vibes          = "Dark & Seductive";
    galeri[1].kapasitas_maks = 50;
    galeri[1].total_volume   = 50;
    setCampuran(galeri[1].riwayat[0], "Jasmine",  15, 15 * 3000);
    setCampuran(galeri[1].riwayat[1], "Vanilla",  20, 20 * 2500);
    setCampuran(galeri[1].riwayat[2], "Oud Wood", 15, 15 * 4500);
    galeri[1].indeks_bahan   = 3;
    galeri[1].total_harga    = (15 * 3000) + (20 * 2500) + (15 * 4500);

    *jml_galeri = 2;
}
//apri

//amel

//ozan
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
// rasyad
void tampilGudang(BibitParfum gudang[], int jml_gudang, bool tampilHabis = false) {
    cout << left<< "| " << setw(5)  << "ID"<< setw(18) << "Nama Bahan"<< setw(13) << "Aroma"<< setw(12) << "Stok(ml)"<< setw(13) << "Harga/ml"<< " Status    |\n";
    cout << "|"; garis2(73, '-'); cout << "|\n";

    bool adaBahan = false;
    for (int i = 0; i < jml_gudang; i++) {
        if (!tampilHabis && gudang[i].stok_ml == 0) continue;
        adaBahan = true;

        string status;
        if (gudang[i].stok_ml == 0) {
            status = "[HABIS]   ";
        } else if (gudang[i].stok_ml < 50) {
            status = "[Menipis] ";
        } else {
            status = "[Tersedia]";
        }

        cout << left<< "| " << setw(5)  << gudang[i].id<< setw(18) << gudang[i].nama<< setw(13) << gudang[i].aroma<< setw(12) << gudang[i].stok_ml<< "Rp " << setw(10) << gudang[i].harga_per_ml<< status << " |\n";
    }
    if (!adaBahan) 
    cout << "|"; garis2(74, '-'); cout << "|\n";
}

void menuKatalog(BibitParfum gudang[], int jml_gudang) {
    string opsiMenu[3] = {"Katalog Gudang (Lihat Stok)", "Restok Bahan Baku", "Kembali ke Menu Utama" };
    int pilihanMenu;

    do {
        pilihanMenu = pilihMenu(opsiMenu, 3, "MANAJEMEN GUDANG & KATALOG");
        
        switch (pilihanMenu) {
            case 0: // melihat katalog gudang
                cetakHeaderKonten("KATALOG STOK GUDANG");
                tampilGudang(gudang, jml_gudang, true);
                cout << "| \n|   Tekan [ENTER] untuk kembali ke Submenu...";
                cout << flush; // Pastikan teks langsung muncul
                cin.get();
                break;
                
            case 1: // Restok bahan baku
                cetakHeaderKonten("RESTOK BAHAN GUDANG");
                tampilGudang(gudang, jml_gudang, true);
                int idRestok, jumlahRestok;
                cout << "| \n";
                bacaInt(idRestok, "Masukkan ID bahan baku: ", 1, jml_gudang);
                
                int found = -1;
                for (int i = 0; i < jml_gudang; i++) {
                    if (gudang[i].id == idRestok) { found = i; break; }
                }
                if (found == -1) {
                    cout << "|   [!] ID Tidak ditemukan.\n";
                } else {
                    bacaInt(jumlahRestok, "Jumlah restok (ml): ", 1, 5000);
                    restokBahan(&gudang[found], jumlahRestok);
                }
                cout << "| \n|   Tekan [ENTER] untuk kembali ke Submenu...";
                cout << flush;
                cin.get();
                break;
        }
    } while (pilihanMenu != 2);
}

int main()
{
}
