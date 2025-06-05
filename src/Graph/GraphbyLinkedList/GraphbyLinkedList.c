#include "GraphbyLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

graphPtr InitGraph(int V)
{
    graphPtr G = malloc(sizeof(graphType));
    G->V = V;
    G->E = 0;
    G->L = malloc(V * sizeof(node *));
    for (int i = 0; i < V; i++) { G->L[i] = NULL; }
    return G;
}
void InsertEdge(graphPtr g, int V1, int V2)
{
    Nptr temp = malloc(sizeof(node));
    temp->data = V2;
    temp->Next = g->L[V1];
    g->L[V1] = temp;
}

void PrintGraph(graphPtr g) {
    for (int i = 0; i < g->V; i++) {
        printf("Vertex %d: ", i);
        Nptr temp = g->L[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->Next;
        }
        printf("NULL\n");
    }
}
