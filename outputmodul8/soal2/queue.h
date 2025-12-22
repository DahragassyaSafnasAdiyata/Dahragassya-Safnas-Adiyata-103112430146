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
