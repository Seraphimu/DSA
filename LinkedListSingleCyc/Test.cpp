#include "CircularlySingleLinkedList.hpp"

void TestCycSingleLinkedList() {
    CycSingleLinkedList * cL = new CycSingleLinkedList();

    cL->pushFront(1);
    cL->pushFront(2);
    cL->pushFront(3);
    cL->pushFront(4);
    cL->pushFront(5);
    cL->pushFront(6);

    cL->printList();

    // cL->popFront();
    // cL->popFront();
    // cL->popFront();
    // cL->popFront();
    // cL->popFront();
    // cL->popFront();

    cL->makeEmpty();

}

int main(void) {
    TestCycSingleLinkedList();

    return 0;
}