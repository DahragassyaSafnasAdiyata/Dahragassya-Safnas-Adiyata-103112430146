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
