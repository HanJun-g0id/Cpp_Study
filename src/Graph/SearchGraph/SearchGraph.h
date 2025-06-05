#ifndef GRAPHBYLINKEDLIST_H
#define GRAPHBYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* Next;
} node;
typedef node* Nptr;

typedef struct {
    int V;
    int E;
    Nptr* L;
} graphType;
typedef graphType* graphPtr;

graphPtr InitGraph(int V);
void InsertEdge(graphPtr g, int V1, int V2);
void PrintGraph(graphPtr G);

void BFS(graphPtr G, int start);
void DFS(graphPtr G, int start);

#endif
