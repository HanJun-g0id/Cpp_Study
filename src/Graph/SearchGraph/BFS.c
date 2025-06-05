#include <stdbool.h>
#include "SearchGraph.h"

void BFS(graphPtr G, int start) {
    bool *visited = calloc(G->V, sizeof(bool));
    int *queue = malloc(G->V * sizeof(int));
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (Nptr temp = G->L[v]; temp != NULL; temp = temp->Next) {
            int adj = temp->data;
            if (!visited[adj]) {
                visited[adj] = true;
                queue[rear++] = adj;
            }
        }
    }
    printf("\n");
    free(visited);
    free(queue);
}
