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
