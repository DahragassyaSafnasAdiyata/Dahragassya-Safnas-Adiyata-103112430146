#include "multilist.h"

boolean kosongInduk(ListInduk L) {
    return L.pertama == NIL;
}

boolean kosongAnak(ListAnak L) {
    return L.pertama == NIL;
}

void buatListInduk(ListInduk &L) {
    L.pertama = NIL;
    L.terakhir = NIL;
}

void buatListAnak(ListAnak &L) {
    L.pertama = NIL;
    L.terakhir = NIL;
}

alamatInduk alokasiInduk(tipeInduk X) {
    alamatInduk P = new ElemenInduk;
    P->info = X;
    buatListAnak(P->daftarAnak);
    P->next = NIL;
    P->prev = NIL;
    return P;
}

alamatAnak alokasiAnak(tipeAnak X) {
    alamatAnak P = new ElemenAnak;
    P->info = X;
    P->next = NIL;
    P->prev = NIL;
    return P;
}

void dealokasiInduk(alamatInduk P) {
    delete P;
}

void dealokasiAnak(alamatAnak P) {
    delete P;
}

alamatInduk cariInduk(ListInduk L, tipeInduk X) {
    alamatInduk P = L.pertama;
    while (P != NIL) {
        if (P->info == X)
            return P;
        P = P->next;
    }
    return NIL;
}

alamatAnak cariAnak(ListAnak L, tipeAnak X) {
    alamatAnak P = L.pertama;
    while (P != NIL) {
        if (P->info == X)
            return P;
        P = P->next;
    }
    return NIL;
}

void tambahIndukTerakhir(ListInduk &L, alamatInduk P) {
    if (kosongInduk(L)) {
        L.pertama = P;
        L.terakhir = P;
    } else {
        L.terakhir->next = P;
        P->prev = L.terakhir;
        L.terakhir = P;
    }
}

void tambahAnakTerakhir(ListAnak &L, alamatAnak P) {
    if (kosongAnak(L)) {
        L.pertama = P;
        L.terakhir = P;
    } else {
        L.terakhir->next = P;
        P->prev = L.terakhir;
        L.terakhir = P;
    }
}

void hapusIndukTerakhir(ListInduk &L, alamatInduk &P) {
    if (!kosongInduk(L)) {
        P = L.terakhir;
        if (L.pertama == L.terakhir) {
            L.pertama = NIL;
            L.terakhir = NIL;
        } else {
            L.terakhir = P->prev;
            L.terakhir->next = NIL;
            P->prev = NIL;
        }
    }
}

void hapusAnakTerakhir(ListAnak &L, alamatAnak &P) {
    if (!kosongAnak(L)) {
        P = L.terakhir;
        if (L.pertama == L.terakhir) {
            L.pertama = NIL;
            L.terakhir = NIL;
        } else {
            L.terakhir = P->prev;
            L.terakhir->next = NIL;
            P->prev = NIL;
        }
    }
}

void tampilkanData(ListInduk L) {
    alamatInduk P = L.pertama;
    while (P != NIL) {
        cout << "Data Induk : " << P->info << endl;
        alamatAnak A = P->daftarAnak.pertama;
        while (A != NIL) {
            cout << "  Data Anak : " << A->info << endl;
            A = A->next;
        }
        P = P->next;
    }
}
