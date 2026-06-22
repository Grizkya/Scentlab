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
// Main
int main()
{

}
