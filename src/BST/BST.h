typedef struct node {
    int Data;
    char* Name;
    struct node* LChild, *RChild;
} NODE, *Nptr;

void Visit(char* name);

Nptr Create(int S[]);
void Destroy(Nptr &T);
void Delete(Nptr &T, int Key);
Nptr Insert(Nptr T, int key, const char* name);
Nptr Search(Nptr T, int key);

void PreOrder(Nptr T);
void InOrder(Nptr T);
void PostOrder(Nptr T);
