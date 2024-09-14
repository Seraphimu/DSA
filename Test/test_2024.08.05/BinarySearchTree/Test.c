#include "BinarySearchTree.h"

void Test() {
    BST * bst = NULL;

    init(&bst);

    insert(&bst, 1);
    insert(&bst, 5);
    insert(&bst, 4);
}

int main(void) {
    Test();

    return 0;
}