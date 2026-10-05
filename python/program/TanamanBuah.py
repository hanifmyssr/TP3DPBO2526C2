from Tanaman import Tanaman


# Turunan 3 dari Tanaman (Hierarchical Inheritance)
class TanamanBuah(Tanaman):

    def __init__(self, id_tanaman="", nama="", luas_tanam_m2=0.0, tanggal_tanam="2026-01-01",
                 jenis_buah="", tinggi_pohon_m=0.0):
        super().__init__(id_tanaman, nama, luas_tanam_m2, tanggal_tanam)
        self._jenis_buah = jenis_buah        # Misal Mangga, Jeruk
        self._tinggi_pohon_m = tinggi_pohon_m  # Tinggi pohon (meter)

    def get_jenis_buah(self):
        return self._jenis_buah

    def get_tinggi_pohon_m(self):
        return self._tinggi_pohon_m

    # Setter untuk setiap atribut sendiri (+ setter warisan dari Tanaman)
    def set_jenis_buah(self, jenis_buah):
        self._jenis_buah = jenis_buah

    def set_tinggi_pohon_m(self, tinggi_pohon_m):
        self._tinggi_pohon_m = tinggi_pohon_m

    # Override: kategori spesifik
    def get_kategori(self):
        return "Tanaman Buah"

    # Override: kolom tabel
    def get_jenis(self):
        return self._jenis_buah

    def get_info_tambahan(self):
        return f"Tinggi: {self._tinggi_pohon_m:g} m"

    # Override: cetak atribut induk + atribut sendiri (polimorfisme)
    def tampilkan_info(self):
        print(f"  [{self.get_kategori()}] ID: {self._id_tanaman} | Nama: {self._nama} | "
              f"Luas: {self._luas_tanam_m2:g} m2 | Tanam: {self._tanggal_tanam} "
              f"({self.hitung_umur_tanam_hari()} hari) | Jenis: {self._jenis_buah} | "
              f"Tinggi: {self._tinggi_pohon_m:g} m")
