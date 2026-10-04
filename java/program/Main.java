import java.time.LocalDate;
import java.time.format.DateTimeParseException;
import java.util.Scanner;


public class Main {

    // Scanner global untuk input user
    private static final Scanner sc = new Scanner(System.in);

    // Ladang utama (orkestrator: pegang Petani + 2 array of object)
    private static final Ladang ladang = new Ladang("LDG001", "Ladang Sukamaju", 10000, "Sukabumi",
            new Petani("T001", "Pak Ahmad", "Jl. Sawah No.1", 2015));

    // Validasi input tidak boleh kosong
    private static String inputNotEmpty(String prompt) {
        while (true) {
            System.out.print(prompt);
            String val = sc.nextLine().trim();
            if (val.isEmpty()) {
                System.out.println("Input tidak boleh kosong!");
                continue;
            }
            return val;
        }
    }

    // Validasi angka double >= 0
    private static double inputDouble(String prompt) {
        while (true) {
            System.out.print(prompt);
            try {
                double v = Double.parseDouble(sc.nextLine().trim());
                if (v < 0) {
                    System.out.println("Input tidak boleh negatif!");
                    continue;
                }
                return v;
            } catch (NumberFormatException e) {
                System.out.println("Input harus berupa angka!");
            }
        }
    }

    // Validasi angka int >= 0
    private static int inputInt(String prompt) {
        while (true) {
            System.out.print(prompt);
            try {
                int v = Integer.parseInt(sc.nextLine().trim());
                if (v < 0) {
                    System.out.println("Input tidak boleh negatif!");
                    continue;
                }
                return v;
            } catch (NumberFormatException e) {
                System.out.println("Input harus berupa angka bulat!");
            }
        }
    }

    // Validasi tanggal format YYYY-MM-DD
    private static String inputTanggal(String prompt) {
        while (true) {
            System.out.print(prompt);
            String val = sc.nextLine().trim();
            try {
                LocalDate.parse(val);
                return val;
            } catch (DateTimeParseException e) {
                System.out.println("Format tanggal harus YYYY-MM-DD! (contoh: 2026-06-10)");
            }
        }
    }

    // Validasi luas: tidak boleh melebihi sisa ladang
    private static double inputLuasTanam() {
        while (true) {
            double luas = inputDouble("Luas Tanam (m2)   : ");
            double sisa = ladang.hitungSisaLuasLadang();
            String sisaStr = (sisa == (long) sisa) ? Long.toString((long) sisa) : Double.toString(sisa);
            if (luas > sisa) {
                System.out.println("Luas melebihi sisa ladang (" + sisaStr + " m2)! Kurangi luasnya.");
                continue;
            }
            return luas;
        }
    }

    private static String inputIdTanaman() {
        while (true) {
            System.out.print("ID Tanaman        : ");
            String id = sc.nextLine().trim();
            if (id.isEmpty()) {
                System.out.println("ID tidak boleh kosong!");
                continue;
            }
            if (ladang.idTanamanDipakai(id)) {
                System.out.println("ID sudah dipakai!");
                continue;
            }
            return id;
        }
    }

