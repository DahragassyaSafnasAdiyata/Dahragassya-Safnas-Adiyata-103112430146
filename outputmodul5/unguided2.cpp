#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string isbn;
    string judul;
    string penulis;
    Buku* next;
};

Buku* head = nullptr;

void tambahBuku(string isbn, string judul, string penulis) {
    Buku* baru = new Buku;
    baru->isbn = isbn;
    baru->judul = judul;
    baru->penulis = penulis;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Buku* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = baru;
    }

    cout << "Buku berhasil disimpan ke dalam daftar.\n";
}

void tampilBuku() {
    if (head == nullptr) {
        cout << "Belum ada data buku yang tersimpan.\n";
        return;
    }

    cout << "\nDaftar Buku Tersedia:\n";
    cout << "-------------------------------------\n";
    Buku* temp = head;
    int nomor = 1;

    while (temp != nullptr) {
        cout << nomor++ << ". ISBN    : " << temp->isbn << endl;
        cout << "   Judul   : " << temp->judul << endl;
        cout << "   Penulis : " << temp->penulis << endl;
        cout << "-------------------------------------\n";
        temp = temp->next;
    }
}

void hapusBuku(string isbn) {
    if (head == nullptr) {
        cout << "Daftar buku kosong.\n";
        return;
    }

    Buku* temp = head;
    Buku* prev = nullptr;

    while (temp != nullptr && temp->isbn != isbn) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Buku dengan ISBN \"" << isbn << "\" tidak ditemukan.\n";
        return;
    }

    if (prev == nullptr)
        head = head->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Data buku berhasil dihapus dari daftar.\n";
}

void perbaruiBuku(string isbn) {
    if (head == nullptr) {
        cout << "Daftar buku masih kosong.\n";
        return;
    }

    Buku* temp = head;
    while (temp != nullptr && temp->isbn != isbn)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Buku dengan ISBN \"" << isbn << "\" tidak ditemukan.\n";
        return;
    }

    cout << "\nPerbarui data buku:\n";
    cout << "Masukkan judul baru   : ";
    getline(cin, temp->judul);
    cout << "Masukkan penulis baru : ";
    getline(cin, temp->penulis);

    cout << "Data buku berhasil diperbarui.\n";
}

void cariByISBN(string isbn) {
    Buku* temp = head;
    bool ditemukan = false;

    while (temp != nullptr) {
        if (temp->isbn == isbn) {
            cout << "\nBuku ditemukan:\n";
            cout << "ISBN    : " << temp->isbn << endl;
            cout << "Judul   : " << temp->judul << endl;
            cout << "Penulis : " << temp->penulis << endl;
            cout << "-------------------------------------\n";
            ditemukan = true;
            break;
        }
        temp = temp->next;
    }

    if (!ditemukan)
        cout << "Tidak ada buku dengan ISBN \"" << isbn << "\".\n";
}

void cariByJudul(string judul) {
    Buku* temp = head;
    bool ditemukan = false;

    while (temp != nullptr) {
        if (temp->judul == judul) {
            if (!ditemukan)
                cout << "\nBuku dengan judul \"" << judul << "\" ditemukan:\n";
            cout << "ISBN    : " << temp->isbn << endl;
            cout << "Penulis : " << temp->penulis << endl;
            cout << "-------------------------------------\n";
            ditemukan = true;
        }
        temp = temp->next;
    }

    if (!ditemukan)
        cout << "Buku berjudul \"" << judul << "\" tidak ditemukan.\n";
}

void cariByPenulis(string penulis) {
    Buku* temp = head;
    bool ditemukan = false;

    while (temp != nullptr) {
        if (temp->penulis == penulis) {
            if (!ditemukan)
                cout << "\nBuku karya \"" << penulis << "\" ditemukan:\n";
            cout << "ISBN  : " << temp->isbn << endl;
            cout << "Judul : " << temp->judul << endl;
            cout << "-------------------------------------\n";
            ditemukan = true;
        }
        temp = temp->next;
    }

    if (!ditemukan)
        cout << "Tidak ditemukan buku karya \"" << penulis << "\".\n";
}


int main() {
    int pilihan;
    string isbn, judul, penulis;

    do {
        cout << "\n==============================================\n";
        cout << "   SISTEM MANAJEMEN DATA BUKU (Linked List)\n";
        cout << "==============================================\n";
        cout << "1. Tambah Buku Baru\n";
        cout << "2. Hapus Buku\n";
        cout << "3. Perbarui Data Buku\n";
        cout << "4. Lihat Semua Buku\n";
        cout << "5. Cari Buku Berdasarkan ISBN\n";
        cout << "6. Cari Buku Berdasarkan Judul\n";
        cout << "7. Cari Buku Berdasarkan Penulis\n";
        cout << "8. Keluar Program\n";
        cout << "----------------------------------------------\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "\nTambah Buku Baru\n";
                cout << "Masukkan ISBN     : ";
                getline(cin, isbn);
                cout << "Masukkan Judul    : ";
                getline(cin, judul);
                cout << "Masukkan Penulis  : ";
                getline(cin, penulis);
                tambahBuku(isbn, judul, penulis);
                break;

            case 2:
                cout << "\nHapus Buku\n";
                cout << "Masukkan ISBN yang ingin dihapus: ";
                getline(cin, isbn);
                hapusBuku(isbn);
                break;

            case 3:
                cout << "\nPerbarui Data Buku\n";
                cout << "Masukkan ISBN buku yang ingin diperbarui: ";
                getline(cin, isbn);
                perbaruiBuku(isbn);
                break;

            case 4:
                tampilBuku();
                break;

            case 5:
                cout << "\nCari Buku Berdasarkan ISBN\n";
                cout << "Masukkan ISBN: ";
                getline(cin, isbn);
                cariByISBN(isbn);
                break;

            case 6:
                cout << "\nCari Buku Berdasarkan Judul\n";
                cout << "Masukkan Judul: ";
                getline(cin, judul);
                cariByJudul(judul);
                break;

            case 7:
                cout << "\nCari Buku Berdasarkan Penulis\n";
                cout << "Masukkan Nama Penulis: ";
                getline(cin, penulis);
                cariByPenulis(penulis);
                break;

            case 8:
                cout << "\nTerima kasih. Program ditutup.\n";
                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (pilihan != 8);

    return 0;
}
