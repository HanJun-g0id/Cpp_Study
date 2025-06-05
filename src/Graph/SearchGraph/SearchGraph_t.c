#include "SearchGraph.h"

int main() {
    int V = 5;
    graphPtr G = InitGraph(V);

    InsertEdge(G, 0, 1);
    InsertEdge(G, 0, 2);
    InsertEdge(G, 1, 2);
    InsertEdge(G, 2, 0);
    InsertEdge(G, 2, 3);
    InsertEdge(G, 3, 3);

    printf("Adjacency List:\n");
    PrintGraph(G);

    printf("BFS from vertex 2: ");
    BFS(G, 2);

    printf("DFS from vertex 2: ");
    DFS(G, 2);

    return 0;
}
