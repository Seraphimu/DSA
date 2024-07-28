#include "BinTree.hpp"

void Test() {
    BT * bt = new BT();

    bt->createManual();
    cout << "preOrder:  ";
    bt->preOrderTraverse();
    cout << "inOrder:   ";
    bt->inOrderTraverse();
    cout << "postOrder: ";
    bt->postOrderTraverse();
    cout << "levelOrder:";
    bt->levelOrderTraverse();
    cout << "Leaf:\n";
    bt->printLeafNode();

    bt->treeHeight();


    bt->MakeEmpty();
}


int main(void) {
    Test();

    return 0;
}