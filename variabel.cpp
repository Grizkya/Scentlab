#include <iostream>
#include <string>
using namespace std;

struct Komposisi {
    int idBahan;
    float takaranMl;
};

// Struct untuk Katalog Bahan Baku
struct BibitParfum {
    int idBahan;
    string nama;
    string kategori;
    float hargaPerMl;
    float stokMl;
};

// Struct untuk Galeri Parfum yang sudah diracik
struct BotolRacikan {
    string namaParfum;
    string deskripsiVibes;
    string rekomendasi;
    float totalTakaran;
    float totalHarga;
    Komposisi bahanCampuran[10]; // Maksimal 10 bahan per botol
    int jumlahBahanTerpakai;
};

// =========================================================================
// Deklarasi Array Global untuk Katalog dan Galeri
// =========================================================================
const int MAKS_KATALOG = 50;
const int MAKS_GALERI = 100;

BibitParfum katalogBahan[MAKS_KATALOG];
int jumlahKatalog = 0; // Penghitung jumlah bahan baku saat ini

BotolRacikan galeriParfum[MAKS_GALERI];
int jumlahGaleri = 0; // Penghitung jumlah parfum racikan saat ini

// TUGAS: Anggota 2 membuat fungsi untuk mengisi data awal (data dummy) agar tidak kosong
void inisialisasiDataDummy() {
    // Format pengisian: {idBahan, "Nama Bahan", "Kategori", hargaPerMl, stokMl}
    
    // Kategori: Sweet & Gourmand (1-7)
    katalogBahan[0] = {101, "Vanilla Madagascar", "Sweet", 2500, 500.0};
    katalogBahan[1] = {102, "Tonka Bean", "Sweet", 2800, 350.0};
    katalogBahan[2] = {103, "Dark Chocolate", "Sweet", 2000, 400.0};
    katalogBahan[3] = {104, "Roasted Coffee", "Sweet", 1800, 450.0};
    katalogBahan[4] = {105, "Caramel Syrup", "Sweet", 1500, 600.0};
    katalogBahan[5] = {106, "Honey Blossom", "Sweet", 2200, 300.0};
    katalogBahan[6] = {107, "Almond Extract", "Sweet", 1900, 350.0};

    // Kategori: Woody & Earthy (8-16)
    katalogBahan[7] = {108, "Sandalwood Extract", "Woody", 3500, 300.0};
    katalogBahan[8] = {109, "Cedarwood Virginia", "Woody", 2100, 500.0};
    katalogBahan[9] = {110, "Oud Agarwood", "Woody", 8500, 100.0}; // Bahan langka/mahal
    katalogBahan[10] = {111, "Vetiver Haiti", "Woody", 2700, 250.0};
    katalogBahan[11] = {112, "Patchouli", "Woody", 2300, 400.0};
    katalogBahan[12] = {113, "Pine Needles", "Woody", 1200, 600.0};
    katalogBahan[13] = {114, "Cypress", "Woody", 1600, 450.0};
    katalogBahan[14] = {115, "Rosewood", "Woody", 3200, 200.0};
    katalogBahan[15] = {116, "Oakmoss Absolute", "Woody", 4000, 150.0};

    // Kategori: Fresh & Citrus (17-26)
    katalogBahan[16] = {117, "Bergamot Calabria", "Fresh", 1800, 750.0};
    katalogBahan[17] = {118, "Lemon Zest", "Fresh", 1200, 800.0};
    katalogBahan[18] = {119, "Mandarin Orange", "Fresh", 1400, 700.0};
    katalogBahan[19] = {120, "Grapefruit Pink", "Fresh", 1500, 650.0};
    katalogBahan[20] = {121, "Lime Extract", "Fresh", 1300, 700.0};
    katalogBahan[21] = {122, "Neroli Blossom", "Fresh", 4500, 200.0};
    katalogBahan[22] = {123, "Yuzu Japan", "Fresh", 3000, 250.0};
    katalogBahan[23] = {124, "Lemongrass", "Fresh", 1100, 900.0};
    katalogBahan[24] = {125, "Petitgrain", "Fresh", 1700, 500.0};
    katalogBahan[25] = {126, "Green Tea Leaf", "Fresh", 1600, 600.0};

    // Kategori: Floral (27-36)
    katalogBahan[26] = {127, "Rose Absolute", "Floral", 5500, 150.0};
    katalogBahan[27] = {128, "Jasmine Sambac", "Floral", 4800, 200.0};
    katalogBahan[28] = {129, "Lavender French", "Floral", 2000, 600.0};
    katalogBahan[29] = {130, "Ylang Ylang", "Floral", 2400, 400.0};
    katalogBahan[30] = {131, "Iris Pallida", "Floral", 6000, 100.0};
    katalogBahan[31] = {132, "Peony Petals", "Floral", 2600, 350.0};
    katalogBahan[32] = {133, "Black Orchid", "Floral", 3500, 250.0};
    katalogBahan[33] = {134, "Violet Leaf", "Floral", 2200, 300.0};
    katalogBahan[34] = {135, "Lily of the Valley", "Floral", 3100, 200.0};
    katalogBahan[35] = {136, "Chamomile", "Floral", 1800, 500.0};

    // Kategori: Spicy & Oriental (37-44)
    katalogBahan[36] = {137, "Cinnamon Bark", "Spicy", 1500, 500.0};
    katalogBahan[37] = {138, "Clove Bud", "Spicy", 1400, 550.0};
    katalogBahan[38] = {139, "Nutmeg Extract", "Spicy", 1600, 450.0};
    katalogBahan[39] = {140, "Cardamom Pods", "Spicy", 2800, 300.0};
    katalogBahan[40] = {141, "Black Pepper", "Spicy", 1300, 600.0};
    katalogBahan[41] = {142, "Ginger Root", "Spicy", 1200, 650.0};
    katalogBahan[42] = {143, "Saffron", "Spicy", 9000, 50.0}; // Rempah termahal
    katalogBahan[43] = {144, "Star Anise", "Spicy", 1700, 400.0};

    // Kategori: Musk, Amber & Aquatic (45-50)
    katalogBahan[44] = {145, "White Musk", "Musk", 2500, 800.0};
    katalogBahan[45] = {146, "Black Musk", "Musk", 2700, 600.0};
    katalogBahan[46] = {147, "Ambergris", "Musk", 8000, 100.0};
    katalogBahan[47] = {148, "Sea Salt Breeze", "Aquatic", 1500, 900.0};
    katalogBahan[48] = {149, "Ocean Mist", "Aquatic", 1600, 850.0};
    katalogBahan[49] = {150, "Coconut Water", "Aquatic", 1200, 700.0};

    // Mengunci total data yang dimasukkan agar sesuai dengan kapasitas
    jumlahKatalog = 50; 
}