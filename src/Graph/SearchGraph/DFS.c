#include "SearchGraph.h"
#include <stdbool.h>

void DFSUtil(graphPtr G, int v, bool *visited) {
    visited[v] = true;
    printf("%d ", v);

    for (Nptr temp = G->L[v]; temp != NULL; temp = temp->Next) {
        int adj = temp->data;
        if (!visited[adj])
            DFSUtil(G, adj, visited);
    }
}

void DFS(graphPtr G, int start) {
    bool *visited = calloc(G->V, sizeof(bool));
    DFSUtil(G, start, visited);
    printf("\n");
    free(visited);
}
