# <h1 align="center">Laporan Praktikum Modul 14 Multi Linked List <br> Stack</h1>
<p align="center">Dahragassya Safnas Adiyata - 103112430146</p>

## Dasar Teori
Graph merupakan struktur data yang digunakan untuk merepresentasikan hubungan antar simpul (vertex) yang dihubungkan oleh sisi (edge), dan umumnya diimplementasikan menggunakan adjacency list atau adjacency matrix. Adjacency list biasanya direpresentasikan dengan vector<int> atau vector<pair<int,int>> untuk graf berbobot, sedangkan adjacency matrix menggunakan array dua dimensi. C++ menyediakan STL seperti vector, queue, dan stack yang sangat membantu dalam pengolahan graf, terutama untuk algoritma penelusuran seperti Breadth First Search (BFS) dan Depth First Search (DFS). Pada graf berarah, setiap sisi memiliki arah tertentu, sedangkan pada graf tidak berarah sisi bersifat dua arah. Graf dalam C++ banyak digunakan untuk menyelesaikan permasalahan seperti pencarian jalur terpendek, analisis jaringan, dan pemodelan hubungan data, sehingga pemahaman struktur dan implementasi graf menjadi penting dalam pengembangan program berbasis algoritma.

## Guided
#### graf.h
```c++
#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED

#include <iostream>
using namespace std;

typedef char infoGraph;

struct ElmNode;
struct ElmEdge;

typedef ElmNode *adrNode;
typedef ElmEdge *adrEdge;

struct ElmNode
{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge
{
    adrNode node;
    adrEdge next;
};

struct Graph
{
    adrNode first;
};

// PRIMITIF GRAPH
void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph X);
adrEdge AllocateEdge(adrNode N);

void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);

void ConnectNode(Graph &G, infoGraph A, infoGraph B);

void PrintInfoGraph(Graph G);

// Traversal
void ResetVisited(Graph &G);
void PrintDFS(Graph &G, adrNode N);
void PrintBFS(Graph &G, adrNode N);

#endif
```
#### graf.cpp
```c++
#include "graf.h"
#include <queue>
#include <stack>

void CreateGraph(Graph &G)
{
    G.first = NULL;
}

adrNode AllocateNode(infoGraph X)
{
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

adrEdge AllocateEdge(adrNode N)
{
    adrEdge P = new ElmEdge;
    P->node = N;
    P->next = NULL;
    return P;
}

void InsertNode(Graph &G, infoGraph X)
{
    adrNode P = AllocateNode(X);
    P->next = G.first;
    G.first = P;
}

adrNode FindNode(Graph G, infoGraph X)
{
    adrNode P = G.first;
    while (P != NULL)
    {
        if (P->info == X)
            return P;
        P = P->next;
    }
    return NULL;
}

void ConnectNode(Graph &G, infoGraph A, infoGraph B)
{
    adrNode N1 = FindNode(G, A);
    adrNode N2 = FindNode(G, B);

    if (N1 == NULL || N2 == NULL)
    {
        cout << "Node tidak ditemukan!\n";
        return;
    }

    // Buat edge dari N1 ke N2
    adrEdge E1 = AllocateEdge(N2);
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    // Karena undirected → buat edge balik
    adrEdge E2 = AllocateEdge(N1);
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G)
{
    adrNode P = G.first;
    while (P != NULL)
    {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL)
        {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void ResetVisited(Graph &G)
{
    adrNode P = G.first;
    while (P != NULL)
    {
        P->visited = 0;
        P = P->next;
    }
}

void PrintDFS(Graph &G, adrNode N)
{
    if (N == NULL)
        return;

    N->visited = 1;
    cout << N->info << " ";

    adrEdge E = N->firstEdge;
    while (E != NULL)
    {
        if (E->node->visited == 0)
        {
            PrintDFS(G, E->node);
        }
        E = E->next;
    }
}

void PrintBFS(Graph &G, adrNode N)
{
    if (N == NULL)
        return;

    queue<adrNode> Q;
    Q.push(N);

    while (!Q.empty())
    {
        adrNode curr = Q.front();
        Q.pop();

        if (curr->visited == 0)
        {
            curr->visited = 1;
            cout << curr->info << " ";

            adrEdge E = curr->firstEdge;
            while (E != NULL)
            {
                if (E->node->visited == 0)
                {
                    Q.push(E->node);
                }
                E = E->next;
            }
        }
    }
}

```
#### main.cpp
```c++
#include "graf.h"
#include "graf.cpp"
#include <iostream>
using namespace std;

int main()
{
    Graph G;
    CreateGraph(G);

    // Tambah node
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');

    // Hubungkan node (graph tidak berarah)
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'C', 'E');

    cout << "=== Struktur Graph ===\n";
    PrintInfoGraph(G);

    cout << "\n=== DFS dari Node A ===\n";
    ResetVisited(G);
    PrintDFS(G, FindNode(G, 'A'));

    cout << "\n\n=== BFS dari Node A ===\n";
    ResetVisited(G);
    PrintBFS(G, FindNode(G, 'A'));

    cout << endl;
    return 0;
}

```

