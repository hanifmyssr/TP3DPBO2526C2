from Tanaman import Tanaman


# Turunan 1 dari Tanaman (Hierarchical Inheritance)
class TanamanPangan(Tanaman):

    def __init__(self, id_tanaman="", nama="", luas_tanam_m2=0.0, tanggal_tanam="2026-01-01",
                 jenis_pangan="", kebutuhan_air_liter_per_hari=0.0):
        super().__init__(id_tanaman, nama, luas_tanam_m2, tanggal_tanam)
        self._jenis_pangan = jenis_pangan                              # Misal Padi, Jagung
        self._kebutuhan_air_liter_per_hari = kebutuhan_air_liter_per_hari  # Liter/hari

    def get_jenis_pangan(self):
        return self._jenis_pangan

    def get_kebutuhan_air_liter_per_hari(self):
        return self._kebutuhan_air_liter_per_hari

    # Setter untuk setiap atribut sendiri (+ setter warisan dari Tanaman)
    def set_jenis_pangan(self, jenis_pangan):
        self._jenis_pangan = jenis_pangan

    def set_kebutuhan_air_liter_per_hari(self, kebutuhan_air_liter_per_hari):
        self._kebutuhan_air_liter_per_hari = kebutuhan_air_liter_per_hari

    # Override: kategori spesifik
    def get_kategori(self):
        return "Tanaman Pangan"

    # Override: kolom tabel
    def get_jenis(self):
        return self._jenis_pangan

    def get_info_tambahan(self):
        return f"Air: {self._kebutuhan_air_liter_per_hari:g} L/hari"

    # Override: cetak atribut induk + atribut sendiri (polimorfisme)
    def tampilkan_info(self):
        print(f"  [{self.get_kategori()}] ID: {self._id_tanaman} | Nama: {self._nama} | "
              f"Luas: {self._luas_tanam_m2:g} m2 | Tanam: {self._tanggal_tanam} "
              f"({self.hitung_umur_tanam_hari()} hari) | Jenis: {self._jenis_pangan} | "
              f"Air: {self._kebutuhan_air_liter_per_hari:g} L/hari")
