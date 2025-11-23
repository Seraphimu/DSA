#include "BinaryTree.h"

void test() {
    BinaryTree tree;
    tree.create();
    tree.levelOrderTraverse();
    tree.preOrderTraverseIter();
    tree.inOrderTraverseIter();
    tree.postOrderTraverseIter();
    tree.postOrderTraverseIterTwoStack();
}

int main(void) {
    test();

    return 0;
}