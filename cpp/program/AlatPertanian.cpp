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

    // Setter untuk setiap atribut
    void setIdAlat(string id) { idAlat = id; }
    void setNamaAlat(string n) { namaAlat = n; }
    void setKondisi(string baru) { kondisi = baru; }
    void setTahunBeli(int thn) { tahunBeli = thn; }

    // Cetak detail alat
    void tampilkanInfoAlat() {
        cout << "  Alat: " << namaAlat << " (" << idAlat << ") | Kondisi: " << kondisi
             << " | Beli: " << tahunBeli << endl;
    }
};