    private static void tambahTanaman() {
        System.out.println();
        System.out.println("--- Tambah Tanaman ---");
        System.out.println("Jenis: 1=Pangan  2=Sayur  3=Buah");
        int jenis;
        while (true) {
            System.out.print("Pilih jenis (1/2/3): ");
            try {
                jenis = Integer.parseInt(sc.nextLine().trim());
            } catch (NumberFormatException e) {
                System.out.println("Input harus berupa angka!");
                continue;
            }
            if (jenis < 1 || jenis > 3) {
                System.out.println("Pilih 1, 2, atau 3!");
                continue;
            }
            break;
        }

        String id = inputIdTanaman();
        String nama = inputNotEmpty("Nama              : ");
        double luas = inputLuasTanam();
        String tanggal = inputTanggal("Tanggal Tanam (YYYY-MM-DD): ");

        if (jenis == 1) {
            String jp = inputNotEmpty("Jenis Pangan      : ");
            double air = inputDouble("Butuh Air (L/hari): ");
            ladang.tanamTanamanBaru(new TanamanPangan(id, nama, luas, tanggal, jp, air));
        } else if (jenis == 2) {
            String js = inputNotEmpty("Jenis Sayur       : ");
            int masa = inputInt("Masa Panen (hari) : ");
            ladang.tanamTanamanBaru(new TanamanSayur(id, nama, luas, tanggal, js, masa));
        } else {
            String jb = inputNotEmpty("Jenis Buah        : ");
            double tinggi = inputDouble("Tinggi Pohon (m)  : ");
            ladang.tanamTanamanBaru(new TanamanBuah(id, nama, luas, tanggal, jb, tinggi));
        }
        System.out.println("Tanaman berhasil ditanam!");
    }

    private static void tambahAlat() {
        System.out.println();
        System.out.println("--- Tambah Alat Pertanian ---");
        String id;
        while (true) {
            System.out.print("ID Alat           : ");
            id = sc.nextLine().trim();
            if (id.isEmpty()) {
                System.out.println("ID tidak boleh kosong!");
                continue;
            }
            if (ladang.idAlatDipakai(id)) {
                System.out.println("ID sudah dipakai!");
                continue;
            }
            break;
        }
        String nama = inputNotEmpty("Nama Alat         : ");
        String kondisi = inputNotEmpty("Kondisi           : ");
        int tahun = inputInt("Tahun Beli        : ");
        ladang.tambahAlat(new AlatPertanian(id, nama, kondisi, tahun));
        System.out.println("Alat berhasil ditambahkan!");
    }

    private static void tampilkanData(String judul) {
        System.out.println();
        System.out.println(">>> " + judul + " <<<");
        ladang.tampilkanInfoLadang();
        System.out.println();
        System.out.println("-- Daftar Tanaman (polimorfisme) --");
        ladang.tampilkanSemuaTanaman();
        System.out.println();
        System.out.println("-- Daftar Alat --");
        ladang.tampilkanSemuaAlat();
    }

    private static void tampilkanMenu() {
        System.out.println();
        System.out.println("===============================");
        System.out.println("  MANAJEMEN LADANG SUKAMAJU");
        System.out.println("===============================");
        System.out.println("1. Tanam Tanaman Baru");
        System.out.println("2. Tambah Alat");
        System.out.println("3. Tampilkan Semua Data");
        System.out.println("0. Keluar");
        System.out.print("Pilih menu: ");
    }

    private static void animasiKeluar() {
        System.out.print("\nMenutup program");
        for (int i = 0; i < 3; i++) {
            try { Thread.sleep(400); } catch (InterruptedException e) {}
            System.out.print(".");
            System.out.flush();
        }
        System.out.println("\n");
        String[] banner = {
            "#####  ####   ###      ####   ###  #   # #####",
            "  #    #   # #   #     #   # #   # ##  # #    ",
            "  #    ####     #      #   # #   # # # # #### ",
            "  #    #       #       #   # #   # #  ## #    ",
            "  #    #      ####     ####   ###  #   # #####"
        };
        for (String baris : banner) {
            try { Thread.sleep(150); } catch (InterruptedException e) {}
            System.out.println(baris);
        }
        System.out.println();
    }

    public static void main(String[] args) {
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
            try {
                pilihan = Integer.parseInt(sc.nextLine().trim());
            } catch (NumberFormatException e) {
                System.out.println("Input harus berupa angka!");
                pilihan = -1;
                continue;
            }

            switch (pilihan) {
                case 1:  tambahTanaman(); break;
                case 2:  tambahAlat(); break;
                case 3:
                    tampilkanData("Data SESUDAH Ditambah");
                    break;
                case 0:  animasiKeluar(); break;
                default: System.out.println("Pilihan tidak valid!");
            }

        } while (pilihan != 0);
    }
}
