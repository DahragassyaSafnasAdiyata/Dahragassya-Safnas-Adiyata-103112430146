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
