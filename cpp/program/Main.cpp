#include <bits/stdc++.h>
#include "Ladang.cpp"

// Ladang utama (orkestrator: pegang Petani + 2 array of object)
Ladang ladang("LDG001", "Ladang Sukamaju", 10000, "Sukabumi", Petani("T001", "Pak Ahmad", "Jl. Sawah No.1", 2015));

// Trim spasi awal/akhir
string trimStr(string s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == string::npos) return "";
    size_t b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b - a + 1);
}

// Validasi input tidak boleh kosong
string inputNotEmpty(string prompt) {
    string val;
    while (true) {
        cout << prompt;
        getline(cin, val);
        val = trimStr(val);
        if (val.empty()) {
            cout << "Input tidak boleh kosong!" << endl;
            continue;
        }
        return val;
    }
}

// Validasi angka double >= 0
double inputDouble(string prompt) {
    double v;
    while (true) {
        cout << prompt;
        cin >> v;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus berupa angka!" << endl;
            continue;
        }
        cin.ignore(1000, '\n');
        if (v < 0) {
            cout << "Input tidak boleh negatif!" << endl;
            continue;
        }
        return v;
    }
}

// Validasi angka int >= 0
int inputInt(string prompt) {
    int v;
    while (true) {
        cout << prompt;
        cin >> v;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus berupa angka bulat!" << endl;
            continue;
        }
        cin.ignore(1000, '\n');
        if (v < 0) {
            cout << "Input tidak boleh negatif!" << endl;
            continue;
        }
        return v;
    }
}

// Validasi tanggal format YYYY-MM-DD
bool tanggalValid(string s) {
    int y, m, d;
    if (sscanf(s.c_str(), "%d-%d-%d", &y, &m, &d) != 3) return false;
    if (m < 1 || m > 12 || d < 1 || d > 31) return false;
    if (y < 1900 || y > 2100) return false;
    return true;
}

string inputTanggal(string prompt) {
    string s;
    while (true) {
        cout << prompt;
        getline(cin, s);
        s = trimStr(s);
        if (!tanggalValid(s)) {
            cout << "Format tanggal harus YYYY-MM-DD! (contoh: 2026-06-10)" << endl;
            continue;
        }
        return s;
    }
}

// Validasi luas: tidak boleh melebihi sisa ladang
double inputLuasTanam() {
    while (true) {
        double luas = inputDouble("Luas Tanam (m2)   : ");
        double sisa = ladang.hitungSisaLuasLadang();
        if (luas > sisa) {
            cout << "Luas melebihi sisa ladang (" << sisa << " m2)! Kurangi luasnya." << endl;
            continue;
        }
        return luas;
    }
}

string inputIdTanaman() {
    string id;
    while (true) {
        cout << "ID Tanaman        : ";
        getline(cin, id);
        id = trimStr(id);
        if (id.empty()) {
            cout << "ID tidak boleh kosong!" << endl;
            continue;
        }
        if (ladang.idTanamanDipakai(id)) {
            cout << "ID sudah dipakai!" << endl;
            continue;
        }
        return id;
    }
}

void tambahTanaman() {
    cout << "\n--- Tambah Tanaman ---" << endl;
    cout << "Jenis: 1=Pangan  2=Sayur  3=Buah" << endl;
    int jenis;
    while (true) {
        cout << "Pilih jenis (1/2/3): ";
        cin >> jenis;
        if (cin.fail()) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Input harus berupa angka!" << endl;
            continue;
        }
        cin.ignore(1000, '\n');
        if (jenis < 1 || jenis > 3) {
            cout << "Pilih 1, 2, atau 3!" << endl;
            continue;
        }
        break;
    }

    string id = inputIdTanaman();
    string nama = inputNotEmpty("Nama              : ");
    double luas = inputLuasTanam();
    string tanggal = inputTanggal("Tanggal Tanam (YYYY-MM-DD): ");

    if (jenis == 1) {
        string jp = inputNotEmpty("Jenis Pangan      : ");
        double air = inputDouble("Butuh Air (L/hari): ");
        ladang.tanamTanamanBaru(new TanamanPangan(id, nama, luas, tanggal, jp, air));
    } else if (jenis == 2) {
        string js = inputNotEmpty("Jenis Sayur       : ");
        int masa = inputInt("Masa Panen (hari) : ");
        ladang.tanamTanamanBaru(new TanamanSayur(id, nama, luas, tanggal, js, masa));
    } else {
        string jb = inputNotEmpty("Jenis Buah        : ");
        double tinggi = inputDouble("Tinggi Pohon (m)  : ");
        ladang.tanamTanamanBaru(new TanamanBuah(id, nama, luas, tanggal, jb, tinggi));
    }
    cout << "Tanaman berhasil ditanam!" << endl;
}

