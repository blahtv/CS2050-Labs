#include "lab10.h"

int main() {
    BST * tree = initBST();
    printInOrder(tree);
    for(int i = 1; i < 101; i++)
    insertBST(tree, i);
    printf("Largest: %d\n", getMax(tree));



    clock_t t = clock();
    printInOrder(tree);
    t = clock() - t;
    printf("Print took %f seconds\n", (float)t/CLOCKS_PER_SEC);

    t = clock();
    int contains = 101;
    printf("Contains %d? : %d\n", contains, BSTContains(tree, contains));
    t = clock() - t;
    printf("Binary Search took %f seconds\n", (float)t/CLOCKS_PER_SEC);

    freeTree(tree);
}  

