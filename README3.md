# <h1 align="center">Laporan Praktikum Modul 3 <br> Abstract Data Type </h1>
<p align="center">Dahragassya Safnas Adiyata - 103112430146</p>

## Dasar Teori

Abstract Data Type (ADT), atau Tipe Data Abstrak, adalah konsep fundamental dalam ilmu komputer yang mendefinisikan sebuah tipe data dari sudut pandang logis atau matematis, bukan dari sudut pandang implementasi fisiknya. ADT adalah spesifikasi tentang apa yang dilakukan oleh suatu tipe data, yang terdiri dari dua komponen utama: koleksi data yang akan disimpan, dan set operasi (fungsi atau metode) yang dapat diterapkan pada data tersebut. . Inti dari ADT adalah abstraksi, di mana kita memisahkan definisi fungsional (antarmuka publik) dari detail implementasi internal (struktur data yang mendasarinya dan kode algoritmik). Misalnya, kita mendefinisikan ADT Stack dengan operasi push (tambah) dan pop (ambil), tanpa peduli apakah Stack tersebut nantinya akan diimplementasikan menggunakan array atau linked list.


## Guided

### guided 1
   ```c++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa
{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif

```

File MAHASISWA_H_INCLUDED berfungsi sebagai kontrak (interface) untuk modul mahasiswa dalam program C++, dilindungi oleh header guard untuk mencegah pendefinisian ganda. File ini mendefinisikan struktur data mahasiswa yang terdiri dari NIM (char nim[10]), dan dua nilai integer (nilai1 dan nilai2). Selain struktur, file ini mendeklarasikan dua prototipe fungsi: void inputMhs(mahasiswa &m) yang memungkinkan pengguna mengisi data mahasiswa (menggunakan referensi untuk memodifikasi objek), dan float rata2(mahasiswa m) yang bertugas menghitung dan mengembalikan hasil rata-rata dari kedua nilai tersebut dalam tipe data floating point.

### guided 2
   ```c++
#include "mahasiswa.h"
#include <iostream>
using namespace std;

void inputMhs(mahasiswa &m)
{
    cout << "input nama = ";
    cin >> (m) .nim;
    cout << "input nilai = ";
    cin >> (m) .nilai1;
    cout << "input niali2 = ";
    cin >> m .nilai2;

}
float rata2(mahasiswa m)
{
    return float(m.nilai1 + m.nilai2) / 2;
}

```

Kode  ini mengimplementasikan dua fungsi inti untuk mengelola data mahasiswa yang didefinisikan dalam header mahasiswa.h. Fungsi inputMhs bertugas menerima input dari pengguna (NIM, nilai pertama, dan nilai kedua) dan menyimpannya ke objek mahasiswa melalui referensi. Sementara itu, fungsi rata2 menghitung nilai rata-rata dari kedua nilai tersebut dan mengembalikan hasilnya dalam tipe floating point untuk memastikan presisi desimal.



### guided 3


```c++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main(){
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata rata = " << rata2(mhs);
    return 0;
}
```
Kode ini adalah program utama (main) yang memanfaatkan struktur dan fungsi yang dideklarasikan di file header mahasiswa.h dan diimplementasikan di file .cpp lain. Pertama, ia mendeklarasikan objek mhs dari tipe mahasiswa. Selanjutnya, fungsi inputMhs(mhs) dipanggil untuk meminta pengguna memasukkan NIM dan dua nilai (nilai1 dan nilai2) ke dalam objek tersebut. Terakhir, program menghitung dan langsung mencetak hasil rata-rata kedua nilai tersebut menggunakan fungsi rata2(mhs), lalu program diakhiri.




## Unguided

### Soal 1

```c++
#include <iostream>
#include <iomanip>

using namespace std;

const int N = 3;

void input_matriks(int matriks[N][N]) {
    cout << "Masukkan elemen Matriks " << N << "x" << N << " (baris per baris):" << endl;
    
    for (int i = 0; i < N; ++i) {
        cout << "Baris " << i + 1 << ": ";
        for (int j = 0; j < N; ++j) {
            cin >> matriks[i][j];
        }
    }
}

void transpose_matriks(const int matriks_awal[N][N], int matriks_transpose[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matriks_transpose[i][j] = matriks_awal[j][i];
        }
    }
}

void cetak_matriks(const int matriks[N][N], const char* judul) {
    cout << "\n" << judul << ":" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(3) << matriks[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int matriks_awal[N][N];
    int matriks_transpose[N][N];
    
    input_matriks(matriks_awal);
    
    transpose_matriks(matriks_awal, matriks_transpose);
    
    cetak_matriks(matriks_awal, "Matriks Awal");
    cetak_matriks(matriks_transpose, "Matriks Hasil Transpose");

    return 0;
}
```
>

Kode program C++ ini dirancang untuk melakukan transpose (mengubah baris menjadi kolom) pada sebuah matriks 3×3, dengan memisahkan tugas menjadi tiga fungsi utama demi kejelasan dan modularitas. Fungsi input_matriks bertugas meminta sembilan angka dari pengguna (tiga per baris) untuk mengisi matriks_awal. Fungsi transpose_matriks kemudian memproses matriks tersebut menggunakan logika inti matriks_transpose[i][j] = matriks_awal[j][i]. Terakhir, fungsi cetak_matriks bertanggung jawab mencetak kedua matriks (awal dan hasil transpose) ke layar dengan rapi menggunakan std::setw(3). Fungsi main() hanya berfungsi sebagai orkestrator yang memanggil ketiga fungsi ini secara berurutan untuk menyelesaikan seluruh proses
> Output
> ![Screenshot bagian x](outputmodul2/Screenshot_unguided1.png)


