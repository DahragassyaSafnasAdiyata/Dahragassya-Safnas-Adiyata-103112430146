#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node* kiri;
    Node* kanan;
} Node;

Node* buatNode(int x);
void insertBST(Node* &akar, int x);

void inorder(Node* akar);
void preorder(Node* akar);
void postorder(Node* akar);

int jumlahNode(Node* akar);
int totalNilai(Node* akar);
int tinggiPohon(Node* akar);

#endif