#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Petani.cpp"
#include "AlatPertanian.cpp"
#include "TanamanPangan.cpp"
#include "TanamanSayur.cpp"
#include "TanamanBuah.cpp"
using namespace std;

// Kelas utama/orkestrator: Ladang
// Composition: Ladang ◆— Petani (1), Ladang ◆— Tanaman (0..*), Ladang ◆— AlatPertanian (0..*)
class Ladang {
private:
    string idLadang;                    // ID unik ladang
    string namaLadang;                  // Nama ladang/kebun
    double luasTotalM2;                 // Luas total lahan (m2)
    string lokasi;                      // Lokasi ladang
    Petani pemilik;                     // Composition (1): satu ladang satu petani
    vector<Tanaman*> daftarTanaman;      // Composition + array of object (0..*)
    vector<AlatPertanian*> daftarAlat;  // Composition + array of object (0..*)

public:
    Ladang(string id = "", string n = "", double luas = 0.0, string lok = "", Petani p = Petani()) {
        idLadang = id;
        namaLadang = n;
        luasTotalM2 = luas;
        lokasi = lok;
        pemilik = p;
    }

    ~Ladang() {
        for (auto t : daftarTanaman) delete t;
        for (auto a : daftarAlat) delete a;
    }

    // Getter
    string getIdLadang() { return idLadang; }
    string getNamaLadang() { return namaLadang; }
    double getLuasTotalM2() { return luasTotalM2; }
    string getLokasi() { return lokasi; }
    Petani getPemilik() { return pemilik; }
    vector<Tanaman*>& getDaftarTanaman() { return daftarTanaman; }
    vector<AlatPertanian*>& getDaftarAlat() { return daftarAlat; }

    // Cek duplikat ID
    bool idTanamanDipakai(string id) {
        for (auto t : daftarTanaman) if (t->getIdTanaman() == id) return true;
        return false;
    }
    bool idAlatDipakai(string id) {
        for (auto a : daftarAlat) if (a->getIdAlat() == id) return true;
        return false;
    }

    // Tambahkan tanaman / alat
    void tanamTanamanBaru(Tanaman* tanaman) { daftarTanaman.push_back(tanaman); }
    void tambahAlat(AlatPertanian* alat) { daftarAlat.push_back(alat); }

    // Loop daftarTanaman, panggil tampilkanInfo() tiap elemen
    // (polimorfisme: otomatis versi override masing-masing jenis)
    void tampilkanSemuaTanaman() {
        if (daftarTanaman.empty()) {
            cout << "  Belum ada tanaman." << endl;
            return;
        }
        for (size_t i = 0; i < daftarTanaman.size(); i++) {
            cout << "  " << (i + 1) << ". ";
            daftarTanaman[i]->tampilkanInfo();
        }
    }

    // Loop daftarAlat
    void tampilkanSemuaAlat() {
        if (daftarAlat.empty()) {
            cout << "  Belum ada alat." << endl;
            return;
        }
        for (size_t i = 0; i < daftarAlat.size(); i++) {
            cout << "  " << (i + 1) << ". ";
            daftarAlat[i]->tampilkanInfoAlat();
        }
    }

    // Jumlahkan luasTanamM2 seluruh tanaman
    double hitungTotalLuasTertanam() {
        double total = 0;
        for (auto t : daftarTanaman) total += t->getLuasTanamM2();
        return total;
    }

    // luasTotal - totalTertanam
    double hitungSisaLuasLadang() { return luasTotalM2 - hitungTotalLuasTertanam(); }

    // Cetak ladang + pemilik (delegasi ke pemilik.tampilkanInfoPetani)
    void tampilkanInfoLadang() {
        cout << "Ladang " << namaLadang << " (" << idLadang << ") | Lokasi: " << lokasi << endl;
        cout << "Luas total: " << luasTotalM2 << " m2 | Tertanam: " << hitungTotalLuasTertanam()
             << " m2 | Sisa: " << hitungSisaLuasLadang() << " m2" << endl;
        pemilik.tampilkanInfoPetani();
        cout << "Jumlah tanaman: " << daftarTanaman.size() << " | Jumlah alat: " << daftarAlat.size() << endl;
    }
};
