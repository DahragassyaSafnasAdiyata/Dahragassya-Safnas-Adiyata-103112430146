#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <iostream>
using namespace std;

#define NIL NULL

typedef struct {
    string nama;
    string nim;
    char jenisKelamin;
    float ipk;
} InfoMahasiswa;

typedef struct Elemen* alamat;

struct Elemen {
    InfoMahasiswa info;
    alamat next;
};

struct ListMelingkar {
    alamat pertama;
};

void buatList(ListMelingkar &L);
alamat alokasi(InfoMahasiswa x);
void dealokasi(alamat P);

void tambahAwal(ListMelingkar &L, alamat P);
void tambahSetelah(ListMelingkar &L, alamat pendahulu, alamat P);
void tambahAkhir(ListMelingkar &L, alamat P);

void hapusAwal(ListMelingkar &L, alamat &P);
void hapusSetelah(ListMelingkar &L, alamat pendahulu, alamat &P);
void hapusAkhir(ListMelingkar &L, alamat &P);

alamat cariData(ListMelingkar L, string nim);
void tampilkanData(ListMelingkar L);

#endif
