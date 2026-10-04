#pragma once
#include <string>
#include <iostream>
#include "Tanaman.cpp"
using namespace std;

// Turunan 3 dari Tanaman (Hierarchical Inheritance)
class TanamanBuah : public Tanaman {
private:
    string jenisBuah;     // Misal Mangga, Jeruk
    double tinggiPohonM;  // Tinggi pohon (meter)

public:
    TanamanBuah(string id = "", string n = "", double luas = 0.0, string tgl = "2026-01-01",
                string jenis = "", double tinggi = 0.0)
        : Tanaman(id, n, luas, tgl) {
        jenisBuah = jenis;
        tinggiPohonM = tinggi;
    }

    string getJenisBuah() { return jenisBuah; }
    double getTinggiPohonM() { return tinggiPohonM; }

    // Override: kategori spesifik
    string getKategori() override { return "Tanaman Buah"; }

    // Override: cetak atribut induk + atribut sendiri (polimorfisme)
    void tampilkanInfo() override {
        cout << "  [" << getKategori() << "] ID: " << idTanaman << " | Nama: " << nama
             << " | Luas: " << luasTanamM2 << " m2 | Tanam: " << tanggalTanam
             << " (" << hitungUmurTanamHari() << " hari) | Jenis: " << jenisBuah
             << " | Tinggi: " << tinggiPohonM << " m" << endl;
    }
};
