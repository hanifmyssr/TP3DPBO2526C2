#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
using namespace std;

// Kelas abstrak induk semua tanaman (Hierarchical Inheritance root)
// Punya campuran method concrete + abstract
class Tanaman {
protected:
    string idTanaman;      // ID unik tanaman
    string nama;           // Nama tanaman
    double luasTanamM2;    // Luas yang dipakai tanaman ini (m2)
    string tanggalTanam;   // Tanggal mulai ditanam (YYYY-MM-DD)

public:
    Tanaman(string id = "", string n = "", double luas = 0.0, string tgl = "2026-01-01") {
        idTanaman = id;
        nama = n;
        luasTanamM2 = luas;
        tanggalTanam = tgl;
    }

    virtual ~Tanaman() {}

    // Getter standar
    string getIdTanaman() { return idTanaman; }
    string getNama() { return nama; }
    double getLuasTanamM2() { return luasTanamM2; }
    string getTanggalTanam() { return tanggalTanam; }

    // Setter untuk setiap atribut
    void setIdTanaman(string id) { idTanaman = id; }
    void setNama(string n) { nama = n; }
    void setLuasTanamM2(double luas) { luasTanamM2 = luas; }
    void setTanggalTanam(string tgl) { tanggalTanam = tgl; }

    // Concrete (bukan abstract): hitung selisih hari dari tanggalTanam sampai sekarang
    // Dipakai sama persis oleh semua turunan
    int hitungUmurTanamHari() {
        int y, m, d;
        if (sscanf(tanggalTanam.c_str(), "%d-%d-%d", &y, &m, &d) != 3) return 0;
        struct tm tanam = {};
        tanam.tm_year = y - 1900;
        tanam.tm_mon = m - 1;
        tanam.tm_mday = d;
        tanam.tm_hour = 12;
        time_t tTanam = mktime(&tanam);
        if (tTanam == (time_t)-1) return 0;
        time_t now = time(nullptr);
        double diff = difftime(now, tTanam) / 86400.0;
        if (diff < 0) return 0;
        return (int)diff;
    }

    // Abstract: perilaku beda per turunan
    virtual string getKategori() = 0;

    // Abstract: untuk kolom tabel (Jenis + Detail spesifik per turunan)
    virtual string getJenis() = 0;
    virtual string getInfoTambahan() = 0;

    // Abstract: cetak atribut Tanaman + atribut spesifik turunan
    virtual void tampilkanInfo() = 0;
};
