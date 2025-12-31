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
