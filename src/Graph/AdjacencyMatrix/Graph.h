#define MAX_VERTICES 50

typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void init(GraphType* g);
void insert_vertex(GraphType* g, int v);
void insert_edge(GraphType* g, int start, int end);
void print_adj_mat(GraphType* g);
