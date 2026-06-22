# PROYEK ALGORITMA DAN PEMROGRAMAN
## 🧪 SCENTLAB - Simulasi Meracik Parfum.
  Program “SCENTLAB - Simulasi Meracik Parfum” adalah aplikasi *Command Line Interface* (CLI) yang menggunakan bahasa C++ untuk mennyimulasikan manajemen inventaris dan peracikan parfum. Secara teknis, program ini memanfaatkan *Array of Struct* 
(AoS) sebagai basis data penyimpanan resep dan pointer untuk memastikan sinkronisasi 
pemotongan memori stok gudang secara real-time. Antarmuka program dirancang interaktif 
menggunakan *Boxed* UI dan navigasi tombol panah (Arrow Keys), menyajikan opsi utama 
yang diawali dengan fitur Katalog Gudang & Restok Bahan untuk memantau ketersediaan 
bibit aroma serta melakukan pengisian ulang stok. 

  Proses operasional inti berlangsung pada menu Buka Meja Racik, di mana pengguna 
dapat memilih ukuran botol (30 ml, 50 ml, atau 100 ml) dan mengombinasikan berbagai 
takaran bibit parfum. Sistem ini dibekali dengan algoritma validasi pertahanan (error 
handling) yang ketat, di mana program akan otomatis menolak eksekusi jika *input* tidak 
valid, stok gudang kurang, atau takaran melebihi sisa kapasitas botol. Setelah meracik, 
pengguna dapat memberikan nama parfum secara manual maupun menggunakan fitur *auto
naming* dari sistem untuk kemudian menyimpannya ke dalam arsip. 

  Seluruh resep yang telah dibuat dapat diakses melalui menu Lihat Galeri Parfum. Pada 
galeri ini, data diarsipkan secara terstruktur dan ditampilkan lengkap dengan rincian 
kapasitas, riwayat komposisi bahan per mililiter, serta kalkulasi total modal biaya produksi 
secara otomatis. Melalui integrasi fitur dan keamanan logika prosedural tersebut, 
SCENTLAB menghadirkan simulasi laboratorium wewangian yang presisi, efisien, dan 
kebal terhadap *human error*.
