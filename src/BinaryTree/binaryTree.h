#define MAXNODE 100

typedef struct {
    char Name[20];
    int LChild;
    int RChild;
} node;

typedef node treeType[MAXNODE];

void initTree(treeType tree);
int createNode(treeType tree, const char* name);
void setLeftChild(treeType tree, int parentIndex, int childIndex);
void setRightChild(treeType tree, int parentIndex, int childIndex);
void inorderTraversal(treeType tree, int rootIndex);
