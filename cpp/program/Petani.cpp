#pragma once
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class Petani {
private:
    string idPetani;            // ID unik petani
    string nama;                // Nama petani
    string alamat;              // Alamat tinggal
    int tahunMulaiBertani;      // Tahun mulai bertani

public:
    Petani(string id = "", string n = "", string al = "", int thn = 2020) {
        idPetani = id;
        nama = n;
        alamat = al;
        tahunMulaiBertani = thn;
    }

    // Getter
    string getIdPetani() { return idPetani; }
    string getNama() { return nama; }
    string getAlamat() { return alamat; }
    int getTahunMulaiBertani() { return tahunMulaiBertani; }

    // Setter untuk setiap atribut
    void setIdPetani(string id) { idPetani = id; }
    void setNama(string n) { nama = n; }
    void setAlamat(string al) { alamat = al; }
    void setTahunMulaiBertani(int thn) { tahunMulaiBertani = thn; }

    // Hitung tahun sekarang - tahunMulaiBertani
    int getPengalamanTahun() {
        time_t now = time(nullptr);
        struct tm* lt = localtime(&now);
        return (lt->tm_year + 1900) - tahunMulaiBertani;
    }

    // Cetak semua info petani
    void tampilkanInfoPetani() {
        cout << "  Petani: " << nama << " (" << idPetani << ") | Alamat: " << alamat
             << " | Pengalaman: " << getPengalamanTahun() << " tahun" << endl;
    }
};
