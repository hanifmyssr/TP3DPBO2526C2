import java.time.Year;

public class Petani {
    private String idPetani;         // ID unik petani
    private String nama;             // Nama petani
    private String alamat;           // Alamat tinggal
    private int tahunMulaiBertani;   // Tahun mulai bertani

    public Petani(String id, String n, String al, int thn) {
        this.idPetani = id;
        this.nama = n;
        this.alamat = al;
        this.tahunMulaiBertani = thn;
    }

    public Petani() {
        this("", "", "", 2020);
    }

    // Getter
    public String getIdPetani() { return idPetani; }
    public String getNama() { return nama; }
    public String getAlamat() { return alamat; }
    public int getTahunMulaiBertani() { return tahunMulaiBertani; }

    // Hitung tahun sekarang - tahunMulaiBertani
    public int getPengalamanTahun() {
        return Year.now().getValue() - tahunMulaiBertani;
    }

    // Cetak semua info petani
    public void tampilkanInfoPetani() {
        System.out.println("  Petani: " + nama + " (" + idPetani + ") | Alamat: " + alamat
            + " | Pengalaman: " + getPengalamanTahun() + " tahun");
    }
}
