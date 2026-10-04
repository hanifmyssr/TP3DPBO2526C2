#pragma once
#include <string>
#include <iostream>
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

    // Override: kategori spesifik
    string getKategori() override { return "Tanaman Pangan"; }

    // Override: cetak atribut induk + atribut sendiri (polimorfisme)
    void tampilkanInfo() override {
        cout << "  [" << getKategori() << "] ID: " << idTanaman << " | Nama: " << nama
             << " | Luas: " << luasTanamM2 << " m2 | Tanam: " << tanggalTanam
             << " (" << hitungUmurTanamHari() << " hari) | Jenis: " << jenisPangan
             << " | Air: " << kebutuhanAirLiterPerHari << " L/hari" << endl;
    }
};
