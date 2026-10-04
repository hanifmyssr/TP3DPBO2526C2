class AlatPertanian:

    def __init__(self, id_alat="", nama_alat="", kondisi="Baik", tahun_beli=2023):
        self._id_alat = id_alat        # ID unik alat
        self._nama_alat = nama_alat    # Misal Cangkul, Traktor, Sprayer
        self._kondisi = kondisi        # Baik / Rusak / Perlu Perawatan
        self._tahun_beli = tahun_beli  # Tahun alat dibeli

    # Getter
    def get_id_alat(self):
        return self._id_alat

    def get_nama_alat(self):
        return self._nama_alat

    def get_kondisi(self):
        return self._kondisi

    def get_tahun_beli(self):
        return self._tahun_beli

    # Update status kondisi alat
    def set_kondisi(self, baru):
        self._kondisi = baru

    # Cetak detail alat
    def tampilkan_info_alat(self):
        print(f"  Alat: {self._nama_alat} ({self._id_alat}) | Kondisi: {self._kondisi} | Beli: {self._tahun_beli}")
