#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    Node* akar = NULL;

    
    insertBST(akar, 1);
    insertBST(akar, 2);
    insertBST(akar, 6);
    insertBST(akar, 4);
    insertBST(akar, 5);
    insertBST(akar, 3);
    insertBST(akar, 6); 
    insertBST(akar, 7);

 
    cout << "=== HASIL SOAL 1 ===" << endl;
    inorder(akar);
    cout << endl;

  
    cout << "\n=== HASIL SOAL 2 ===" << endl;
    inorder(akar);
    cout << endl;
    cout << "Tinggi Pohon   : " << tinggiPohon(akar) << endl;
    cout << "Jumlah Node    : " << jumlahNode(akar) << endl;
    cout << "Total Nilai    : " << totalNilai(akar) << endl;

   
    cout << "\n=== HASIL SOAL 3 ===" << endl;
    cout << "Preorder   : ";
    preorder(akar);
    cout << endl;

    cout << "Postorder  : ";
    postorder(akar);
    cout << endl;

    return 0;
}