#include <iostream>
#include <string>

using namespace std;

// =========================================================================
// [TUGAS ANGGOTA 2]: Pengembang Database & Struct Dasar
// Nama Tugas: Deklarasi Struct & Inisialisasi Data Dummy
// =========================================================================
// TUGAS: Anggota 2 silakan isi definisi struct di bawah ini 
// (Contoh: Struct untuk BibitParfum, BotolRacikan, GaleriParfum, dll)
struct BibitParfum {
    // Isi variabel struct di sini (contoh: id, nama, kategori, harga, stok)
};

struct BotolRacikan {
    // Isi variabel struct di sini (contoh: totalVolume, totalHarga, namaRacikan)
};

// TUGAS: Anggota 2 silakan deklarasikan Array Global untuk Katalog dan Galeri di sini
// (Sesuai Modul 3: Array Katalog dan Array Galeri)


// TUGAS: Anggota 2 membuat fungsi untuk mengisi data awal (data dummy) agar tidak kosong
void inisialisasiDataDummy() {
    // Isi puluhan data awal untuk katalog bahan baku di sini
}
// =========================================================================


// =========================================================================
// [TUGAS ANGGOTA 6]: Pengembang Fitur Pencarian & Analitik (Searching/Sorting)
// Nama Tugas: Fungsi Tampilkan Katalog, Searching Aroma, & Sorting Harga
// =========================================================================
void tampilkanKatalog() {
    // TUGAS: Buat fungsi untuk menampilkan seluruh isi katalog bahan baku
}

void cariBahanBaku() {
    // TUGAS: Buat fungsi untuk mencari bahan berdasarkan "Kategori Aroma" (Searching)
}

void urutkanBahanBaku() {
    // TUGAS: Buat fungsi untuk mengurutkan bahan dari termurah/termahal (Sorting)
}
// =========================================================================


// =========================================================================
// [TUGAS ANGGOTA 3 & 4]: Ahli Logika Peracikan & Eksekutor Pointer
// Nama Tugas: Fungsi Peracikan Bahan & Manipulasi Memori via Pointer
// =========================================================================
// TUGAS: Anggota 3 membuat logika hitungan matematika (harga * takaran)
// TUGAS: Anggota 4 menggunakan parameter POINTER untuk mengurangi stok gudang & menambah isi botol
void racikBahanParfum(/* Gunakan parameter pointer di sini jika diperlukan */) {
    // Isi logika peracikan, validasi volume, dan hitungan harga di sini
}
// =========================================================================


// =========================================================================
// [TUGAS ANGGOTA 5]: Arsitek Galeri & Fitur Auto-Naming
// Nama Tugas: Validasi Penamaan (Manual/Otomatis) & Menyimpan ke Galeri
// =========================================================================
void simpanKeGaleri() {
    // TUGAS: Buat algoritma if-else jika pengguna tidak memberi nama (Auto-Naming)
    // Lalu pindahkan/simpan data hasil racikan ke Array Galeri
}

void tampilkanGaleri() {
    // TUGAS: Buat fungsi untuk menampilkan seluruh daftar parfum di Array Galeri
}
// =========================================================================


// =========================================================================
// [TUGAS ANGGOTA 7]: Spesialis Validasi (Quality Assurance & Error Handling)
// Nama Tugas: Fungsi Validasi Input global
// =========================================================================
// Keterangan: Anggota 7 bertugas menyisipkan validasi di fungsi-fungsi milik 
// anggota lain (misal: cek input negatif, input menu salah, atau botol luber).
// Bisa juga membuat fungsi pembantu di bawah ini:
bool validasiInputAngka(int input) {
    // Isi logika pengecekan validasi di sini
    return true;
}
// =========================================================================


// =========================================================================
// [TUGAS KAMU - ANGGOTA 1]: Manajer Antarmuka & Navigasi (UI/UX Terminal)
// Nama Tugas: Pembuatan ASCII Art, Menu Utama (Do-While & Switch-Case)
// =========================================================================
void tampilkanLogoASCII() {
    // Kamu bisa edit atau ganti tulisan ASCII Art ini sesuka hatimu
    cout << "=========================================================\n";
    cout << "  ____   _    ____  _____ _   _ __  __   ____ _     ___  \n";
    cout << " |  _ \\ / \\  |  _ \\|  ___| | | |  \\/  | / ___| |   |_ _| \n";
    cout << " | |_) / _ \\ | |_) | |_  | | | | |\\/| | |     | |    | |  \n";
    cout << " |  __/ ___ \\|  _ <|  _| | |_| | |  | | |___  | |___ | |  \n";
    cout << " |_| /_/   \\_\\_| \\_\\_|    \\___/|_|  |_|  \\____|_____|___| \n";
    cout << "               SISTEM LAYERING PARFUM UMKM               \n";
    cout << "=========================================================\n";
}

int main() {
    // Memanggil data awal milik Anggota 2 saat program pertama kali dibuka
    // inisialisasiDataDummy(); 

    int pilihanMenu;

    // Modul 2: Implementasi Looping Do-While agar program terus berjalan
    do {
        tampilkanLogoASCII();
        cout << " [1] Lihat Katalog Bahan Baku\n";
        cout << " [2] Cari Bahan Baku (Berdasarkan Aroma)\n";
        cout << " [3] Urutkan Bahan Baku (Berdasarkan Harga)\n";
        cout << " [4] Mulai Racik Parfum Baru (Layering)\n";
        cout << " [5] Lihat Galeri Parfum Racikan\n";
        cout << " [6] Keluar dari Aplikasi\n";
        cout << "--------------------------------=========================\n";
        cout << " Pilih Menu (1-6): ";
        cin >> pilihanMenu;

        // Modul 2: Implementasi Switch-Case untuk Navigasi Menu
        switch (pilihanMenu) {
            case 1:
                cout << "\n[MENAMPILKAN KATALOG]\n";
                tampilkanKatalog(); // Memanggil fungsi Anggota 6
                break;
            case 2:
                cout << "\n[PENCARIAN BAHAN BAKU]\n";
                cariBahanBaku(); // Memanggil fungsi Anggota 6
                break;
            case 3:
                cout << "\n[PENGURUTAN KATALOG]\n";
                urutkanBahanBaku(); // Memanggil fungsi Anggota 6
                break;
            case 4:
                cout << "\n[PROSES LAYERING PARFUM]\n";
                // Memanggil fungsi Anggota 3 & 4
                // racikBahanParfum(); 
                
                // Setelah selesai meracik, panggil fungsi simpan Anggota 5
                // simpanKeGaleri(); 
                break;
            case 5:
                cout << "\n[MENAMPILKAN GALERI PARFUM]\n";
                tampilkanGaleri(); // Memanggil fungsi Anggota 5
                break;
            case 6:
                cout << "\n=========================================================\n";
                cout << " Terima kasih! Program selesai.\n";
                cout << "=========================================================\n";
                break;
            default:
                cout << "\n Pilihan tidak valid! Silakan masukkan angka 1-6.\n";
                // Di sini nanti bisa dikoordinasikan dengan Anggota 7 untuk handling error
                break;
        }
        cout << "\n";
        
    } while (pilihanMenu != 6); // Program berhenti jika memilih menu 6

    return 0;
}
// =========================================================================