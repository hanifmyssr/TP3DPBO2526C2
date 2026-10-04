#pragma once
#include <string>
#include <iostream>
using namespace std;

class AlatPertanian {
private:
    string idAlat;      // ID unik alat
    string namaAlat;    // Misal Cangkul, Traktor, Sprayer
    string kondisi;     // Baik / Rusak / Perlu Perawatan
    int tahunBeli;      // Tahun alat dibeli

public:
    AlatPertanian(string id = "", string n = "", string k = "Baik", int thn = 2023) {
        idAlat = id;
        namaAlat = n;
        kondisi = k;
        tahunBeli = thn;
    }

    // Getter
    string getIdAlat() { return idAlat; }
    string getNamaAlat() { return namaAlat; }
    string getKondisi() { return kondisi; }
    int getTahunBeli() { return tahunBeli; }

    // Update status kondisi alat
    void setKondisi(string baru) { kondisi = baru; }

    // Cetak detail alat
    void tampilkanInfoAlat() {
        cout << "  Alat: " << namaAlat << " (" << idAlat << ") | Kondisi: " << kondisi
             << " | Beli: " << tahunBeli << endl;
    }
};
