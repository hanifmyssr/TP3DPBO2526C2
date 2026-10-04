// Turunan 2 dari Tanaman (Hierarchical Inheritance)
public class TanamanSayur extends Tanaman {
    private String jenisSayur;  // Misal Bayam, Kangkung
    private int masaPanenHari;  // Hari sampai siap panen

    public TanamanSayur(String id, String n, double luas, String tgl,
                        String jenis, int masa) {
        super(id, n, luas, tgl);
        this.jenisSayur = jenis;
        this.masaPanenHari = masa;
    }

    public String getJenisSayur() { return jenisSayur; }
    public int getMasaPanenHari() { return masaPanenHari; }

    // Override: kategori spesifik
    @Override
    public String getKategori() { return "Tanaman Sayur"; }

    // Override: cetak atribut induk + atribut sendiri (polimorfisme)
    @Override
    public void tampilkanInfo() {
        String luasStr = (luasTanamM2 == (long) luasTanamM2) ? Long.toString((long) luasTanamM2) : Double.toString(luasTanamM2);
        System.out.println("  [" + getKategori() + "] ID: " + idTanaman + " | Nama: " + nama
            + " | Luas: " + luasStr + " m2 | Tanam: " + tanggalTanam
            + " (" + hitungUmurTanamHari() + " hari) | Jenis: " + jenisSayur
            + " | Panen: " + masaPanenHari + " hari");
    }
}
