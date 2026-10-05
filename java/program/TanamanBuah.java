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

    // Setter untuk setiap atribut sendiri (+ setter warisan dari Tanaman)
    public void setJenisBuah(String jenis) { this.jenisBuah = jenis; }
    public void setTinggiPohonM(double tinggi) { this.tinggiPohonM = tinggi; }

    // Override: kategori spesifik
    @Override
    public String getKategori() { return "Tanaman Buah"; }

    // Override: kolom tabel
    @Override
    public String getJenis() { return jenisBuah; }
    @Override
    public String getInfoTambahan() { return "Tinggi: " + Tanaman.fmtAngka(tinggiPohonM) + " m"; }

    // Override: cetak atribut induk + atribut sendiri (polimorfisme)
    @Override
    public void tampilkanInfo() {
        String luasStr = Tanaman.fmtAngka(luasTanamM2);
        String tinggiStr = Tanaman.fmtAngka(tinggiPohonM);
        System.out.println("  [" + getKategori() + "] ID: " + idTanaman + " | Nama: " + nama
            + " | Luas: " + luasStr + " m2 | Tanam: " + tanggalTanam
            + " (" + hitungUmurTanamHari() + " hari) | Jenis: " + jenisBuah
            + " | Tinggi: " + tinggiStr + " m");
    }
}
