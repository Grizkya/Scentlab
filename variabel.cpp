#include <iostream>
#include <string>
using namespace std;


struct BibitParfum {
    int idBahan;
    string nama;
    string kategori;
    float hargaPerMl;
    float stokMl; 
};

struct Komposisi {
    int idBahan;
    float takaranMl;
};

struct BotolRacikan {
    string namaParfum;
    string deskripsiVibes;
    string rekomendasi;
    float totalTakaran;
    float totalHarga;
    Komposisi bahanCampuran[10]; 
    int jumlahBahanTerpakai;
};

const int MAKS_KATALOG = 50;  
const int MAKS_GALERI = 100;  

BibitParfum arrayKatalog[MAKS_KATALOG] = {
    {1, "Vanilla Bourbon", "Gourmand", 5000, 1000},
    {2, "Bergamot Italy", "Citrus", 6500, 800},
    {3, "Sandalwood", "Woody", 8000, 500},
    {4, "Jasmine Sambac", "Floral", 7500, 600},
    {5, "White Musk", "Musk", 4000, 1200},
    {6, "Patchouli", "Earthy", 5500, 700},
    {7, "Rose Damascena", "Floral", 9000, 400},
    {8, "Sweet Orange", "Fruity", 3500, 1500},
    {9, "Oud Wood", "Woody", 12000, 300},
    {10, "Lavender Mint", "Fresh", 4500, 1000}
};

int jumlahBahanKatalog = 10; 

BotolRacikan arrayGaleri[MAKS_GALERI]; 

int jumlahParfumGaleri = 0;
