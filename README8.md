# <h1 align="center">Laporan Praktikum Modul 8 <br>QUEUE</h1>
<p align="center">Dahragassya Safnas Adiyata - 103112430146</p>

## Dasar Teori
Queue, atau antrian, adalah struktur data linear fundamental yang beroperasi berdasarkan prinsip FIFO (First-In, First-Out), di mana elemen yang pertama kali dimasukkan (melalui operasi Enqueue di bagian Rear/Tail) adalah yang pertama kali akan dikeluarkan (melalui operasi Dequeue di bagian Front/Head), persis seperti antrian di dunia nyata; implementasinya sering menggunakan array, linked list, atau circular array, dan sangat vital dalam aplikasi seperti penjadwalan proses pada sistem operasi dan algoritma pencarian Breadth-First Search (BFS).


## Guided

### Guided 1
```c++
#include <iostream>
using namespace std;

#define MAX 5 // ukuran maksimal queue

// Struktur Queue
struct Queue {
    int data[MAX];
    int head;
    int tail;
};

// Membuat antrean kosong
void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(Queue Q) {
    return (Q.tail == MAX - 1);
}

// Menampilkan isi antrian
void printQueue(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Queue : ";
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.data[i] << " ";
        }
        cout << endl;
    }
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh! Tidak bisa menambah data." << endl;
    } else {
        if (isEmpty(Q)) {
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.data[Q.tail] = x;
        cout << "Enqueue: " << x << endl;
    }
}

void dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong! Tidak ada data yang dihapus." << endl;
    } else {
        cout << "Dequeue: " << Q.data[Q.head] << endl;
        // Jika hanya 1 elemen
        if (Q.head == Q.tail) {
            Q.head = Q.tail = -1;
        } else {
            // Geser semua elemen ke kiri
            for (int i = Q.head; i < Q.tail; i++) {
                Q.data[i] = Q.data[i + 1];
            }
            Q.tail--;
        }
    }
}

int main() {
    Queue Q;
    enqueue(Q, 5);
    enqueue(Q, 2);
    enqueue(Q, 7);
    printQueue(Q);

    dequeue(Q);
    printQueue(Q);

    enqueue(Q, 4);
    enqueue(Q, 9);
    printQueue(Q);

    dequeue(Q);
    dequeue(Q);
    printQueue(Q);

    return 0;
}
```

> Output
> ![Screenshot bagian x](outputmodul10/Screenshot_unguided1.png)


Program di atas adalah implementasi struktur data **Queue** berbasis array dengan ukuran maksimal lima elemen, menggunakan konsep **FIFO**. Queue memiliki operasi utama yaitu `enqueue()` untuk menambah data di belakang antrian dan `dequeue()` untuk menghapus data dari depan, lengkap dengan pengecekan kondisi penuh dan kosong. Saat data dihapus, elemen-elemen digeser ke kiri untuk menjaga posisi antrian. Program `main()` menampilkan contoh penggunaan queue dengan beberapa proses penambahan, penghapusan, dan penampilan isi antrian untuk memperlihatkan cara kerja struktur data tersebut.


## UNGUIDED

### Soal 1


#### queue.h
```c++
#ifndef QUEUE_H
#define QUEUE_H

const int UKURAN_MAKSIMUM = 5;
typedef int TipeData;

struct Antrian {
    TipeData data[UKURAN_MAKSIMUM];
    int depan;
    int belakang;
};

void buatAntrian(Antrian &Q);

bool kosong(const Antrian &Q);
bool penuh(const Antrian &Q);

void tambahAntrian(Antrian &Q, TipeData nilai);
TipeData hapusAntrian(Antrian &Q);

void tampilkanAntrian(const Antrian &Q);

#endif


```
#### queue.cpp
```c++
#include "queue.h"
#include <iostream>
using namespace std;

void buatAntrian(Antrian &Q) {
    Q.depan = -1;
    Q.belakang = -1;
}

bool kosong(const Antrian &Q) {
    return Q.depan == -1;
}

bool penuh(const Antrian &Q) {
    return Q.belakang == UKURAN_MAKSIMUM - 1;
}

void tambahAntrian(Antrian &Q, TipeData nilai) {
    if (!penuh(Q)) {
        if (kosong(Q)) {
            Q.depan = 0;
        }
        Q.belakang++;
        Q.data[Q.belakang] = nilai;
    }
}

TipeData hapusAntrian(Antrian &Q) {
    TipeData hasil = -1;
    if (!kosong(Q)) {
        hasil = Q.data[Q.depan];
        if (Q.depan == Q.belakang) {
            Q.depan = -1;
            Q.belakang = -1;
        } else {
            Q.depan++;
        }
    }
    return hasil;
}

void tampilkanAntrian(const Antrian &Q) {
    if (!kosong(Q)) {
        for (int i = Q.depan; i <= Q.belakang; i++) {
            cout << Q.data[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Antrian kosong" << endl;
    }
}

```

