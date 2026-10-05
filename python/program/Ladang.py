# Kelas utama/orkestrator: Ladang
# Composition: Ladang ◆— Petani (1), Ladang ◆— Tanaman (0..*), Ladang ◆— AlatPertanian (0..*)
class Ladang:

    def __init__(self, id_ladang="", nama_ladang="", luas_total_m2=0.0, lokasi="", pemilik=None):
        self._id_ladang = id_ladang          # ID unik ladang
        self._nama_ladang = nama_ladang      # Nama ladang/kebun
        self._luas_total_m2 = luas_total_m2  # Luas total lahan (m2)
        self._lokasi = lokasi                # Lokasi ladang
        self._pemilik = pemilik              # Composition (1): satu ladang satu petani
        self._daftar_tanaman = []             # Composition + array of object (0..*): Tanaman*
        self._daftar_alat = []               # Composition + array of object (0..*): AlatPertanian*

    # Getter
    def get_id_ladang(self):
        return self._id_ladang

    def get_nama_ladang(self):
        return self._nama_ladang

    def get_luas_total_m2(self):
        return self._luas_total_m2

    def get_lokasi(self):
        return self._lokasi

    def get_pemilik(self):
        return self._pemilik

    def get_daftar_tanaman(self):
        return self._daftar_tanaman

    def get_daftar_alat(self):
        return self._daftar_alat

    # Setter untuk setiap atribut
    def set_id_ladang(self, id_ladang):
        self._id_ladang = id_ladang

    def set_nama_ladang(self, nama_ladang):
        self._nama_ladang = nama_ladang

    def set_luas_total_m2(self, luas_total_m2):
        self._luas_total_m2 = luas_total_m2

    def set_lokasi(self, lokasi):
        self._lokasi = lokasi

    def set_pemilik(self, pemilik):
        self._pemilik = pemilik

    def set_daftar_tanaman(self, daftar_tanaman):
        self._daftar_tanaman = daftar_tanaman

    def set_daftar_alat(self, daftar_alat):
        self._daftar_alat = daftar_alat

    # Cek duplikat ID tanaman / alat
    def id_tanaman_dipakai(self, id_tanaman):
        for t in self._daftar_tanaman:
            if t.get_id_tanaman() == id_tanaman:
                return True
        return False

    def id_alat_dipakai(self, id_alat):
        for a in self._daftar_alat:
            if a.get_id_alat() == id_alat:
                return True
        return False

    # Tambahkan tanaman / alat
    def tanam_tanaman_baru(self, tanaman):
        self._daftar_tanaman.append(tanaman)

    def tambah_alat(self, alat):
        self._daftar_alat.append(alat)

    @staticmethod
    def _fmt(x):
        return f"{x:g}" if isinstance(x, float) else str(x)

    @staticmethod
    def _header_box():
        w = 66
        print("+" + "=" * w + "+")
        print("|" + "MANAJEMEN LADANG SUKAMAJU".center(w) + "|")
        print("|" + "Sistem Manajemen Ladang & Tanaman".center(w) + "|")
        print("+" + "=" * w + "+")

    # Gaya screenshot: daftar hierarki bernomor + tree (polimorfisme:
    # get_kategori/get_jenis/get_info_tambahan otomatis versi override tiap jenis)
    def tampilkan_semua_tanaman(self):
        print("[ DAFTAR TANAMAN ]")
        if not self._daftar_tanaman:
            print("  Belum ada tanaman.")
            return
        for i, t in enumerate(self._daftar_tanaman, 1):
            print(f"  {i}. [{t.get_kategori()}] {t.get_nama()} ({t.get_id_tanaman()})")
            umur = f"{t.hitung_umur_tanam_hari()} hr"
            print(f"     Detail : Luas {self._fmt(t.get_luas_tanam_m2())} m2 | "
                  f"Tanam {t.get_tanggal_tanam()} ({umur}) | "
                  f"Jenis {t.get_jenis()} | {t.get_info_tambahan()}")

    # Gaya screenshot: daftar hierarki bernomor + tree
    def tampilkan_semua_alat(self):
        print("[ DAFTAR ALAT ]")
        if not self._daftar_alat:
            print("  Belum ada alat.")
            return
        for i, a in enumerate(self._daftar_alat, 1):
            print(f"  {i}. {a.get_nama_alat()} ({a.get_id_alat()})")
            print(f"     Detail : Kondisi {a.get_kondisi()} | Beli {a.get_tahun_beli()}")

    # Jumlahkan luasTanamM2 seluruh tanaman
    def hitung_total_luas_tertanam(self):
        return sum(t.get_luas_tanam_m2() for t in self._daftar_tanaman)

    # luasTotal - totalTertanam
    def hitung_sisa_luas_ladang(self):
        return self._luas_total_m2 - self.hitung_total_luas_tertanam()

    # Gaya screenshot: header box + bullet info (seperti [ INFORMASI BIMBEL ])
    def tampilkan_info_ladang(self):
        self._header_box()
        print()
        print("[ INFORMASI LADANG ]")
        print(f"  - ID Ladang   : {self._id_ladang}")
        print(f"  - Nama Ladang : {self._nama_ladang}")
        print(f"  - Lokasi      : {self._lokasi}")
        print(f"  - Luas Total  : {self._fmt(self._luas_total_m2)} m2")
        print(f"  - Tertanam    : {self._fmt(self.hitung_total_luas_tertanam())} m2")
        print(f"  - Sisa        : {self._fmt(self.hitung_sisa_luas_ladang())} m2")
        print(f"  - Isi         : {len(self._daftar_tanaman)} tanaman | {len(self._daftar_alat)} alat")
        print()
        if self._pemilik is not None:
            p = self._pemilik
            print("[ INFORMASI PETANI ]")
            print(f"  - ID Petani   : {p.get_id_petani()}")
            print(f"  - Nama        : {p.get_nama()}")
            print(f"  - Alamat      : {p.get_alamat()}")
            print(f"  - Mulai       : {p.get_tahun_mulai_bertani()} ({p.get_pengalaman_tahun()} thn pengalaman)")
