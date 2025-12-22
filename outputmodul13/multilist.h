#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
using namespace std;

#define NIL NULL
typedef bool boolean;

typedef int tipeInduk;
typedef int tipeAnak;

typedef struct ElemenInduk* alamatInduk;
typedef struct ElemenAnak* alamatAnak;

struct ElemenAnak {
    tipeAnak info;
    alamatAnak next;
    alamatAnak prev;
};

struct ListAnak {
    alamatAnak pertama;
    alamatAnak terakhir;
};

struct ElemenInduk {
    tipeInduk info;
    ListAnak daftarAnak;
    alamatInduk next;
    alamatInduk prev;
};

struct ListInduk {
    alamatInduk pertama;
    alamatInduk terakhir;
};

boolean kosongInduk(ListInduk L);
boolean kosongAnak(ListAnak L);

void buatListInduk(ListInduk &L);
void buatListAnak(ListAnak &L);

alamatInduk alokasiInduk(tipeInduk X);
alamatAnak alokasiAnak(tipeAnak X);
void dealokasiInduk(alamatInduk P);
void dealokasiAnak(alamatAnak P);

alamatInduk cariInduk(ListInduk L, tipeInduk X);
alamatAnak cariAnak(ListAnak L, tipeAnak X);

void tambahIndukTerakhir(ListInduk &L, alamatInduk P);
void tambahAnakTerakhir(ListAnak &L, alamatAnak P);

void hapusIndukTerakhir(ListInduk &L, alamatInduk &P);
void hapusAnakTerakhir(ListAnak &L, alamatAnak &P);

void tampilkanData(ListInduk L);

#endif
