import java.util.ArrayList;
import java.util.List;

// Kelas utama/orkestrator: Ladang
// Composition: Ladang ◆— Petani (1), Ladang ◆— Tanaman (0..*), Ladang ◆— AlatPertanian (0..*)
public class Ladang {
    private String idLadang;                  // ID unik ladang
    private String namaLadang;                // Nama ladang/kebun
    private double luasTotalM2;               // Luas total lahan (m2)
    private String lokasi;                    // Lokasi ladang
    private Petani pemilik;                   // Composition (1): satu ladang satu petani
    private List<Tanaman> daftarTanaman;      // Composition + array of object (0..*)
    private List<AlatPertanian> daftarAlat;   // Composition + array of object (0..*)

    public Ladang(String id, String n, double luas, String lok, Petani p) {
        this.idLadang = id;
        this.namaLadang = n;
        this.luasTotalM2 = luas;
        this.lokasi = lok;
        this.pemilik = (p != null) ? p : new Petani();
        this.daftarTanaman = new ArrayList<>();
        this.daftarAlat = new ArrayList<>();
    }

    // Getter
    public String getIdLadang() { return idLadang; }
    public String getNamaLadang() { return namaLadang; }
    public double getLuasTotalM2() { return luasTotalM2; }
    public String getLokasi() { return lokasi; }
    public Petani getPemilik() { return pemilik; }
    public List<Tanaman> getDaftarTanaman() { return daftarTanaman; }
    public List<AlatPertanian> getDaftarAlat() { return daftarAlat; }

    // Setter untuk setiap atribut
    public void setIdLadang(String id) { this.idLadang = id; }
    public void setNamaLadang(String n) { this.namaLadang = n; }
    public void setLuasTotalM2(double luas) { this.luasTotalM2 = luas; }
    public void setLokasi(String lok) { this.lokasi = lok; }
    public void setPemilik(Petani p) { this.pemilik = p; }
    public void setDaftarTanaman(List<Tanaman> daftar) { this.daftarTanaman = daftar; }
    public void setDaftarAlat(List<AlatPertanian> daftar) { this.daftarAlat = daftar; }

    // Cek duplikat ID
    public boolean idTanamanDipakai(String id) {
        for (Tanaman t : daftarTanaman) {
            if (t.getIdTanaman().equals(id)) return true;
        }
        return false;
    }

    public boolean idAlatDipakai(String id) {
        for (AlatPertanian a : daftarAlat) {
            if (a.getIdAlat().equals(id)) return true;
        }
        return false;
    }

    // Tambahkan tanaman / alat
    public void tanamTanamanBaru(Tanaman tanaman) { daftarTanaman.add(tanaman); }
    public void tambahAlat(AlatPertanian alat) { daftarAlat.add(alat); }

    private static String fmt(double v) { return Tanaman.fmtAngka(v); }

    private static String tengah(String s, int w) {
        if (s.length() >= w) return s;
        int kiri = (w - s.length()) / 2;
        int kanan = w - s.length() - kiri;
        return " ".repeat(kiri) + s + " ".repeat(kanan);
    }

    private static void cetakHeaderBox() {
        int w = 66;
        System.out.println("+" + "=".repeat(w) + "+");
        System.out.println("|" + tengah("MANAJEMEN LADANG SUKAMAJU", w) + "|");
        System.out.println("|" + tengah("Sistem Manajemen Ladang & Tanaman", w) + "|");
        System.out.println("+" + "=".repeat(w) + "+");
    }

    // Gaya screenshot: daftar hierarki bernomor + tree (polimorfisme:
    // getKategori/getJenis/getInfoTambahan otomatis versi override tiap jenis)
    public void tampilkanSemuaTanaman() {
        System.out.println("[ DAFTAR TANAMAN ]");
        if (daftarTanaman.isEmpty()) {
            System.out.println("  Belum ada tanaman.");
            return;
        }
        for (int i = 0; i < daftarTanaman.size(); i++) {
            Tanaman t = daftarTanaman.get(i);
            System.out.println("  " + (i + 1) + ". [" + t.getKategori() + "] "
                + t.getNama() + " (" + t.getIdTanaman() + ")");
            System.out.println("     Detail : Luas " + fmt(t.getLuasTanamM2())
                + " m2 | Tanam " + t.getTanggalTanam() + " (" + t.hitungUmurTanamHari() + " hr)"
                + " | Jenis " + t.getJenis() + " | " + t.getInfoTambahan());
        }
    }

    // Gaya screenshot: daftar hierarki bernomor + tree
    public void tampilkanSemuaAlat() {
        System.out.println("[ DAFTAR ALAT ]");
        if (daftarAlat.isEmpty()) {
            System.out.println("  Belum ada alat.");
            return;
        }
        for (int i = 0; i < daftarAlat.size(); i++) {
            AlatPertanian a = daftarAlat.get(i);
            System.out.println("  " + (i + 1) + ". " + a.getNamaAlat() + " (" + a.getIdAlat() + ")");
            System.out.println("     Detail : Kondisi " + a.getKondisi()
                + " | Beli " + a.getTahunBeli());
        }
    }

    // Jumlahkan luasTanamM2 seluruh tanaman
    public double hitungTotalLuasTertanam() {
        double total = 0;
        for (Tanaman t : daftarTanaman) total += t.getLuasTanamM2();
        return total;
    }

    // luasTotal - totalTertanam
    public double hitungSisaLuasLadang() {
        return luasTotalM2 - hitungTotalLuasTertanam();
    }

    // Gaya screenshot: header box + bullet info (seperti [ INFORMASI BIMBEL ])
    public void tampilkanInfoLadang() {
        cetakHeaderBox();
        System.out.println();
        System.out.println("[ INFORMASI LADANG ]");
        System.out.println("  - ID Ladang   : " + idLadang);
        System.out.println("  - Nama Ladang : " + namaLadang);
        System.out.println("  - Lokasi      : " + lokasi);
        System.out.println("  - Luas Total  : " + fmt(luasTotalM2) + " m2");
        System.out.println("  - Tertanam    : " + fmt(hitungTotalLuasTertanam()) + " m2");
        System.out.println("  - Sisa        : " + fmt(hitungSisaLuasLadang()) + " m2");
        System.out.println("  - Isi         : " + daftarTanaman.size() + " tanaman | " + daftarAlat.size() + " alat");
        System.out.println();
        if (pemilik != null) {
            System.out.println("[ INFORMASI PETANI ]");
            System.out.println("  - ID Petani   : " + pemilik.getIdPetani());
            System.out.println("  - Nama        : " + pemilik.getNama());
            System.out.println("  - Alamat      : " + pemilik.getAlamat());
            System.out.println("  - Mulai       : " + pemilik.getTahunMulaiBertani()
                + " (" + pemilik.getPengalamanTahun() + " thn pengalaman)");
        }
    }
}
