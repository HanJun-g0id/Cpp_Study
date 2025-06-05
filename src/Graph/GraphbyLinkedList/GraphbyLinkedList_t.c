#include <stdio.h>
#include <stdlib.h>
#include "GraphbyLinkedList.h"

int main() {
    int V = 4;
    graphPtr G = InitGraph(V);

    InsertEdge(G, 0, 1);
    InsertEdge(G, 0, 2);
    InsertEdge(G, 1, 2);
    InsertEdge(G, 2, 0);
    InsertEdge(G, 2, 3);
    InsertEdge(G, 3, 3);

    PrintGraph(G);

    return 0;
}
