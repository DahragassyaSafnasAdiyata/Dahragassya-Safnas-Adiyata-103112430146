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
