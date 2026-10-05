from datetime import date


class Petani:

    def __init__(self, id_petani="", nama="", alamat="", tahun_mulai_bertani=2020):
        self._id_petani = id_petani                    # ID unik petani
        self._nama = nama                              # Nama petani
        self._alamat = alamat                          # Alamat tinggal
        self._tahun_mulai_bertani = tahun_mulai_bertani  # Tahun mulai bertani

    # Getter
    def get_id_petani(self):
        return self._id_petani

    def get_nama(self):
        return self._nama

    def get_alamat(self):
        return self._alamat

    def get_tahun_mulai_bertani(self):
        return self._tahun_mulai_bertani

    # Setter untuk setiap atribut
    def set_id_petani(self, id_petani):
        self._id_petani = id_petani

    def set_nama(self, nama):
        self._nama = nama

    def set_alamat(self, alamat):
        self._alamat = alamat

    def set_tahun_mulai_bertani(self, tahun_mulai_bertani):
        self._tahun_mulai_bertani = tahun_mulai_bertani

    # Hitung tahun sekarang - tahunMulaiBertani
    def get_pengalaman_tahun(self):
        return date.today().year - self._tahun_mulai_bertani

    # Cetak semua info petani
    def tampilkan_info_petani(self):
        print(f"  Petani: {self._nama} ({self._id_petani}) | Alamat: {self._alamat} | "
              f"Pengalaman: {self.get_pengalaman_tahun()} tahun")
