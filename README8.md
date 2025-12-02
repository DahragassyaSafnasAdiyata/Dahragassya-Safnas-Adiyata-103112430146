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
> 

Program di atas adalah implementasi struktur data **Queue** berbasis array dengan ukuran maksimal lima elemen, menggunakan konsep **FIFO**. Queue memiliki operasi utama yaitu `enqueue()` untuk menambah data di belakang antrian dan `dequeue()` untuk menghapus data dari depan, lengkap dengan pengecekan kondisi penuh dan kosong. Saat data dihapus, elemen-elemen digeser ke kiri untuk menjaga posisi antrian. Program `main()` menampilkan contoh penggunaan queue dengan beberapa proses penambahan, penghapusan, dan penampilan isi antrian untuk memperlihatkan cara kerja struktur data tersebut.


## UNGUIDED

### Soal 1


#### queue.h
```c++
#ifndef QUEUE_H
#define QUEUE_H

const int MAX_SIZE = 5;
typedef int ElementType;

struct Queue {
    ElementType data[MAX_SIZE];
    int front, rear;
};

void initQueue(Queue &Q);

bool isEmpty(const Queue &Q);

bool isFull(const Queue &Q);

void enqueue(Queue &Q, ElementType value);

ElementType dequeue(Queue &Q);

void displayQueue(const Queue &Q);

#endif

```
#### queue.cpp
```c++
#include <iostream>
#include "queue.h"
using namespace std;

void initQueue(Queue &Q) {
    Q.front = -1;
    Q.rear = -1;
}

bool isEmpty(const Queue &Q) {
    return (Q.front == -1 && Q.rear == -1);
}

bool isFull(const Queue &Q) {
    return (Q.rear == MAX_SIZE - 1);
}

void enqueue(Queue &Q, ElementType value) {
    if (isFull(Q)) {
        cout << "Queue penuh! Tidak dapat menambahkan data." << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.front = 0;
    }

    Q.rear++;
    Q.data[Q.rear] = value;
    cout << value << " berhasil ditambahkan ke dalam queue." << endl;
}

ElementType dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong! Tidak ada data untuk dihapus." << endl;
        return -1;
    }

    ElementType removed = Q.data[Q.front];

    if (Q.front == Q.rear) {
        initQueue(Q); // queue kembali kosong
    } else {
        Q.front++;
    }

    cout << removed << " dihapus dari queue." << endl;
    return removed;
}

void displayQueue(const Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong." << endl;
        return;
    }

    cout << "Isi Queue: ";
    for (int i = Q.front; i <= Q.rear; i++) {
        cout << Q.data[i] << " ";
    }
    cout << endl;
}

```

#### main.cpp
```c++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue Q;
    initQueue(Q);

    int pilihan, nilai;

    do {
        cout << "\n=== MENU QUEUE ===" << endl;
        cout << "1. Enqueue (Tambah data)" << endl;
        cout << "2. Dequeue (Hapus data)" << endl;
        cout << "3. Tampilkan Queue" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                enqueue(Q, nilai);
                break;

            case 2:
                dequeue(Q);
                break;

            case 3:
                displayQueue(Q);
                break;

            case 4:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 4);

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
#include <iostream>
#include "queue.h"
using namespace std;

void initQueue(Queue &Q) {
    Q.front = -1;
    Q.rear = -1;
}

bool isEmpty(const Queue &Q) {
    return (Q.front == -1 && Q.rear == -1);
}

bool isFull(const Queue &Q) {
    return (Q.rear == MAX - 1);
}

void enqueue(Queue &Q, infotype value) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.front = Q.rear = 0;
    } else {
        Q.rear++;
    }

    Q.data[Q.rear] = value;
    cout << value << " berhasil dimasukkan ke queue." << endl;
}

infotype dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype removedValue = Q.data[Q.front];

    if (Q.front == Q.rear) {
        initQueue(Q);
    } else {
        Q.front++;
    }

    cout << removedValue << " dihapus dari queue." << endl;
    return removedValue;
}

void displayQueue(const Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong." << endl;
        return;
    }

    cout << "Isi Queue: ";
    for (int i = Q.front; i <= Q.rear; i++) {
        cout << Q.data[i] << " ";
    }
    cout << endl;
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
#include <iostream>
#include "queue.h"
using namespace std;

void initializeQueue(Queue &Q) {
    Q.front = -1;
    Q.rear = -1;
}

bool isEmpty(const Queue &Q) {
    return (Q.front == -1);
}

bool isFull(const Queue &Q) {
    return ((Q.rear + 1) % MAX_SIZE == Q.front);
}

void enqueue(Queue &Q, ElementType value) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.front = Q.rear = 0;
    } else {
        Q.rear = (Q.rear + 1) % MAX_SIZE;
    }

    Q.array[Q.rear] = value;
    cout << value << " berhasil dimasukkan ke queue." << endl;
}

ElementType dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    ElementType removedValue = Q.array[Q.front];

    if (Q.front == Q.rear) {
        initializeQueue(Q);
    } else {
        Q.front = (Q.front + 1) % MAX_SIZE;
    }

    cout << removedValue << " dihapus dari queue." << endl;
    return removedValue;
}

void displayQueue(const Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong." << endl;
        return;
    }

    cout << "Isi Queue: ";
    int index = Q.front;

    while (true) {
        cout << Q.array[index] << " ";
        if (index == Q.rear) break;
        index = (index + 1) % MAX_SIZE;
    }

    cout << endl;
}

```

> Output soal 3
> 
> ![Screenshot bagian x]()
> 
Kode ini adalah implementasi Circular Queue menggunakan array berkapasitas MAX_SIZE = 5. Fungsi initializeQueue() mengatur queue agar kosong dengan nilai front dan rear = -1. Fungsi isEmpty() mengecek apakah queue kosong, sedangkan isFull() mengecek apakah queue penuh menggunakan perhitungan circular (rear + 1) % MAX_SIZE == front. Fungsi enqueue() menambahkan data ke bagian belakang queue, dan dequeue() menghapus data dari bagian depan sesuai prinsip FIFO. Fungsi displayQueue() digunakan untuk menampilkan isi queue secara berurutan dengan logika indeks circular.
## Referensi




