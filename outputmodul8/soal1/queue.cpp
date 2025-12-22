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
