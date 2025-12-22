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
