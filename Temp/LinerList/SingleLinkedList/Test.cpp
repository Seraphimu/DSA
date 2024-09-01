#include "SingleLinkedList.hpp"

void test() {
    SL * ps = new SL();
    // ps->pushFront(5);
    // ps->pushFront(4);
    // ps->pushFront(3);
    // ps->pushFront(2);
    // ps->pushFront(1);

    ps->pushBack(1);
    ps->pushBack(2);
    ps->pushBack(3);
    ps->pushBack(4);
    ps->pushBack(5);

    SL * newList = ps->reverseList();

    // ps->insertThisPos(0, 114514);

    // ps->deleteThisPos(0);
    // ps->deleteThisPos(1);
    // ps->deleteThisPos(2);
    // ps->deleteThisPos(2);
    cout << "newList:\n";
    newList->makeEmpty();
    cout << "ps:\n";
    ps->makeEmpty();
}

int main(void) {
    test();

    return 0;
}