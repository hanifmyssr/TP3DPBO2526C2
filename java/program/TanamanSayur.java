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

    // Setter untuk setiap atribut sendiri (+ setter warisan dari Tanaman)
    public void setJenisSayur(String jenis) { this.jenisSayur = jenis; }
    public void setMasaPanenHari(int masa) { this.masaPanenHari = masa; }

    // Override: kategori spesifik
    @Override
    public String getKategori() { return "Tanaman Sayur"; }

    // Override: kolom tabel
    @Override
    public String getJenis() { return jenisSayur; }
    @Override
    public String getInfoTambahan() { return "Panen: " + masaPanenHari + " hari"; }

    // Override: cetak atribut induk + atribut sendiri (polimorfisme)
    @Override
    public void tampilkanInfo() {
        String luasStr = Tanaman.fmtAngka(luasTanamM2);
        System.out.println("  [" + getKategori() + "] ID: " + idTanaman + " | Nama: " + nama
            + " | Luas: " + luasStr + " m2 | Tanam: " + tanggalTanam
            + " (" + hitungUmurTanamHari() + " hari) | Jenis: " + jenisSayur
            + " | Panen: " + masaPanenHari + " hari");
    }
}
