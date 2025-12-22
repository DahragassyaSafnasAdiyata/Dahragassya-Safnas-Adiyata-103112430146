#include "bstree.h"

Node* buatNode(int x) {
    Node* baru = new Node;
    baru->data = x;
    baru->kiri = NULL;
    baru->kanan = NULL;
    return baru;
}

void insertBST(Node* &akar, int x) {
    if (akar == NULL) {
        akar = buatNode(x);
    } else if (x < akar->data) {
        insertBST(akar->kiri, x);
    } else if (x > akar->data) {
        insertBST(akar->kanan, x);
    }
}

void inorder(Node* akar) {
    if (akar != NULL) {
        inorder(akar->kiri);
        cout << akar->data << " ";
        inorder(akar->kanan);
    }
}

void preorder(Node* akar) {
    if (akar != NULL) {
        cout << akar->data << " ";
        preorder(akar->kiri);
        preorder(akar->kanan);
    }
}

void postorder(Node* akar) {
    if (akar != NULL) {
        postorder(akar->kiri);
        postorder(akar->kanan);
        cout << akar->data << " ";
    }
}

int jumlahNode(Node* akar) {
    if (akar == NULL)
        return 0;
    return 1 + jumlahNode(akar->kiri) + jumlahNode(akar->kanan);
}

int totalNilai(Node* akar) {
    if (akar == NULL)
        return 0;
    return akar->data + totalNilai(akar->kiri) + totalNilai(akar->kanan);
}

int tinggiPohon(Node* akar) {
    if (akar == NULL)
        return 0;

    int kiri = tinggiPohon(akar->kiri);
    int kanan = tinggiPohon(akar->kanan);

    return (kiri > kanan) ? kiri + 1 : kanan + 1;
}