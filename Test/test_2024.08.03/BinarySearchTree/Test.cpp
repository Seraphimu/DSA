#include "BST.hpp"

void Test() {
    BST * bst = new BST();
    bst->insertBST(114514);
    bst->insertBST(114);
    bst->insertBST(1919810);
    bst->insertBST(514);
    bst->insertBST(1);
    bst->insertBST(2);
    bst->insertBST(50);


    // bst->preOrderTraverse();
    bst->levelTraverse();
    bst->deleteBST(50);
    bst->deleteBST(114514);

    // bst->levelTraverse();

    bst->makeEmpty();
}

int main(void) {
    Test();

    return 0;
}