#### main.cpp
```c++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    Antrian Q;
    buatAntrian(Q);

    tambahAntrian(Q, 10);
    tambahAntrian(Q, 20);
    tambahAntrian(Q, 30);

    tampilkanAntrian(Q);

    cout << "Data keluar: " << hapusAntrian(Q) << endl;

    tampilkanAntrian(Q);

    return 0;
}

```
> Output soal 1
> 
> ![Screenshot bagian x]()

Program ini merupakan implementasi struktur data Queue (antrian) menggunakan array dengan kapasitas tetap, dimana data dimasukkan melalui operasi enqueue dan dihapus menggunakan dequeue, mengikuti prinsip FIFO (First In First Out). Pada program ini terdapat tiga file, yaitu queue.h yang berfungsi sebagai header dan berisi deklarasi struktur dan fungsi, Queue.cpp berisi implementasi fungsi seperti pengecekan antrian penuh atau kosong, penambahan data, penghapusan data, dan penampilan isi queue, sedangkan main.cpp menyediakan menu interaktif untuk pengguna agar dapat mengakses operasi queue tersebut. Program menampilkan informasi setiap kali data ditambahkan atau dihapus, serta memastikan kondisi overflow dan underflow tidak terjadi dengan melakukan pengecekan sebelum operasi dijalankan. Dengan cara ini, pengguna dapat memahami cara kerja queue secara praktis melalui simulasi input dan output yang ditampilkan di layar.


### Soal 2

#### queue.cpp
```c++
#include "queue.h"
#include <iostream>
using namespace std;

void buatAntrian(Antrian &Q) {
    Q.depan = -1;
    Q.belakang = -1;
}

bool antrianKosong(const Antrian &Q) {
    return Q.depan == -1;
}

bool antrianPenuh(const Antrian &Q) {
    return Q.belakang == MAKS - 1;
}

void tambah(Antrian &Q, TipeInfo nilai) {
    if (!antrianPenuh(Q)) {
        if (antrianKosong(Q)) {
            Q.depan = 0;
        }
        Q.belakang++;
        Q.data[Q.belakang] = nilai;
    }
}

TipeInfo hapus(Antrian &Q) {
    TipeInfo hasil = -1;
    if (!antrianKosong(Q)) {
        hasil = Q.data[Q.depan];
        if (Q.depan == Q.belakang) {
            Q.depan = -1;
            Q.belakang = -1;
        } else {
            Q.depan++;
        }
    }
    return hasil;
}

void tampilkan(const Antrian &Q) {
    if (!antrianKosong(Q)) {
        for (int i = Q.depan; i <= Q.belakang; i++) {
            cout << Q.data[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Antrian kosong" << endl;
    }
}


```
#### queue.h
```c++
#ifndef QUEUE_H
#define QUEUE_H

const int MAKS = 5;
typedef int TipeInfo;

struct Antrian {
    TipeInfo data[MAKS];
    int depan;
    int belakang;
};

void buatAntrian(Antrian &Q);
bool antrianKosong(const Antrian &Q);
bool antrianPenuh(const Antrian &Q);
void tambah(Antrian &Q, TipeInfo nilai);
TipeInfo hapus(Antrian &Q);
void tampilkan(const Antrian &Q);

#endif

```

