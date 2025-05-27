#include <stdio.h>
#include "binaryTree.h"

int main() {
    treeType tree;
    initTree(tree);

    int park = createNode(tree, "Park");
    int kim = createNode(tree, "Kim");
    int seo = createNode(tree, "Seo");
    int lee = createNode(tree, "Lee");
    int cho = createNode(tree, "Cho");

    setLeftChild(tree, park, kim);
    setRightChild(tree, park, seo);
    setLeftChild(tree, kim, lee);
    setRightChild(tree, seo, cho);

    printf("중위 순회 결과 : ");
    inorderTraversal(tree, park);
    printf("\n");

    return 0;
}
