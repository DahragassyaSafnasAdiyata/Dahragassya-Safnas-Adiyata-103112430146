#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);
    infotype x;
    char lanjut = 'y';

    while (lanjut == 'y' || lanjut == 'Y') {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        if (isExist(L, x.nopol)) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            cout << "masukkan warna kendaraan: ";
            cin >> x.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> x.thnBuat;

            address P = alokasi(x);
            insertLast(L, P);
        }

        cout << "Tambah data lagi? (y/n): ";
        cin >> lanjut;
    }

    cout << endl;
    printInfo(L);
    return 0;
}
