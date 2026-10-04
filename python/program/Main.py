from datetime import datetime
from Petani import Petani
from AlatPertanian import AlatPertanian
from TanamanPangan import TanamanPangan
from TanamanSayur import TanamanSayur
from TanamanBuah import TanamanBuah
from Ladang import Ladang
import time
import sys

# Ladang utama (orkestrator: pegang Petani + 2 array of object)
ladang = Ladang("LDG001", "Ladang Sukamaju", 10000, "Sukabumi",
                Petani("T001", "Pak Ahmad", "Jl. Sawah No.1", 2015))


# Validasi input tidak boleh kosong
def input_not_empty(prompt):
    while True:
        val = input(prompt).strip()
        if not val:
            print("Input tidak boleh kosong!")
            continue
        return val


# Validasi angka float >= 0
def input_float(prompt):
    while True:
        try:
            v = float(input(prompt).strip())
        except ValueError:
            print("Input harus berupa angka!")
            continue
        if v < 0:
            print("Input tidak boleh negatif!")
            continue
        return v


# Validasi angka int >= 0
def input_int(prompt):
    while True:
        try:
            v = int(input(prompt).strip())
        except ValueError:
            print("Input harus berupa angka bulat!")
            continue
        if v < 0:
            print("Input tidak boleh negatif!")
            continue
        return v


# Validasi tanggal format YYYY-MM-DD
def input_tanggal(prompt):
    while True:
        val = input(prompt).strip()
        try:
            datetime.strptime(val, "%Y-%m-%d")
            return val
        except ValueError:
            print("Format tanggal harus YYYY-MM-DD! (contoh: 2026-06-10)")


# Validasi luas: tidak boleh melebihi sisa ladang
def input_luas_tanam():
    while True:
        luas = input_float("Luas Tanam (m2)   : ")
        sisa = ladang.hitung_sisa_luas_ladang()
        if luas > sisa:
            print(f"Luas melebihi sisa ladang ({sisa:g} m2)! Kurangi luasnya.")
            continue
        return luas


def input_id_tanaman():
    while True:
        id_tanaman = input("ID Tanaman        : ").strip()
        if not id_tanaman:
            print("ID tidak boleh kosong!")
            continue
        if ladang.id_tanaman_dipakai(id_tanaman):
            print("ID sudah dipakai!")
            continue
        return id_tanaman


def tambah_tanaman():
    print("\n--- Tambah Tanaman ---")
    print("Jenis: 1=Pangan  2=Sayur  3=Buah")
    while True:
        try:
            jenis = int(input("Pilih jenis (1/2/3): ").strip())
            if jenis not in (1, 2, 3):
                print("Pilih 1, 2, atau 3!")
                continue
            break
        except ValueError:
            print("Input harus berupa angka!")

    id_tanaman = input_id_tanaman()
    nama = input_not_empty("Nama              : ")
    luas = input_luas_tanam()
    tanggal = input_tanggal("Tanggal Tanam (YYYY-MM-DD): ")

    if jenis == 1:
        jenis_pangan = input_not_empty("Jenis Pangan      : ")
        air = input_float("Butuh Air (L/hari): ")
        ladang.tanam_tanaman_baru(TanamanPangan(id_tanaman, nama, luas, tanggal, jenis_pangan, air))
    elif jenis == 2:
        jenis_sayur = input_not_empty("Jenis Sayur       : ")
        masa = input_int("Masa Panen (hari) : ")
        ladang.tanam_tanaman_baru(TanamanSayur(id_tanaman, nama, luas, tanggal, jenis_sayur, masa))
    else:
        jenis_buah = input_not_empty("Jenis Buah        : ")
        tinggi = input_float("Tinggi Pohon (m)  : ")
        ladang.tanam_tanaman_baru(TanamanBuah(id_tanaman, nama, luas, tanggal, jenis_buah, tinggi))
    print("Tanaman berhasil ditanam!")


