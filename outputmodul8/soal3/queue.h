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