void tambahAlat() {
    cout << "\n--- Tambah Alat Pertanian ---" << endl;
    string id;
    while (true) {
        cout << "ID Alat           : ";
        getline(cin, id);
        id = trimStr(id);
        if (id.empty()) {
            cout << "ID tidak boleh kosong!" << endl;
            continue;
        }
        if (ladang.idAlatDipakai(id)) {
            cout << "ID sudah dipakai!" << endl;
            continue;
        }
        break;
    }
    string nama = inputNotEmpty("Nama Alat         : ");
    string kondisi = inputNotEmpty("Kondisi           : ");
    int tahun = inputInt("Tahun Beli        : ");
    ladang.tambahAlat(new AlatPertanian(id, nama, kondisi, tahun));
    cout << "Alat berhasil ditambahkan!" << endl;
}

void tampilkanData(string judul) {
    cout << "\n>>> " << judul << " <<<" << endl;
    ladang.tampilkanInfoLadang();
    cout << "\n-- Daftar Tanaman (polimorfisme) --" << endl;
    ladang.tampilkanSemuaTanaman();
    cout << "\n-- Daftar Alat --" << endl;
    ladang.tampilkanSemuaAlat();
}

void tampilkanMenu() {
    cout << "\n===============================" << endl;
    cout << "  MANAJEMEN LADANG SUKAMAJU" << endl;
    cout << "===============================" << endl;
    cout << "1. Tanam Tanaman Baru" << endl;
    cout << "2. Tambah Alat" << endl;
    cout << "3. Tampilkan Semua Data" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih menu: ";
}

void animasiKeluar() {
    cout << "\nMenutup program";
    for (int i = 0; i < 3; i++) {
        this_thread::sleep_for(chrono::milliseconds(400));
        cout << "." << flush;
    }
    cout << "\n\n";
    vector<string> banner = {
        "#####  ####   ###      ####   ###  #   # #####",
        "  #    #   # #   #     #   # #   # ##  # #    ",
        "  #    ####     #      #   # #   # # # # #### ",
        "  #    #       #       #   # #   # #  ## #    ",
        "  #    #      ####     ####   ###  #   # #####"
    };
    for (auto& baris : banner) {
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << baris << endl;
    }
    cout << endl;
}

int main() {
    // Data awal SEBELUM ditambah: 6 tanaman (2 pangan + 2 sayur + 2 buah) + 3 alat
    ladang.tanamTanamanBaru(new TanamanPangan("PGN001", "Padi IR64", 2000, "2026-06-10", "Padi", 5000));
    ladang.tanamTanamanBaru(new TanamanPangan("PGN002", "Jagung Bisi-18", 1500, "2026-07-01", "Jagung", 3500));
    ladang.tanamTanamanBaru(new TanamanSayur("SYR001", "Bayam Hijau", 500, "2026-09-10", "Bayam", 25));
    ladang.tanamTanamanBaru(new TanamanSayur("SYR002", "Kangkung Cabut", 400, "2026-09-15", "Kangkung", 20));
    ladang.tanamTanamanBaru(new TanamanBuah("BUH001", "Mangga Harum Manis", 800, "2024-03-01", "Mangga", 4.5));
    ladang.tanamTanamanBaru(new TanamanBuah("BUH002", "Jeruk Siam", 600, "2025-01-15", "Jeruk", 3.2));

    ladang.tambahAlat(new AlatPertanian("ALT001", "Cangkul", "Baik", 2022));
    ladang.tambahAlat(new AlatPertanian("ALT002", "Traktor Mini", "Perlu Perawatan", 2020));
    ladang.tambahAlat(new AlatPertanian("ALT003", "Sprayer", "Baik", 2023));

    tampilkanData("Data AWAL Ladang (Sebelum Ditambah)");

    int pilihan;
    do {
        tampilkanMenu();
        cin >> pilihan;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus berupa angka!" << endl;
            pilihan = -1;
            continue;
        }
        cin.ignore(1000, '\n');

        switch (pilihan) {
            case 1: tambahTanaman(); break;
            case 2: tambahAlat(); break;
            case 3: tampilkanData("Data SESUDAH Ditambah"); break;
            case 0: animasiKeluar(); break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
