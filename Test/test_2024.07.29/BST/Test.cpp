#include "BinarySearchTree.hpp"

void Test() {
    BST * bst = new BST();

    // bst->createManual();
    // bst->searchByIter(114514);
    // bst->searchByIter(1919810);
    // bst->searchByIter(1);
    bst->insert(1);
    bst->insert(1);
    bst->insert(4);
    bst->insert(5);
    bst->insert(1);
    bst->insert(4);

    bst->insert(114514);
    bst->insert(-114514);
    bst->insert(0);
    bst->insert(-100);

    // bst->insertIter(114514);
    // bst->insertIter(-114514);
    // bst->insertIter(0);
    // bst->insertIter(-100);

    cout << "Max is " << bst->getMax() << "\n";
    cout << "Min is " << bst->getMin() << "\n";

    bst->preOrderTraverse();
    bst->inOrderTraverse();
    bst->postOrderTraverse();
}

int main(void) {
    Test();

    return 0;
}