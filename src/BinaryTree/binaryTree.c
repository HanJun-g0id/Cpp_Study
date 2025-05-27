#include <stdio.h>
#include <string.h>
#include "binaryTree.h"

void initTree(treeType tree) {
    for (int i = 0; i < MAXNODE; i++) {
        tree[i].Name[0] = '\0';
        tree[i].LChild = -1;
        tree[i].RChild = -1;
    }
}

int createNode(treeType tree, const char* name) {
    for (int i = 0; i < MAXNODE; i++) {
        if (tree[i].Name[0] == '\0') {
            strncpy(tree[i].Name, name, 19);
            tree[i].Name[19] = '\0';
            tree[i].LChild = -1;
            tree[i].RChild = -1;
            return i;
        }
    }
    return -1;
}

void setLeftChild(treeType tree, int parentIndex, int childIndex) {
    tree[parentIndex].LChild = childIndex;
}

void setRightChild(treeType tree, int parentIndex, int childIndex) {
    tree[parentIndex].RChild = childIndex;
}

void inorderTraversal(treeType tree, int rootIndex) {
    if (rootIndex == -1 || tree[rootIndex].Name[0] == '\0') return;

    inorderTraversal(tree, tree[rootIndex].LChild);
    printf("%s ", tree[rootIndex].Name);
    inorderTraversal(tree, tree[rootIndex].RChild);
}
