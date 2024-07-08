#include <iostream>
using namespace std;

class MataKuliah {
protected:
    float presensi;

public:
    MataKuliah() {
        presensi = 0.0;
    }

    virtual void namaMataKuliah() = 0; // Fungsi abstrak
    virtual float hitungNilaiAkhir() = 0; // Fungsi abstrak
    virtual void cekKelulusan() = 0; // Fungsi abstrak

    void setPresensi(float nilai) {
        this->presensi = nilai;
    }

    float getPresensi() {
        return presensi;
    }
};

class Pemrograman : public MataKuliah {
private:
    float activity, exercise, tugasAkhir;

public:
    Pemrograman() {
        activity = 0.0;
        exercise = 0.0;
        tugasAkhir = 0.0;
    }

    void inputNilai() {
        Scanner scanner(cin);

        cout << "Masukkan nilai presensi: ";
        setPresensi(scanner.nextFloat());

        cout << "Masukkan nilai activity: ";
        activity = scanner.nextFloat();

        cout << "Masukkan nilai exercise: ";
        exercise = scanner.nextFloat();

        cout << "Masukkan nilai tugas akhir: ";
        tugasAkhir = scanner.nextFloat();
    }

    override void namaMataKuliah() {
        cout << "Pemrograman" << endl;
    }

    override float hitungNilaiAkhir() {
        return (getPresensi() * 10) + (activity * 20) + (exercise * 20) + (tugasAkhir * 50);
    }

    override void cekKelulusan() {
        float nilaiAkhir = hitungNilaiAkhir();
        string kelulusan = nilaiAkhir >= 75 ? "Lulus" : "Tidak Lulus";

        cout << "Mata Kuliah: " << namaMataKuliah() << endl;
        cout << "Nilai Akhir: " << nilaiAkhir << endl;
        cout << "Hasil: " << kelulusan << endl;
    }
};

class Jaringan : public MataKuliah {
private:
    float activity, exercise;

public:
    Jaringan() {
        activity = 0.0;
        exercise = 0.0;
    }

    void inputNilai() {
        Scanner scanner(cin);

        cout << "Masukkan nilai presensi: ";
        setPresensi(scanner.nextFloat());

        cout << "Masukkan nilai activity: ";
        activity = scanner.nextFloat();

        cout << "Masukkan nilai exercise: ";
        exercise = scanner.nextFloat();
    }

    override void namaMataKuliah() {
        cout << "Jaringan" << endl;
    }

    override float hitungNilaiAkhir() {
        return (getPresensi() * 10) + (activity * 40) + (exercise * 50);
    }

    override void cekKelulusan() {
        float nilaiAkhir = hitungNilaiAkhir();
        string kelulusan = nilaiAkhir >= 75 ? "Lulus" : "Tidak Lulus";

        cout << "Mata Kuliah: " << namaMataKuliah() << endl;
        cout << "Nilai Akhir: " << nilaiAkhir << endl;
        cout << "Hasil: " << kelulusan << endl;
    }
};

int main() {
    char pilih;
    MataKuliah* mataKuliah;
    Pemrograman pemrograman;
    Jaringan jaringan;

    cout << "Pilih Mata Kuliah: " << endl;
    cout << "1. Pemrograman" << endl;
    cout << "2. Jaringan" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> pilih;

    switch (pilih) {
    case '1':
        mataKuliah = &pemprograman;
        break;
    case '2':
        mataKuliah = &jaringan;
        break;
    default:
        cout << "Pilihan tidak valid!" << endl;
        return 1;
    }

    mataKuliah->inputNilai();
    mataKuliah->hitungNilaiAkhir();
    mataKuliah->cekKelulusan();

    return 0;
}