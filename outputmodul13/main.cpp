#include "multilist.h"

int main() {
    ListInduk dataInduk;
    buatListInduk(dataInduk);

    alamatInduk I1 = alokasiInduk(1);
    alamatInduk I2 = alokasiInduk(2);

    tambahIndukTerakhir(dataInduk, I1);
    tambahIndukTerakhir(dataInduk, I2);

    alamatAnak A1 = alokasiAnak(10);
    alamatAnak A2 = alokasiAnak(20);
    alamatAnak A3 = alokasiAnak(30);

    tambahAnakTerakhir(I1->daftarAnak, A1);
    tambahAnakTerakhir(I1->daftarAnak, A2);
    tambahAnakTerakhir(I2->daftarAnak, A3);

    tampilkanData(dataInduk);

    return 0;
}
