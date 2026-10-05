#pragma once
#include <string>
#include <iostream>
#include <sstream>
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

    // Setter untuk setiap atribut sendiri (+ setter warisan dari Tanaman)
    void setJenisBuah(string jenis) { jenisBuah = jenis; }
    void setTinggiPohonM(double tinggi) { tinggiPohonM = tinggi; }

    // Override: kategori spesifik
    string getKategori() override { return "Tanaman Buah"; }

    // Override: kolom tabel
    string getJenis() override { return jenisBuah; }
    string getInfoTambahan() override {
        ostringstream oss; oss << tinggiPohonM;
        return "Tinggi: " + oss.str() + " m";
    }

    // Override: cetak atribut induk + atribut sendiri (polimorfisme)
    void tampilkanInfo() override {
        cout << "  [" << getKategori() << "] ID: " << idTanaman << " | Nama: " << nama
             << " | Luas: " << luasTanamM2 << " m2 | Tanam: " << tanggalTanam
             << " (" << hitungUmurTanamHari() << " hari) | Jenis: " << jenisBuah
             << " | Tinggi: " << tinggiPohonM << " m" << endl;
    }
};
