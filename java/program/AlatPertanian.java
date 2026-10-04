public class AlatPertanian {
    private String idAlat;    // ID unik alat
    private String namaAlat;  // Misal Cangkul, Traktor, Sprayer
    private String kondisi;   // Baik / Rusak / Perlu Perawatan
    private int tahunBeli;    // Tahun alat dibeli

    public AlatPertanian(String id, String n, String k, int thn) {
        this.idAlat = id;
        this.namaAlat = n;
        this.kondisi = k;
        this.tahunBeli = thn;
    }

    public AlatPertanian() {
        this("", "", "Baik", 2023);
    }

    // Getter
    public String getIdAlat() { return idAlat; }
    public String getNamaAlat() { return namaAlat; }
    public String getKondisi() { return kondisi; }
    public int getTahunBeli() { return tahunBeli; }

    // Update status kondisi alat
    public void setKondisi(String baru) { this.kondisi = baru; }

    // Cetak detail alat
    public void tampilkanInfoAlat() {
        System.out.println("  Alat: " + namaAlat + " (" + idAlat + ") | Kondisi: " + kondisi
            + " | Beli: " + tahunBeli);
    }
}
