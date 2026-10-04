# TP3DPBO2526C2 - Sistem Manajemen Ladang

Tugas Praktikum dalam Mata Kuliah DPBO: Hierarchical, Multiple, Hybrid Inheritance dan Class Relationship.
Total **7 class**: Tanaman, TanamanPangan, TanamanSayur, TanamanBuah, Petani, AlatPertanian, Ladang.

## JANJI

Saya Muhammad Hanif Muyassar dengan NIM 2510593 mengerjakan Tugas Praktikum 3 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

## MAPPING KE SYARAT TUGAS

| Syarat tugas | Dipenuhi oleh |
|---|---|
| Composition | Ladang ◆— Petani (1), Ladang ◆— Tanaman (0..*), Ladang ◆— AlatPertanian (0..*) |
| Array of object | `daftarTanaman: vector<Tanaman*>` dan `daftarAlat: vector<AlatPertanian*>` di dalam Ladang |
| Hierarchical Inheritance | Tanaman (abstract) → TanamanPangan, TanamanSayur, TanamanBuah |
| Minimal 4 class | Total 7 class: Tanaman, TanamanPangan, TanamanSayur, TanamanBuah, Petani, AlatPertanian, Ladang |
| Materi tambahan (bonus) | Abstract class + polimorfisme lewat `getKategori()`/`tampilkanInfo()` yang di-override tiap turunan Tanaman |

## DESAIN DIAGRAM PROGRAM

```
              +--------+
              | Petani |
              +--------+
                  ^
                  | ◆— (1) pemilik
                  |
+---------------+ | +------------------+
| AlatPertanian | | | Tanaman (abstract)|
+---------------+ | +------------------+
   ^              |        ^
   | ◆— (0..*)    |        | hierarchical
   |              |   +----+----+----+
   |              |   |         |    |
   +----------+---+---+--+ +----+---+ +----+-----+
              | Ladang    | | Pangan | | Sayur  | | Buah   |
              +-----------+ +--------+ +--------+ +--------+
              | daftarTanaman: Tanaman* (0..*)               |
              | daftarAlat: AlatPertanian* (0..*)            |
              +---------------------------------------------+
```

- `Ladang` adalah orkestrator: memegang 1 `Petani` + 2 array (`daftarTanaman`, `daftarAlat`).
- `daftarTanaman` bertipe pointer/reference ke `Tanaman` abstrak, diisi objek `TanamanPangan/Sayur/Buah`
  sehingga `tampilkanSemuaTanaman()` memanggil `tampilkanInfo()` versi override masing-masing (polimorfisme).

## PENJELASAN ATRIBUT & METHOD

### 1. Tanaman (abstract)

| Atribut | Tipe Data | Keterangan |
|---|---|---|
| idTanaman | string | ID unik tanaman |
| nama | string | Nama tanaman |
| luasTanamM2 | double | Luas lahan yang dipakai tanaman ini (m²) |
| tanggalTanam | string | Tanggal mulai ditanam (YYYY-MM-DD) |

| Method | Return | Parameter | Keterangan |
|---|---|---|---|
| getIdTanaman() / getNama() / getLuasTanamM2() / getTanggalTanam() | sesuai atribut | – | Getter standar |
| hitungUmurTanamHari() | int | – | Concrete (bukan abstract) — hitung selisih hari dari tanggalTanam sampai sekarang, dipakai sama persis oleh semua turunan |
| getKategori() | string | – | Abstract — override tiap turunan |
| tampilkanInfo() | void | – | Abstract — override tiap turunan |

Catatan: Tanaman sengaja punya campuran method concrete (`hitungUmurTanamHari`) dan abstract
(`getKategori`, `tampilkanInfo`) — nunjukkin nggak semua method di abstract class harus abstract,
cuma yang memang butuh perilaku beda per turunan.

### 2–4. Turunan Tanaman (Hierarchical Inheritance)

