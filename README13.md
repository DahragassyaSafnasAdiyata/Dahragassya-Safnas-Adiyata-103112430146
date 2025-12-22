# <h1 align="center">Laporan Praktikum Modul 13 Multi Linked List <br> Stack</h1>
<p align="center">Dahragassya Safnas Adiyata - 103112430146</p>

## Dasar Teori
Multi Linked List adalah struktur data yang merupakan pengembangan dari linked list biasa, di mana setiap node memiliki lebih dari satu pointer untuk menghubungkan node tersebut ke beberapa node lain. Struktur ini memungkinkan satu data memiliki lebih dari satu relasi, sehingga sangat cocok digunakan untuk merepresentasikan hubungan yang kompleks seperti relasi many-to-many, contohnya hubungan antara mahasiswa dengan mata kuliah atau dosen dengan kelas. Dalam implementasinya menggunakan bahasa pemrograman C++, Multi Linked List dibangun dengan memanfaatkan struktur struct atau class yang berisi data serta beberapa pointer yang menunjuk ke node lain. Penggunaan pointer ini memungkinkan pengelolaan data secara dinamis di memori, sehingga penambahan, penghapusan, dan pencarian data dapat dilakukan secara fleksibel. Dengan kemampuan merepresentasikan lebih dari satu hubungan dalam satu struktur, Multi Linked List banyak digunakan pada sistem informasi dan aplikasi yang membutuhkan pemodelan relasi data yang kompleks.

## Guide

```go
#include <iostream>
#include <string>
using namespace std;

struct ChildNode
{
    string info;
    ChildNode *next;
};

struct ParentNode
{
    string info;
    ChildNode *childHead;
    ParentNode *next;
};

ParentNode *createParent(string info)
{
    ParentNode *newNode = new ParentNode;
    newNode->info = info;
    newNode->childHead = NULL;
    newNode->next = NULL;
    return newNode;
}

ChildNode *createChild(string info)
{
    ChildNode *newNode = new ChildNode;
    newNode->info = info;
    newNode->next = NULL;
    return newNode;
}

void insertParent(ParentNode *&head, string info)
{
    ParentNode *newNode = createParent(info);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        ParentNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertChild(ParentNode *head, string parentInfo, string childInfo)
{
    ParentNode *p = head;
    while (p != NULL && p->info != parentInfo)
    {
        p = p->next;
    }
    
    if (p != NULL)
    {
        ChildNode *newChild = createChild(childInfo);
        
        if (p->childHead == NULL)
        {
            p->childHead = newChild;
        }
        else
        {
            ChildNode *c = p->childHead;
            while (c->next != NULL)
            {
                c = c->next;
            }
            c->next = newChild;
        }
    }
}

void printAll(ParentNode *head)
{
    ParentNode *p = head;
    while (p != NULL)
    {
        cout << p->info;
        ChildNode *c = p->childHead;
        if (c != NULL)
        {
            while (c != NULL)
            {
                cout << " -> " << c->info;
                c = c->next;
            }
        }
     cout << endl;
        p = p->next;
    }
}

int main()
{
    ParentNode *list = NULL;
    
    insertParent(list, "Parent Node 1");
    insertParent(list, "Parent Node 2");
    
    printAll(list);
    cout << "\n";
    
    insertChild(list, "Parent Node 1", "Child Node A");
    insertChild(list, "Parent Node 1", "Child Node B");
    insertChild(list, "Parent Node 2", "Child Node C");
    
    printAll(list);
    
    return 0;
}
```
