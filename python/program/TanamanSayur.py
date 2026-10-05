from Tanaman import Tanaman


# Turunan 2 dari Tanaman (Hierarchical Inheritance)
class TanamanSayur(Tanaman):

    def __init__(self, id_tanaman="", nama="", luas_tanam_m2=0.0, tanggal_tanam="2026-01-01",
                 jenis_sayur="", masa_panen_hari=0):
        super().__init__(id_tanaman, nama, luas_tanam_m2, tanggal_tanam)
        self._jenis_sayur = jenis_sayur        # Misal Bayam, Kangkung
        self._masa_panen_hari = masa_panen_hari  # Hari sampai siap panen

    def get_jenis_sayur(self):
        return self._jenis_sayur

    def get_masa_panen_hari(self):
        return self._masa_panen_hari

    # Setter untuk setiap atribut sendiri (+ setter warisan dari Tanaman)
    def set_jenis_sayur(self, jenis_sayur):
        self._jenis_sayur = jenis_sayur

    def set_masa_panen_hari(self, masa_panen_hari):
        self._masa_panen_hari = masa_panen_hari

    # Override: kategori spesifik
    def get_kategori(self):
        return "Tanaman Sayur"

    # Override: kolom tabel
    def get_jenis(self):
        return self._jenis_sayur

    def get_info_tambahan(self):
        return f"Panen: {self._masa_panen_hari} hari"

    # Override: cetak atribut induk + atribut sendiri (polimorfisme)
    def tampilkan_info(self):
        print(f"  [{self.get_kategori()}] ID: {self._id_tanaman} | Nama: {self._nama} | "
              f"Luas: {self._luas_tanam_m2:g} m2 | Tanam: {self._tanggal_tanam} "
              f"({self.hitung_umur_tanam_hari()} hari) | Jenis: {self._jenis_sayur} | "
              f"Panen: {self._masa_panen_hari} hari")
