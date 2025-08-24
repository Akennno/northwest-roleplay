# Northwest Roleplay (Open.MP) 🎮

**Northwest Roleplay** adalah gamemode roleplay berbasis Open.MP (SA-MP) yang dirancang untuk memberikan pengalaman bermain roleplay yang imersif. Dengan integrasi MySQL dan struktur kode yang rapi, proyek ini cocok untuk komunitas yang ingin membangun server roleplay kustom dengan performa tinggi.

## 🚀 Fitur Utama
- **Login & Register**: Sistem autentikasi yang memungkinkan pemain untuk mendaftar akun baru dan login dengan aman ke server.
- **Save & Load**: Fitur penyimpanan dan pemuatan data pemain, memastikan progres seperti karakter, inventaris, dan statistik tersimpan dengan andal di database MySQL.

## 🧩 Panduan Instalasi
Ikuti langkah-langkah berikut untuk menyiapkan server Northwest Roleplay:

1. **Konfigurasi MySQL**  
   Edit pengaturan MySQL di file `gamemodes/lib/mysql`:
   ```c
   // Ganti dengan kredensial MySQL kalian
   #define MYSQL_HOSTNAME  "localhost"
   #define MYSQL_USERNAME  "root"
   #define MYSQL_PASSWORD  ""
   #define MYSQL_DATABASE  "northwest"
   ```
   Pastikan server MySQL aktif (contoh: XAMPP atau MariaDB).

2. **Kompilasi Gamemode**  
   Gunakan compiler PAWN untuk mengompilasi gamemode:
   ```bash
   pawncc gamemodes/northwest.pwn
   ```
   Pastikan semua plugin dan include (seperti `mysql`, `sscanf`, `streamer`) sudah ada di folder `pawno/include` dan `plugins`.

3. **Impor Database**  
   Impor file `northwest.sql` ke database MySQL melalui phpMyAdmin:
   - Buka phpMyAdmin.
   - Buat database bernama `northwest`.
   - Gunakan tab *Import* untuk mengunggah `northwest.sql`.

4. **Jalankan Server**  
   Jalankan server Open.MP:
   - Windows: Klik `samp-server.exe`.
   - Linux: Jalankan `./samp03svr`.
   Pastikan `server.cfg` sudah dikonfigurasi dengan benar.

## 🛠️ Prasyarat
- **Open.MP Server**: Unduh dari [open.mp](https://www.open.mp/).
- **MySQL Server**: XAMPP, MariaDB, atau MySQL server lainnya.
- **PAWN Compiler**: Untuk mengompilasi file `.pwn`.
- **Plugin yang Diperlukan**:
  - mysql (R41-4 atau lebih baru)
  - sscanf
  - streamer
  - (Tambahkan plugin lain jika diperlukan)

## 📂 Struktur Direktori
```
northwest-rp/
├── gamemodes/
│   ├── northwest.pwn        # File gamemode utama
│   └── lib/
│       └── mysql            # Konfigurasi MySQL
├── plugins/                 # Plugin server
├── include/                 # File include PAWN
├── northwest.sql            # Skema database
└── server.cfg               # Konfigurasi server
```

## 🤝 Kontribusi
Kami menyambut kontribusi dari komunitas! Untuk berkontribusi:
1. Fork repository ini.
2. Buat branch baru: `git checkout -b fitur-baru`.
3. Commit perubahan: `git commit -m "Menambahkan fitur X"`.
4. Push ke branch: `git push origin fitur-baru`.
5. Buat Pull Request di GitHub.

Laporkan bug atau saran di tab [Issues](https://github.com/Akennno/northwest-roleplay/issues).

## 📃 Lisensi
Dilisensikan di bawah [MIT License](LICENSE) – bebas untuk dimodifikasi, didistribusikan, dan digunakan untuk keperluan pribadi maupun komersial.

## 📬 Kontak
Punya pertanyaan? Hubungi kami melalui [GitHub Issues](https://github.com/Akennno/northwest-roleplay/issues) atau bergabung dengan komunitas kami di [Discord](#) (ganti dengan link Discord jika ada).

---
⭐ **Star repository ini jika kamu menyukainya!**  
Terima kasih telah menggunakan Northwest Roleplay. Selamat membangun server impianmu! 🚀