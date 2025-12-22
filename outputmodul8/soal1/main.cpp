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