#### main.cpp
```c++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    Antrian Q;
    buatAntrian(Q);

    tambah(Q, 5);
    tambah(Q, 10);
    tambah(Q, 15);

    tampilkan(Q);

    cout << "Data keluar: " << hapus(Q) << endl;

    tampilkan(Q);

    return 0;
}


```

> Output soal 2
> 
> ![Screenshot bagian x]()

Program ini menggunakan struktur data stack (tumpukan) dengan konsep LIFO (Last In, First Out), di mana elemen terakhir yang dimasukkan akan keluar pertama. Variabel top digunakan untuk mengetahui posisi data teratas di stack. Fungsi initStack() menginisialisasi stack agar kosong, push() menambah data jika stack belum penuh, dan pop() mengambil data jika stack tidak kosong. Fungsi showStack() menampilkan isi stack, reverseStack() membalik urutannya, dan pushAscending() menambahkan data baru secara terurut naik dengan bantuan stack sementara.

### Soal 3
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
queue Alternatif 3 (head dan tail berputar).

#### queue.cpp
```c++
#include "queue.h"
#include <iostream>
using namespace std;

void buatAntrian(Antrian &Q) {
    Q.depan = -1;
    Q.belakang = -1;
}

bool kosong(const Antrian &Q) {
    return Q.depan == -1;
}

bool penuh(const Antrian &Q) {
    return (Q.belakang + 1) % MAKS == Q.depan;
}

void tambah(Antrian &Q, TipeData nilai) {
    if (penuh(Q)) {
        cout << "Antrian penuh" << endl;
        return;
    }

    if (kosong(Q)) {
        Q.depan = 0;
        Q.belakang = 0;
    } else {
        Q.belakang = (Q.belakang + 1) % MAKS;
    }

    Q.data[Q.belakang] = nilai;
}

TipeData hapus(Antrian &Q) {
    if (kosong(Q)) {
        cout << "Antrian kosong" << endl;
        return -1;
    }

    TipeData hasil = Q.data[Q.depan];

    if (Q.depan == Q.belakang) {
        buatAntrian(Q);
    } else {
        Q.depan = (Q.depan + 1) % MAKS;
    }

    return hasil;
}

void tampilkan(const Antrian &Q) {
    if (kosong(Q)) {
        cout << "Antrian kosong" << endl;
        return;
    }

    int i = Q.depan;
    while (true) {
        cout << Q.data[i] << " ";
        if (i == Q.belakang)
            break;
        i = (i + 1) % MAKS;
    }
    cout << endl;
}

```

#### main.cpp
```c++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    Antrian Q;
    buatAntrian(Q);

    tambah(Q, 10);
    tambah(Q, 20);
    tambah(Q, 30);
    tambah(Q, 40);
    tambah(Q, 50);

    tampilkan(Q);

    cout << "Data keluar: " << hapus(Q) << endl;
    cout << "Data keluar: " << hapus(Q) << endl;

    tampilkan(Q);

    tambah(Q, 60);
    tambah(Q, 70);

    tampilkan(Q);

    return 0;
}


```

#### queue.h
```c++
#ifndef QUEUE_H
#define QUEUE_H

const int MAKS = 5;
typedef int TipeData;

struct Antrian {
    TipeData data[MAKS];
    int depan;
    int belakang;
};

void buatAntrian(Antrian &Q);
bool kosong(const Antrian &Q);
bool penuh(const Antrian &Q);
void tambah(Antrian &Q, TipeData nilai);
TipeData hapus(Antrian &Q);
void tampilkan(const Antrian &Q);

#endif


```



> Output soal 3
> 
> ![Screenshot bagian x]()
> 
Kode ini adalah implementasi Circular Queue menggunakan array berkapasitas MAX_SIZE = 5. Fungsi initializeQueue() mengatur queue agar kosong dengan nilai front dan rear = -1. Fungsi isEmpty() mengecek apakah queue kosong, sedangkan isFull() mengecek apakah queue penuh menggunakan perhitungan circular (rear + 1) % MAX_SIZE == front. Fungsi enqueue() menambahkan data ke bagian belakang queue, dan dequeue() menghapus data dari bagian depan sesuai prinsip FIFO. Fungsi displayQueue() digunakan untuk menampilkan isi queue secara berurutan dengan logika indeks circular.
## Referensi




