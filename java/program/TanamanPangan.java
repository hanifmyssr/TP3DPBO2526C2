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

    // Override: kategori spesifik
    @Override
    public String getKategori() { return "Tanaman Pangan"; }

    // Override: cetak atribut induk + atribut sendiri (polimorfisme)
    @Override
    public void tampilkanInfo() {
        String luasStr = (luasTanamM2 == (long) luasTanamM2) ? Long.toString((long) luasTanamM2) : Double.toString(luasTanamM2);
        String airStr = (kebutuhanAirLiterPerHari == (long) kebutuhanAirLiterPerHari) ? Long.toString((long) kebutuhanAirLiterPerHari) : Double.toString(kebutuhanAirLiterPerHari);
        System.out.println("  [" + getKategori() + "] ID: " + idTanaman + " | Nama: " + nama
            + " | Luas: " + luasStr + " m2 | Tanam: " + tanggalTanam
            + " (" + hitungUmurTanamHari() + " hari) | Jenis: " + jenisPangan
            + " | Air: " + airStr + " L/hari");
    }
}