def tambah_alat():
    print("\n--- Tambah Alat Pertanian ---")
    while True:
        id_alat = input("ID Alat           : ").strip()
        if not id_alat:
            print("ID tidak boleh kosong!")
            continue
        if ladang.id_alat_dipakai(id_alat):
            print("ID sudah dipakai!")
            continue
        break
    nama = input_not_empty("Nama Alat         : ")
    kondisi = input_not_empty("Kondisi           : ")
    tahun = input_int("Tahun Beli        : ")
    ladang.tambah_alat(AlatPertanian(id_alat, nama, kondisi, tahun))
    print("Alat berhasil ditambahkan!")


def tampilkan_data(judul):
    print(f"\n>>> {judul} <<<")
    ladang.tampilkan_info_ladang()
    print("\n-- Daftar Tanaman (polimorfisme) --")
    ladang.tampilkan_semua_tanaman()
    print("\n-- Daftar Alat --")
    ladang.tampilkan_semua_alat()


def tampilkan_menu():
    print("\n===============================")
    print("  MANAJEMEN LADANG SUKAMAJU")
    print("===============================")
    print("1. Tanam Tanaman Baru")
    print("2. Tambah Alat")
    print("3. Tampilkan Semua Data")
    print("0. Keluar")
    print("Pilih menu: ", end="")


def animasi_keluar():
    print("\nMenutup program", end="")
    for _ in range(3):
        time.sleep(0.4)
        print(".", end="")
        sys.stdout.flush()
    print("\n")
    banner = [
        "#####  ####   ###      ####   ###  #   # #####",
        "  #    #   # #   #     #   # #   # ##  # #    ",
        "  #    ####     #      #   # #   # # # # #### ",
        "  #    #       #       #   # #   # #  ## #    ",
        "  #    #      ####     ####   ###  #   # #####",
    ]
    for baris in banner:
        time.sleep(0.15)
        print(baris)
    print()


def main():
    # Data awal SEBELUM ditambah: 6 tanaman (2 pangan + 2 sayur + 2 buah) + 3 alat
    ladang.tanam_tanaman_baru(TanamanPangan("PGN001", "Padi IR64", 2000, "2026-06-10", "Padi", 5000))
    ladang.tanam_tanaman_baru(TanamanPangan("PGN002", "Jagung Bisi-18", 1500, "2026-07-01", "Jagung", 3500))
    ladang.tanam_tanaman_baru(TanamanSayur("SYR001", "Bayam Hijau", 500, "2026-09-10", "Bayam", 25))
    ladang.tanam_tanaman_baru(TanamanSayur("SYR002", "Kangkung Cabut", 400, "2026-09-15", "Kangkung", 20))
    ladang.tanam_tanaman_baru(TanamanBuah("BUH001", "Mangga Harum Manis", 800, "2024-03-01", "Mangga", 4.5))
    ladang.tanam_tanaman_baru(TanamanBuah("BUH002", "Jeruk Siam", 600, "2025-01-15", "Jeruk", 3.2))

    ladang.tambah_alat(AlatPertanian("ALT001", "Cangkul", "Baik", 2022))
    ladang.tambah_alat(AlatPertanian("ALT002", "Traktor Mini", "Perlu Perawatan", 2020))
    ladang.tambah_alat(AlatPertanian("ALT003", "Sprayer", "Baik", 2023))

    tampilkan_data("Data AWAL Ladang (Sebelum Ditambah)")

    while True:
        tampilkan_menu()
        try:
            pilihan = int(input())
        except ValueError:
            print("Input harus berupa angka!")
            continue

        if pilihan == 1:
            tambah_tanaman()
        elif pilihan == 2:
            tambah_alat()
        elif pilihan == 3:
            tampilkan_data("Data SESUDAH Ditambah")
        elif pilihan == 0:
            animasi_keluar()
            break
        else:
            print("Pilihan tidak valid!")


if __name__ == "__main__":
    main()
