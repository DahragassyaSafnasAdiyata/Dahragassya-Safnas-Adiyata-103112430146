#include "circularlist.h"

void buatList(ListMelingkar &L) {
    L.pertama = NIL;
}

alamat alokasi(InfoMahasiswa x) {
    alamat P = new Elemen;
    P->info = x;
    P->next = NIL;
    return P;
}

void dealokasi(alamat P) {
    delete P;
}

void tambahAwal(ListMelingkar &L, alamat P) {
    if (L.pertama == NIL) {
        L.pertama = P;
        P->next = P;
    } else {
        alamat Q = L.pertama;
        while (Q->next != L.pertama) {
            Q = Q->next;
        }
        P->next = L.pertama;
        Q->next = P;
        L.pertama = P;
    }
}

void tambahAkhir(ListMelingkar &L, alamat P) {
    if (L.pertama == NIL) {
        L.pertama = P;
        P->next = P;
    } else {
        alamat Q = L.pertama;
        while (Q->next != L.pertama) {
            Q = Q->next;
        }
        Q->next = P;
        P->next = L.pertama;
    }
}

void tambahSetelah(ListMelingkar &L, alamat pendahulu, alamat P) {
    P->next = pendahulu->next;
    pendahulu->next = P;
}

void hapusAwal(ListMelingkar &L, alamat &P) {
    if (L.pertama != NIL) {
        alamat Q = L.pertama;
        while (Q->next != L.pertama) {
            Q = Q->next;
        }
        P = L.pertama;
        if (P->next == P) {
            L.pertama = NIL;
        } else {
            L.pertama = P->next;
            Q->next = L.pertama;
        }
        P->next = NIL;
    }
}

void hapusAkhir(ListMelingkar &L, alamat &P) {
    if (L.pertama != NIL) {
        alamat Q = L.pertama;
        alamat R = NIL;
        while (Q->next != L.pertama) {
            R = Q;
            Q = Q->next;
        }
        P = Q;
        if (R == NIL) {
            L.pertama = NIL;
        } else {
            R->next = L.pertama;
        }
        P->next = NIL;
    }
}

void hapusSetelah(ListMelingkar &L, alamat pendahulu, alamat &P) {
    P = pendahulu->next;
    pendahulu->next = P->next;
    P->next = NIL;
}

alamat cariData(ListMelingkar L, string nim) {
    if (L.pertama == NIL) return NIL;
    alamat P = L.pertama;
    do {
        if (P->info.nim == nim)
            return P;
        P = P->next;
    } while (P != L.pertama);
    return NIL;
}

void tampilkanData(ListMelingkar L) {
    if (L.pertama != NIL) {
        alamat P = L.pertama;
        do {
            cout << "Nama : " << P->info.nama << endl;
            cout << "NIM  : " << P->info.nim << endl;
            cout << "JK   : " << P->info.jenisKelamin << endl;
            cout << "IPK  : " << P->info.ipk << endl;
            cout << endl;
            P = P->next;
        } while (P != L.pertama);
    }
}
