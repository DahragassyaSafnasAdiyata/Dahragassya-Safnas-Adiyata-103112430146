#include <iostream>
#include <string>
using namespace std;


struct Node {
    string nama;
    string pesanan;
    Node *next;
};

Node *front = nullptr;
Node *rear = nullptr;

bool isEmpty() {
    return front == nullptr;
}


void tambahAntrian(string nama, string pesanan) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->pesanan = pesanan;
    baru->next = nullptr;

    if (isEmpty()) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }
    cout << "Pembeli berhasil ditambahkan ke antrian.\n";
}


void layaniAntrian() {
    if (isEmpty()) {
        cout << "Belum ada pembeli di antrian.\n";
        return;
    }

    Node *hapus = front;
    cout << "\nSedang melayani pesanan...\n";
    cout << "Nama   : " << hapus->nama << endl;
    cout << "Pesanan: " << hapus->pesanan << endl;

    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }

    delete hapus;
    cout << "Pesanan telah selesai dilayani.\n";
}


void tampilAntrian() {
    if (isEmpty()) {
        cout << "Tidak ada pembeli dalam antrian.\n";
        return;
    }

    cout << "\nDaftar Antrian Pembeli:\n";
    cout << "------------------------------\n";
    Node *temp = front;
    int nomor = 1;
    while (temp != nullptr) {
        cout << nomor << ". Nama   : " << temp->nama << endl;
        cout << "   Pesanan: " << temp->pesanan << endl;
        cout << "------------------------------\n";
        temp = temp->next;
        nomor++;
    }
}


void cariPembeli(string namaCari) {
    if (isEmpty()) {
        cout << "Antrian kosong! Tidak ada data untuk dicari.\n";
        return;
    }

    Node *temp = front;
    int posisi = 1;
    bool ditemukan = false;

    while (temp != nullptr) {
        if (temp->nama == namaCari) {
            cout << "\nData Pembeli Ditemukan!\n";
            cout << "Posisi dalam antrian: " << posisi << endl;
            cout << "Nama   : " << temp->nama << endl;
            cout << "Pesanan: " << temp->pesanan << endl;
            cout << "------------------------------\n";
            ditemukan = true;
            break;
        }
        temp = temp->next;
        posisi++;
    }

    if (!ditemukan) {
        cout << "Pembeli dengan nama \"" << namaCari 
             << "\" tidak ditemukan dalam antrian.\n";
    }
}


int main() {
    int pilihan;
    string nama, pesanan;

    do {
        cout << "==============================\n";
        cout << "   SISTEM ANTRIAN KAFE MINI   \n";
        cout << "==============================\n";
        cout << "1. Tambahkan Pembeli\n";
        cout << "2. Layani Pembeli\n";
        cout << "3. Lihat Daftar Antrian\n";
        cout << "4. Cari Nama Pembeli\n";
        cout << "5. Keluar Program\n";
        cout << "==============================\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        cin.ignore(); 

        switch (pilihan) {
            case 1:
                cout << "\nMasukkan nama pembeli   : ";
                getline(cin, nama);
                cout << "Masukkan pesanan        : ";
                getline(cin, pesanan);
                tambahAntrian(nama, pesanan);
                break;

            case 2:
                layaniAntrian();
                break;

            case 3:
                tampilAntrian();
                break;

            case 4:
                cout << "\nMasukkan nama pembeli yang ingin dicari: ";
                getline(cin, nama);
                cariPembeli(nama);
                break;

            case 5:
                cout << "Terima kasih! Program antrian ditutup.\n";
                break;

            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }

        cout << endl;
    } while (pilihan != 5);

    return 0;
}
