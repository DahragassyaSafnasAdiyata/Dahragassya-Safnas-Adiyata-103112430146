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
