// Turunan 3 dari Tanaman (Hierarchical Inheritance)
public class TanamanBuah extends Tanaman {
    private String jenisBuah;    // Misal Mangga, Jeruk
    private double tinggiPohonM; // Tinggi pohon (meter)

    public TanamanBuah(String id, String n, double luas, String tgl,
                       String jenis, double tinggi) {
        super(id, n, luas, tgl);
        this.jenisBuah = jenis;
        this.tinggiPohonM = tinggi;
    }

    public String getJenisBuah() { return jenisBuah; }
    public double getTinggiPohonM() { return tinggiPohonM; }

    // Override: kategori spesifik
    @Override
    public String getKategori() { return "Tanaman Buah"; }

    // Override: cetak atribut induk + atribut sendiri (polimorfisme)
    @Override
    public void tampilkanInfo() {
        String luasStr = (luasTanamM2 == (long) luasTanamM2) ? Long.toString((long) luasTanamM2) : Double.toString(luasTanamM2);
        String tinggiStr = (tinggiPohonM == (long) tinggiPohonM) ? Long.toString((long) tinggiPohonM) : Double.toString(tinggiPohonM);
        System.out.println("  [" + getKategori() + "] ID: " + idTanaman + " | Nama: " + nama
            + " | Luas: " + luasStr + " m2 | Tanam: " + tanggalTanam
            + " (" + hitungUmurTanamHari() + " hari) | Jenis: " + jenisBuah
            + " | Tinggi: " + tinggiStr + " m");
    }
}
