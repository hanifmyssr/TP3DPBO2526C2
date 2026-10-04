from abc import ABC, abstractmethod
from datetime import date, datetime


# Kelas abstrak induk semua tanaman (Hierarchical Inheritance root)
# Punya campuran method concrete + abstract
class Tanaman(ABC):

    def __init__(self, id_tanaman="", nama="", luas_tanam_m2=0.0, tanggal_tanam="2026-01-01"):
        self._id_tanaman = id_tanaman        # ID unik tanaman
        self._nama = nama                    # Nama tanaman
        self._luas_tanam_m2 = luas_tanam_m2  # Luas yang dipakai tanaman ini (m2)
        self._tanggal_tanam = tanggal_tanam  # Tanggal mulai ditanam (YYYY-MM-DD)

    # Getter standar
    def get_id_tanaman(self):
        return self._id_tanaman

    def get_nama(self):
        return self._nama

    def get_luas_tanam_m2(self):
        return self._luas_tanam_m2

    def get_tanggal_tanam(self):
        return self._tanggal_tanam

    # Concrete (bukan abstract): hitung selisih hari dari tanggalTanam sampai sekarang
    # Dipakai sama persis oleh semua turunan
    def hitung_umur_tanam_hari(self):
        try:
            tgl = datetime.strptime(self._tanggal_tanam, "%Y-%m-%d").date()
            return (date.today() - tgl).days
        except ValueError:
            return 0

    # Abstract: perilaku beda per turunan
    @abstractmethod
    def get_kategori(self):
        pass

    # Abstract: cetak atribut Tanaman + atribut spesifik turunan
    @abstractmethod
    def tampilkan_info(self):
        pass
