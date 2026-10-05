#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "Tanaman.cpp"
using namespace std;

// Turunan 1 dari Tanaman (Hierarchical Inheritance)
class TanamanPangan : public Tanaman {
private:
    string jenisPangan;                 // Misal Padi, Jagung
    double kebutuhanAirLiterPerHari;    // Liter/hari

public:
    TanamanPangan(string id = "", string n = "", double luas = 0.0, string tgl = "2026-01-01",
                  string jenis = "", double air = 0.0)
        : Tanaman(id, n, luas, tgl) {
        jenisPangan = jenis;
        kebutuhanAirLiterPerHari = air;
    }

    string getJenisPangan() { return jenisPangan; }
    double getKebutuhanAirLiterPerHari() { return kebutuhanAirLiterPerHari; }

    // Setter untuk setiap atribut sendiri (+ setter warisan dari Tanaman)
    void setJenisPangan(string jenis) { jenisPangan = jenis; }
    void setKebutuhanAirLiterPerHari(double air) { kebutuhanAirLiterPerHari = air; }

    // Override: kategori spesifik
    string getKategori() override { return "Tanaman Pangan"; }

    // Override: kolom tabel
    string getJenis() override { return jenisPangan; }
    string getInfoTambahan() override {
        ostringstream oss; oss << kebutuhanAirLiterPerHari;
        return "Air: " + oss.str() + " L/hari";
    }

    // Override: cetak atribut induk + atribut sendiri (polimorfisme)
    void tampilkanInfo() override {
        cout << "  [" << getKategori() << "] ID: " << idTanaman << " | Nama: " << nama
             << " | Luas: " << luasTanamM2 << " m2 | Tanam: " << tanggalTanam
             << " (" << hitungUmurTanamHari() << " hari) | Jenis: " << jenisPangan
             << " | Air: " << kebutuhanAirLiterPerHari << " L/hari" << endl;
    }
};
