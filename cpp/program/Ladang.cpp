#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Petani.cpp"
#include "AlatPertanian.cpp"
#include "TanamanPangan.cpp"
#include "TanamanSayur.cpp"
#include "TanamanBuah.cpp"
using namespace std;

// Helper gaya screenshot: format angka + teks tengah untuk header box
static string fmtAngka(double v) {
    ostringstream oss; oss << v;
    return oss.str();
}
static string tengahBox(const string& s, int w) {
    int len = (int)s.length();
    if (len >= w) return s;
    int kiri = (w - len) / 2;
    int kanan = w - len - kiri;
    return string(kiri, ' ') + s + string(kanan, ' ');
}
static void cetakHeaderBox() {
    const int W = 66;
    string garisTengah(W, '=');
    cout << "+" << garisTengah << "+" << endl;
    cout << "|" << tengahBox("MANAJEMEN LADANG SUKAMAJU", W) << "|" << endl;
    cout << "|" << tengahBox("Sistem Manajemen Ladang & Tanaman", W) << "|" << endl;
    cout << "+" << garisTengah << "+" << endl;
}

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

    // Setter untuk setiap atribut
    void setIdLadang(string id) { idLadang = id; }
    void setNamaLadang(string n) { namaLadang = n; }
    void setLuasTotalM2(double luas) { luasTotalM2 = luas; }
    void setLokasi(string lok) { lokasi = lok; }
    void setPemilik(Petani p) { pemilik = p; }
    void setDaftarTanaman(vector<Tanaman*> daftar) { daftarTanaman = daftar; }
    void setDaftarAlat(vector<AlatPertanian*> daftar) { daftarAlat = daftar; }

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

    // Gaya screenshot: daftar hierarki bernomor + tree (polimorfisme:
    // getKategori/getJenis/getInfoTambahan otomatis versi override tiap jenis)
    void tampilkanSemuaTanaman() {
        cout << "[ DAFTAR TANAMAN ]" << endl;
        if (daftarTanaman.empty()) {
            cout << "  Belum ada tanaman." << endl;
            return;
        }
        for (size_t i = 0; i < daftarTanaman.size(); i++) {
            Tanaman* t = daftarTanaman[i];
            cout << "  " << (i + 1) << ". [" << t->getKategori() << "] "
                 << t->getNama() << " (" << t->getIdTanaman() << ")" << endl;
            ostringstream umurSs; umurSs << t->hitungUmurTanamHari() << " hr";
            cout << "     Detail : Luas " << fmtAngka(t->getLuasTanamM2())
                 << " m2 | Tanam " << t->getTanggalTanam() << " (" << umurSs.str() << ")"
                 << " | Jenis " << t->getJenis() << " | " << t->getInfoTambahan() << endl;
        }
    }

    // Gaya screenshot: daftar hierarki bernomor + tree
    void tampilkanSemuaAlat() {
        cout << "[ DAFTAR ALAT ]" << endl;
        if (daftarAlat.empty()) {
            cout << "  Belum ada alat." << endl;
            return;
        }
        for (size_t i = 0; i < daftarAlat.size(); i++) {
            AlatPertanian* a = daftarAlat[i];
            cout << "  " << (i + 1) << ". " << a->getNamaAlat()
                 << " (" << a->getIdAlat() << ")" << endl;
            cout << "     Detail : Kondisi " << a->getKondisi()
                 << " | Beli " << a->getTahunBeli() << endl;
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

    // Gaya screenshot: header box + bullet info (seperti [ INFORMASI BIMBEL ])
    void tampilkanInfoLadang() {
        cetakHeaderBox();
        cout << endl;
        cout << "[ INFORMASI LADANG ]" << endl;
        cout << "  - ID Ladang   : " << idLadang << endl;
        cout << "  - Nama Ladang : " << namaLadang << endl;
        cout << "  - Lokasi      : " << lokasi << endl;
        cout << "  - Luas Total  : " << fmtAngka(luasTotalM2) << " m2" << endl;
        cout << "  - Tertanam    : " << fmtAngka(hitungTotalLuasTertanam()) << " m2" << endl;
        cout << "  - Sisa        : " << fmtAngka(hitungSisaLuasLadang()) << " m2" << endl;
        cout << "  - Isi         : " << daftarTanaman.size() << " tanaman | "
             << daftarAlat.size() << " alat" << endl;
        cout << endl;
        cout << "[ INFORMASI PETANI ]" << endl;
        cout << "  - ID Petani   : " << pemilik.getIdPetani() << endl;
        cout << "  - Nama        : " << pemilik.getNama() << endl;
        cout << "  - Alamat      : " << pemilik.getAlamat() << endl;
        cout << "  - Mulai       : " << pemilik.getTahunMulaiBertani()
             << " (" << pemilik.getPengalamanTahun() << " thn pengalaman)" << endl;
    }
};
