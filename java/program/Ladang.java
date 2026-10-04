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

    // Loop daftarTanaman, panggil tampilkanInfo() tiap elemen
    // (polimorfisme: otomatis versi override masing-masing jenis)
    public void tampilkanSemuaTanaman() {
        if (daftarTanaman.isEmpty()) {
            System.out.println("  Belum ada tanaman.");
            return;
        }
        for (int i = 0; i < daftarTanaman.size(); i++) {
            System.out.print("  " + (i + 1) + ". ");
            daftarTanaman.get(i).tampilkanInfo();
        }
    }

    // Loop daftarAlat
    public void tampilkanSemuaAlat() {
        if (daftarAlat.isEmpty()) {
            System.out.println("  Belum ada alat.");
            return;
        }
        for (int i = 0; i < daftarAlat.size(); i++) {
            System.out.print("  " + (i + 1) + ". ");
            daftarAlat.get(i).tampilkanInfoAlat();
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

    // Cetak ladang + pemilik (delegasi ke pemilik.tampilkanInfoPetani)
    public void tampilkanInfoLadang() {
        String totalStr = (luasTotalM2 == (long) luasTotalM2) ? Long.toString((long) luasTotalM2) : Double.toString(luasTotalM2);
        double tertanam = hitungTotalLuasTertanam();
        double sisa = hitungSisaLuasLadang();
        String tanamStr = (tertanam == (long) tertanam) ? Long.toString((long) tertanam) : Double.toString(tertanam);
        String sisaStr = (sisa == (long) sisa) ? Long.toString((long) sisa) : Double.toString(sisa);
        System.out.println("Ladang " + namaLadang + " (" + idLadang + ") | Lokasi: " + lokasi);
        System.out.println("Luas total: " + totalStr + " m2 | Tertanam: " + tanamStr
            + " m2 | Sisa: " + sisaStr + " m2");
        if (pemilik != null) pemilik.tampilkanInfoPetani();
        System.out.println("Jumlah tanaman: " + daftarTanaman.size() + " | Jumlah alat: " + daftarAlat.size());
    }
}