## UNGUIDED 1,2,3


#### code
#### graph.h
```c++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;

struct ElmNode;
struct ElmEdge;

typedef ElmNode* adrNode;
typedef ElmEdge* adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

/* Basic Operation */
void CreateGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(Graph &G, infoGraph X1, infoGraph X2);

/* Utility */
void ResetVisited(Graph &G);
void PrintGraph(Graph G);

/* Traversal */
void PrintDFS(Graph &G, infoGraph start);
void PrintBFS(Graph &G, infoGraph start);

#endif

```
#### graph.cpp
```c++
#include "graph.h"
#include <queue>

/* ================= BASIC ================= */

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X)
            return P;
        P = P->next;
    }
    return NULL;
}

adrNode InsertNode(Graph &G, infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL)
            Q = Q->next;
        Q->next = P;
    }
    return P;
}

void ConnectNode(Graph &G, infoGraph X1, infoGraph X2) {
    adrNode N1 = FindNode(G, X1);
    adrNode N2 = FindNode(G, X2);

    if (N1 == NULL || N2 == NULL)
        return;

    // Edge N1 -> N2
    adrEdge E1 = new ElmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    // Edge N2 -> N1 (undirected)
    adrEdge E2 = new ElmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

/* ================= UTILITY ================= */

void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = false;
        P = P->next;
    }
}

void PrintGraph(Graph G) {
    adrNode P = G.first;
    cout << "Graph Representation\n";
    while (P != NULL) {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

/* ================= DFS ================= */

void DFS(adrNode N) {
    if (N == NULL || N->visited)
        return;

    cout << N->info << " ";
    N->visited = true;

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        DFS(E->node);
        E = E->next;
    }
}

void PrintDFS(Graph &G, infoGraph start) {
    ResetVisited(G);
    adrNode N = FindNode(G, start);

    if (N != NULL) {
        cout << "DFS from " << start << " : ";
        DFS(N);
        cout << endl;
    }
}

/* ================= BFS ================= */

void PrintBFS(Graph &G, infoGraph start) {
    ResetVisited(G);
    adrNode N = FindNode(G, start);

    if (N == NULL)
        return;

    cout << "BFS from " << start << " : ";

    queue<adrNode> Q;
    Q.push(N);
    N->visited = true;

    while (!Q.empty()) {
        adrNode cur = Q.front();
        Q.pop();

        cout << cur->info << " ";

        adrEdge E = cur->firstEdge;
        while (E != NULL) {
            if (!E->node->visited) {
                E->node->visited = true;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
    cout << endl;
}

```
#### main.cpp
```c++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'C', 'G');
    ConnectNode(G, 'E', 'F');

    PrintGraph(G);

    PrintDFS(G, 'A');
    PrintBFS(G, 'A');

    PrintDFS(G, 'D');
    PrintBFS(G, 'C');

    return 0;
}

```
> Output
> ![Screenshot bagian x](outputmodul14/Screenshot_unguided123.png)

Program ini mengimplementasikan struktur data graf berarah menggunakan adjacency list berbasis pointer dalam bahasa C++. Setiap simpul (node) direpresentasikan oleh struktur ElmNode yang menyimpan informasi berupa karakter (infoGraph), penanda kunjungan (visited), pointer ke sisi pertama (firstEdge), dan pointer ke simpul berikutnya. Setiap sisi (edge) direpresentasikan oleh struktur ElmEdge yang menunjuk ke simpul tujuan dan ke sisi berikutnya. Struktur Graph menyimpan pointer ke simpul pertama sebagai awal graf.
