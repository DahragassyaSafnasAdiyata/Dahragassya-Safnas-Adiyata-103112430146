#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarNilai(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void tukarPosisi(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int ArrayA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int ArrayB[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    cout << "Array A sebelum ditukar:\n";
    tampilArray(ArrayA);
    cout << "\nArray B sebelum ditukar:\n";
    tampilArray(ArrayB);

    tukarPosisi(ArrayA, ArrayB, 1, 1);

    cout << "\nSetelah menukar elemen pada posisi [1][1]:\n";
    cout << "Array A:\n";
    tampilArray(ArrayA);
    cout << "\nArray B:\n";
    tampilArray(ArrayB);

    int nilaiX = 50, nilaiY = 100;
    int *ptr1 = &nilaiX;
    int *ptr2 = &nilaiY;

    cout << "\nNilai sebelum ditukar melalui pointer:\n";
    cout << "nilaiX = " << nilaiX << ", nilaiY = " << nilaiY << endl;

    tukarPointer(ptr1, ptr2);

    cout << "Nilai setelah ditukar melalui pointer:\n";
    cout << "nilaiX = " << nilaiX << ", nilaiY = " << nilaiY << endl;

    return 0;
}