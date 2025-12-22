#include "circularlist.h"

int main() {
    ListMelingkar L;
    buatList(L);

    InfoMahasiswa m1 = {"Andi", "123", 'L', 3.75};
    InfoMahasiswa m2 = {"Budi", "456", 'L', 3.60};
    InfoMahasiswa m3 = {"Citra", "789", 'P', 3.90};

    alamat P1 = alokasi(m1);
    alamat P2 = alokasi(m2);
    alamat P3 = alokasi(m3);

    tambahAwal(L, P1);
    tambahAkhir(L, P2);
    tambahAkhir(L, P3);

    tampilkanData(L);

    return 0;
}
