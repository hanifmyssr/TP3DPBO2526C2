#pragma once
#include <string>
#include <iostream>
#include "Tanaman.cpp"
using namespace std;

// Turunan 2 dari Tanaman (Hierarchical Inheritance)
class TanamanSayur : public Tanaman {
private:
    string jenisSayur;    // Misal Bayam, Kangkung
    int masaPanenHari;    // Hari sampai siap panen

public:
    TanamanSayur(string id = "", string n = "", double luas = 0.0, string tgl = "2026-01-01",
                 string jenis = "", int masa = 0)
        : Tanaman(id, n, luas, tgl) {
        jenisSayur = jenis;
        masaPanenHari = masa;
    }

    string getJenisSayur() { return jenisSayur; }
    int getMasaPanenHari() { return masaPanenHari; }

    // Override: kategori spesifik
    string getKategori() override { return "Tanaman Sayur"; }

    // Override: cetak atribut induk + atribut sendiri (polimorfisme)
    void tampilkanInfo() override {
        cout << "  [" << getKategori() << "] ID: " << idTanaman << " | Nama: " << nama
             << " | Luas: " << luasTanamM2 << " m2 | Tanam: " << tanggalTanam
             << " (" << hitungUmurTanamHari() << " hari) | Jenis: " << jenisSayur
             << " | Panen: " << masaPanenHari << " hari" << endl;
    }
};
