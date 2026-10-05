// Turunan 1 dari Tanaman (Hierarchical Inheritance)
public class TanamanPangan extends Tanaman {
    private String jenisPangan;              // Misal Padi, Jagung
    private double kebutuhanAirLiterPerHari; // Liter/hari

    public TanamanPangan(String id, String n, double luas, String tgl,
                         String jenis, double air) {
        super(id, n, luas, tgl);
        this.jenisPangan = jenis;
        this.kebutuhanAirLiterPerHari = air;
    }

    public String getJenisPangan() { return jenisPangan; }
    public double getKebutuhanAirLiterPerHari() { return kebutuhanAirLiterPerHari; }

    // Setter untuk setiap atribut sendiri (+ setter warisan dari Tanaman)
    public void setJenisPangan(String jenis) { this.jenisPangan = jenis; }
    public void setKebutuhanAirLiterPerHari(double air) { this.kebutuhanAirLiterPerHari = air; }

    // Override: kategori spesifik
    @Override
    public String getKategori() { return "Tanaman Pangan"; }

    // Override: kolom tabel
    @Override
    public String getJenis() { return jenisPangan; }
    @Override
    public String getInfoTambahan() { return "Air: " + Tanaman.fmtAngka(kebutuhanAirLiterPerHari) + " L/hari"; }

    // Override: cetak atribut induk + atribut sendiri (polimorfisme)
    @Override
    public void tampilkanInfo() {
        String luasStr = Tanaman.fmtAngka(luasTanamM2);
        String airStr = Tanaman.fmtAngka(kebutuhanAirLiterPerHari);
        System.out.println("  [" + getKategori() + "] ID: " + idTanaman + " | Nama: " + nama
            + " | Luas: " + luasStr + " m2 | Tanam: " + tanggalTanam
            + " (" + hitungUmurTanamHari() + " hari) | Jenis: " + jenisPangan
            + " | Air: " + airStr + " L/hari");
    }
}
