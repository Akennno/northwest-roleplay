# Northwest Roleplay (Open.MP) 🎮

**Northwest Roleplay** adalah gamemode roleplay berbasis Open.MP (SA-MP) yang dirancang untuk memberikan pengalaman bermain roleplay yang imersif. Dengan integrasi MySQL dan struktur kode yang rapi.

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
   Setelah menyesuaikan kredensial MySQL lalu compile gamemode ini

3. **Impor Database**  
   Impor file `northwest.sql` ke database MySQL melalui phpMyAdmin:
   - Buka phpMyAdmin.
   - Buat database bernama `northwest`.
   - Gunakan tab *Import* untuk mengunggah `northwest.sql`.

4. **Jalankan Server**  
   Jalankan server Open.MP:
   - Windows: Klik `samp-server.exe`.
   - Pastikan `config.json` udah dikonfigurasi dengan benar.


## 🛠️ Prasyarat
- **MySQL Server**: XAMPP, MariaDB, atau MySQL server lainnya.

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
