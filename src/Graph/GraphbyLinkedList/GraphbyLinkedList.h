typedef struct node{
    int data;
    struct node* Next;
}node;
typedef node* Nptr;

typedef struct 
{
    int V;
    int E;
    node **L;
}graphType;
typedef graphType *graphPtr;

graphPtr InitGraph(int V);
void InsertEdge(graphPtr g, int V1, int V2);
void PrintGraph(graphPtr g);