| Class | Atribut | Tipe Data | Keterangan |
|---|---|---|---|
| TanamanPangan | jenisPangan | string | Misal "Padi", "Jagung" |
| | kebutuhanAirLiterPerHari | double | Kebutuhan air harian |
| TanamanSayur | jenisSayur | string | Misal "Bayam", "Kangkung" |
| | masaPanenHari | int | Berapa hari sampai siap panen |
| TanamanBuah | jenisBuah | string | Misal "Mangga", "Jeruk" |
| | tinggiPohonM | double | Tinggi pohon (meter) |

Ketiganya override `getKategori()` (return "Tanaman Pangan" / "Tanaman Sayur" / "Tanaman Buah")
dan `tampilkanInfo()` (cetak atribut Tanaman + atribut spesifiknya sendiri).

### 5. Petani

| Atribut | Tipe Data | Keterangan |
|---|---|---|
| idPetani | string | ID unik petani |
| nama | string | Nama petani |
| alamat | string | Alamat tempat tinggal |
| tahunMulaiBertani | int | Tahun mulai jadi petani |

| Method | Return | Keterangan |
|---|---|---|
| getIdPetani() / getNama() / getAlamat() | sesuai atribut | Getter |
| getPengalamanTahun() | int | Hitung tahun sekarang − tahunMulaiBertani |
| tampilkanInfoPetani() | void | Cetak semua info petani |

### 6. AlatPertanian

| Atribut | Tipe Data | Keterangan |
|---|---|---|
| idAlat | string | ID unik alat |
| namaAlat | string | Misal "Cangkul", "Traktor", "Sprayer" |
| kondisi | string | "Baik" / "Rusak" / "Perlu Perawatan" |
| tahunBeli | int | Tahun alat dibeli |

| Method | Return | Parameter | Keterangan |
|---|---|---|---|
| getIdAlat() / getNamaAlat() / getKondisi() | sesuai atribut | – | Getter |
| setKondisi(baru) | void | string | Update status kondisi alat |
| tampilkanInfoAlat() | void | – | Cetak detail alat |

### 7. Ladang (class utama/orkestrator)

| Atribut | Tipe Data | Keterangan |
|---|---|---|
| idLadang | string | ID unik ladang |
| namaLadang | string | Nama ladang/kebun |
| luasTotalM2 | double | Luas total lahan |
| lokasi | string | Lokasi ladang |
| pemilik | Petani | Composition (1) — satu ladang dimiliki satu petani |
| daftarTanaman | vector\<Tanaman*\> | Composition + array of object (0..*) |
| daftarAlat | vector\<AlatPertanian*\> | Composition + array of object (0..*) |

| Method | Return | Parameter | Keterangan |
|---|---|---|---|
| tanamTanamanBaru(tanaman) | void | Tanaman* | Tambahkan tanaman ke daftarTanaman |
| tambahAlat(alat) | void | AlatPertanian* | Tambahkan alat ke daftarAlat |
| tampilkanSemuaTanaman() | void | – | Loop daftarTanaman, panggil tampilkanInfo() tiap elemen (polimorfisme) |
| tampilkanSemuaAlat() | void | – | Loop daftarAlat, cetak tiap alat |
| hitungTotalLuasTertanam() | double | – | Jumlahkan luasTanamM2 dari seluruh daftarTanaman |
| hitungSisaLuasLadang() | double | – | luasTotalM2 − hitungTotalLuasTertanam() |
| tampilkanInfoLadang() | void | – | Cetak namaLadang, lokasi, lalu panggil pemilik.tampilkanInfoPetani() |

## PENJELASAN DESAIN PROGRAM

1. **Hierarchical Inheritance:** `Tanaman` (abstract) → `TanamanPangan`, `TanamanSayur`, `TanamanBuah`.
   Dipilih hierarchical agar C++, Python, dan Java (bonus) tetap identik
   (Java tidak mendukung multiple inheritance antar class).
2. **Composition:** `Ladang` memiliki `Petani` (1), `Tanaman` (0..*), dan `AlatPertanian` (0..*).
   `daftarTanaman`/`daftarAlat` hidup di dalam `Ladang`, bukan di `Main`.
