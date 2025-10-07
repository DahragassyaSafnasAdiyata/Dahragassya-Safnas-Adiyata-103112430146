# <h1 align="center">Laporan Praktikum Modul 2 <br> PENGENALAN C++ </h1>
<p align="center">Dahragassya Safnas Adiyata - 103112430146</p>

## Dasar Teori

C++ adalah bahasa pemrograman tingkat menengah yang dikembangkan oleh Bjarne Stroustrup di Bell Labs pada awal 1980-an, sebagai evolusi dari bahasa C (yang awalnya dibuat oleh Dennis Ritchie untuk sistem Unix). C++ dibangun untuk mempertahankan efisiensi dan dukungan pemrograman tingkat rendah (low level coding) dari C, namun dengan penambahan konsep-konsep baru. Perbedaan paling mendasar adalah dukungan penuh C++ terhadap Pemrograman Berorientasi Objek (OOP), memperkenalkan fitur seperti class, inheritance, dan overloading.

## Guided

### soal 1 (Aritmatika)
    #include <iostream>
    using namespace std;
    int main()
    {
    int W, X, Y;
    float Z;
    X = 7;
    Y = 3;
    W = 1;
    Z = (X + Y) / (Y + W);
    cout << "Nilai z = " << Z << endl;
    return 0;
    }

Kode C++ di atas adalah program sederhana yang menghitung nilai variabel Z. Program pertama-tama mendeklarasikan tiga variabel integer (W, X, Y) dan satu variabel floating-point (Z). Variabel X diinisialisasi dengan nilai 7, Y dengan 3, dan W dengan 1. Perhitungan nilai Z menggunakan rumus (X + Y) / (Y + W), yang secara matematis adalah (7+3)/(3+1) atau 10/4. Karena semua operan dalam perhitungan ini adalah integer (X, Y, W), operasi 10/4 akan menghasilkan pembagian integer, yang hasilnya adalah 2 (sisa 2 diabaikan), dan hasil integer 2 ini kemudian diubah (cast) menjadi float saat disimpan di variabel Z. Akhirnya, program mencetak pesan "Nilai z = " diikuti nilai 2.00 (atau 2) ke konsol.

> Output
> ![Screenshot bagian x](output/Screenshot_guided1.png)



### soal 2 (fungsi)


    #include <iostream>
    using namespace std;

    // Prosedur: hanya menampilkan hasil, tidak mengembalikan nilai
    void tampilkanHasil(double p, double l)
    {
    cout << "\n=== Hasil Perhitungan ===" << endl;
    cout << "Panjang : " << p << endl;
    cout << "Lebar   : " << l << endl;
    cout << "Luas    : " << p * l << endl;
    cout << "Keliling: " << 2 * (p + l) << endl;
    }

    // Fungsi: mengembalikan nilai luas
    double hitungLuas(double p, double l)
    {    
    return p * l;
    }

    // Fungsi: mengembalikan nilai keliling
    double hitungKeliling(double p, double l)
    {
    return 2 * (p + l);
    }

    int main()
    {
    double panjang, lebar;

    cout << "Masukkan panjang: ";
    cin >> panjang;
    cout << "Masukkan lebar  : ";
    cin >> lebar;

    // Panggil fungsi
    double luas = hitungLuas(panjang, lebar);
    double keliling = hitungKeliling(panjang, lebar);

    cout << "\nDihitung dengan fungsi:" << endl;
    cout << "Luas      = " << luas << endl;
    cout << "Keliling  = " << keliling << endl;

    // Panggil prosedur
    tampilkanHasil(panjang, lebar);

    return 0;
    }

Kode C++ diatas secara modular menghitung dan menampilkan luas serta keliling persegi panjang. Program diawali dengan meminta panjang dan lebar dari pengguna. Logika perhitungan dipecah menjadi dua fungsi terpisah (hitungLuas dan hitungKeliling) yang mengembalikan nilai double untuk digunakan kembali di main(). Selain itu, terdapat satu prosedur (tampilkanHasil, bertipe void) yang tidak mengembalikan nilai tetapi bertanggung jawab langsung untuk menerima data dan mencetak semua hasil perhitungan sekaligus ke konsol, mendemonstrasikan kedua pendekatan dalam membagi tugas pemrograman.

> Output
> ![Screenshot bagian x](output/Screenshot_guided2.png)


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
> ![Screenshot bagian x](output/Screenshot_unguided1.png)



### Soal 2

soal nomor 2

```c++
#include <iostream>

using namespace std;

void kuadratkan(int &angka)
{
    angka = angka * angka;
}

int main()
{
    int nilai;

    cout << "Masukkan nilai awal yang ingin dikuadratkan: ";
    cin >> nilai;

    cout << "Nilai awal: " << nilai << endl;

    kuadratkan(nilai);

    cout << "Nilai setelah dikuadratkan: " << nilai << endl;

    return 0;
}
```

Kode ini meminta pengguna memasukkan sebuah angka (nilai). Kemudian, ia memanggil fungsi kuadratkan, yang didefinisikan menggunakan referensi (&). Karena ada tanda &, fungsi tersebut tidak membuat salinan dari nilai, melainkan mendapatkan akses langsung ke variabel nilai yang asli di memori. Ketika angka = angka * angka dijalankan di dalam fungsi, ia mengubah nilai variabel asli (nilai) menjadi kuadratnya. Hasilnya, nilai yang dicetak sebelum dan sesudah pemanggilan fungsi akan berbeda, membuktikan bahwa fungsi berhasil mengubah variabel nilai secara permanen.

> Output
> ![Screenshot bagian x](output/Screenshot_unguided2.png)
