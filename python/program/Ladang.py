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

    # Loop daftarTanaman, panggil tampilkanInfo() tiap elemen
    # (polimorfisme: otomatis versi override masing-masing jenis)
    def tampilkan_semua_tanaman(self):
        if not self._daftar_tanaman:
            print("  Belum ada tanaman.")
            return
        for i, t in enumerate(self._daftar_tanaman, 1):
            print(f"  {i}. ", end="")
            t.tampilkan_info()

    # Loop daftarAlat
    def tampilkan_semua_alat(self):
        if not self._daftar_alat:
            print("  Belum ada alat.")
            return
        for i, a in enumerate(self._daftar_alat, 1):
            print(f"  {i}. ", end="")
            a.tampilkan_info_alat()

    # Jumlahkan luasTanamM2 seluruh tanaman
    def hitung_total_luas_tertanam(self):
        return sum(t.get_luas_tanam_m2() for t in self._daftar_tanaman)

    # luasTotal - totalTertanam
    def hitung_sisa_luas_ladang(self):
        return self._luas_total_m2 - self.hitung_total_luas_tertanam()

    # Cetak ladang + pemilik (delegasi ke pemilik.tampilkan_info_petani)
    def tampilkan_info_ladang(self):
        print(f"Ladang {self._nama_ladang} ({self._id_ladang}) | Lokasi: {self._lokasi}")
        print(f"Luas total: {self._luas_total_m2:g} m2 | Tertanam: {self.hitung_total_luas_tertanam():g} m2 | "
              f"Sisa: {self.hitung_sisa_luas_ladang():g} m2")
        if self._pemilik is not None:
            self._pemilik.tampilkan_info_petani()
        print(f"Jumlah tanaman: {len(self._daftar_tanaman)} | Jumlah alat: {len(self._daftar_alat)}")
