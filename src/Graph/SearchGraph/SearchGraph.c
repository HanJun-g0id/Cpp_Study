#include "SearchGraph.h"

graphPtr InitGraph(int V) {
    graphPtr G = malloc(sizeof(graphType));
    G->V = V;
    G->E = 0;
    G->L = malloc(V * sizeof(node *));
    for (int i = 0; i < V; i++) { G->L[i] = NULL; }
    return G;
}

void InsertEdge(graphPtr g, int V1, int V2) {
    Nptr temp = malloc(sizeof(node));
    temp->data = V2;
    temp->Next = g->L[V1];
    g->L[V1] = temp;
    g->E++;
}

void PrintGraph(graphPtr G) {
    for (int i = 0; i < G->V; i++) {
        printf("Vertex %d: ", i);
        Nptr temp = G->L[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->Next;
        }
        printf("NULL\n");
    }
}
