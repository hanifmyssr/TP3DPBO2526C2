import java.time.LocalDate;
import java.time.format.DateTimeParseException;
import java.time.temporal.ChronoUnit;

// Kelas abstrak induk semua tanaman (Hierarchical Inheritance root)
// Punya campuran method concrete + abstract
public abstract class Tanaman {
    protected String idTanaman;    // ID unik tanaman
    protected String nama;         // Nama tanaman
    protected double luasTanamM2;  // Luas yang dipakai tanaman ini (m2)
    protected String tanggalTanam; // Tanggal mulai ditanam (YYYY-MM-DD)

    public Tanaman(String id, String n, double luas, String tgl) {
        this.idTanaman = id;
        this.nama = n;
        this.luasTanamM2 = luas;
        this.tanggalTanam = tgl;
    }

    public Tanaman() {
        this("", "", 0.0, "2026-01-01");
    }

    // Getter standar
    public String getIdTanaman() { return idTanaman; }
    public String getNama() { return nama; }
    public double getLuasTanamM2() { return luasTanamM2; }
    public String getTanggalTanam() { return tanggalTanam; }

    // Setter untuk setiap atribut
    public void setIdTanaman(String id) { this.idTanaman = id; }
    public void setNama(String n) { this.nama = n; }
    public void setLuasTanamM2(double luas) { this.luasTanamM2 = luas; }
    public void setTanggalTanam(String tgl) { this.tanggalTanam = tgl; }

    // Concrete (bukan abstract): hitung selisih hari dari tanggalTanam sampai sekarang
    // Dipakai sama persis oleh semua turunan
    public int hitungUmurTanamHari() {
        try {
            LocalDate tgl = LocalDate.parse(tanggalTanam);
            long diff = ChronoUnit.DAYS.between(tgl, LocalDate.now());
            if (diff < 0) return 0;
            return (int) diff;
        } catch (DateTimeParseException e) {
            return 0;
        }
    }

    // Abstract: perilaku beda per turunan
    public abstract String getKategori();

    // Abstract: untuk kolom tabel (Jenis + Detail spesifik per turunan)
    public abstract String getJenis();
    public abstract String getInfoTambahan();

    // Helper format angka: hilangkan .0 bila bulat (untuk tabel)
    public static String fmtAngka(double v) {
        if (v == (long) v) return Long.toString((long) v);
        return Double.toString(v);
    }

    // Abstract: cetak atribut Tanaman + atribut spesifik turunan
    public abstract void tampilkanInfo();
}