3. **Array of object + polimorfisme:** `daftarTanaman` bertipe pointer ke abstract `Tanaman`.
   Saat `tampilkanSemuaTanaman()` dipanggil, tiap elemen otomatis menjalankan `tampilkanInfo()`
   versi `Pangan/Sayur/Buah`-nya sendiri tanpa `if/else` jenis.
4. **Abstract + concrete campur:** `hitungUmurTanamHari()` ditulis sekali di `Tanaman`
   (parse `YYYY-MM-DD`, selisih ke hari ini); `getKategori()`/`tampilkanInfo()` dibiarkan abstract.

## PENJELASAN ALUR (berlaku untuk C++, Python, Java)

1. `Main` membuat `Ladang("LDG001", "Ladang Sukamaju", 10000, "Sukabumi", Petani("T001", ...))`
   lalu mengisi 6 tanaman + 3 alat statis (2 pangan + 2 sayur + 2 buah).
2. Cetak `Data AWAL Ladang (Sebelum Ditambah)`: `tampilkanInfoLadang()` + `tampilkanSemuaTanaman()` + `tampilkanSemuaAlat()`.
3. Loop menu: `1. Tanam Tanaman Baru | 2. Tambah Alat | 3. Tampilkan Semua Data | 0. Keluar`.
   Tambah tanaman meminta sub-jenis (1=Pangan, 2=Sayur, 3=Buah), validasi ID duplikat,
   tanggal `YYYY-MM-DD`, angka >= 0, dan luas tidak boleh melebihi `hitungSisaLuasLadang()`.
4. Menu 3 mencetak `Data SESUDAH Ditambah` (7 tanaman + 4 alat bila memakai `input.txt`).
5. Menu 0 animasi keluar + banner ASCII.

## STRUKTUR FOLDER

```
TP3DPBO2526C2/
├── cpp/program/
│   ├── Tanaman.cpp  TanamanPangan.cpp  TanamanSayur.cpp  TanamanBuah.cpp
│   ├── Petani.cpp  AlatPertanian.cpp  Ladang.cpp  Main.cpp  input.txt
├── cpp/dokumentasi/output.txt
├── python/program/
│   ├── Tanaman.py  TanamanPangan.py  TanamanSayur.py  TanamanBuah.py
│   ├── Petani.py  AlatPertanian.py  Ladang.py  Main.py  input.txt
├── python/dokumentasi/output.txt
├── java/program/ (bonus, struktur sama .java)
└── java/dokumentasi/output.txt
```

## CARA MENJALANKAN

```bash
# Python
cd python/program
python Main.py
# testcase (PowerShell): Get-Content input.txt | python Main.py

# C++
cd cpp/program
g++ Main.cpp -o Main
./Main
# testcase (PowerShell): Get-Content input.txt | ./Main

# Java (bonus)
cd java/program
javac Petani.java AlatPertanian.java Tanaman.java TanamanPangan.java TanamanSayur.java TanamanBuah.java Ladang.java Main.java
java Main
# testcase (PowerShell): Get-Content input.txt | java Main
```

`input.txt` menanam 1 buah (BUH003 Lengkeng) + 1 alat (ALT004 Pompa Air), lalu tampilkan, lalu keluar.

## DOKUMENTASI

Output terminal lengkap (sebelum + sesudah) tersimpan di:

- `cpp/dokumentasi/output.txt`
- `python/dokumentasi/output.txt`
- `java/dokumentasi/output.txt`

Contoh potongan sesudah ditambah (identik di 3 bahasa):

```
Jumlah tanaman: 7 | Jumlah alat: 4
  7.   [Tanaman Buah] ID: BUH003 | Nama: Lengkeng Matalada | Luas: 700 m2 | Tanam: 2025-06-01 (490 hari) | Jenis: Lengkeng | Tinggi: 3.8 m
  4.   Alat: Pompa Air (ALT004) | Kondisi: Baik | Beli: 2024
```

Ganti file `output.txt` dengan screenshot/screenrecord saat presentasi bila diminta dosen.
