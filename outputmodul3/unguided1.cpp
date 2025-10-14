#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

void inputMahasiswa(Mahasiswa &mhs) {
    cout << "Masukkan Nama          : ";
    getline(cin, mhs.nama);
    cout << "Masukkan NIM           : ";
    getline(cin, mhs.nim);
    cout << "Masukkan Nilai UTS     : ";
    cin >> mhs.uts;
    cout << "Masukkan Nilai UAS     : ";
    cin >> mhs.uas;
    cout << "Masukkan Nilai Tugas   : ";
    cin >> mhs.tugas;
    cin.ignore();
    mhs.nilaiAkhir = hitungNilaiAkhir(mhs.uts, mhs.uas, mhs.tugas);
}

void tampilMahasiswa(Mahasiswa mhs[], int jumlah) {
    cout << "\n==============================================\n";
    cout << "Daftar Data Mahasiswa\n";
    cout << "==============================================\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama                 : " << mhs[i].nama << endl;
        cout << "NIM                  : " << mhs[i].nim << endl;
        cout << "UTS                  : " << mhs[i].uts << endl;
        cout << "UAS                  : " << mhs[i].uas << endl;
        cout << "Tugas                : " << mhs[i].tugas << endl;
        cout << "Nilai Akhir          : " << mhs[i].nilaiAkhir << endl;
        cout << "----------------------------------------------\n";
    }
}

int main() {
    Mahasiswa daftarMhs[10];
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> jumlah;
    cin.ignore();

    if (jumlah > 10) {
        cout << "Jumlah melebihi batas maksimum (10)!" << endl;
        return 0;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nInput data mahasiswa ke-" << i + 1 << endl;
        inputMahasiswa(daftarMhs[i]);
    }

    tampilMahasiswa(daftarMhs, jumlah);

    return 0;
}