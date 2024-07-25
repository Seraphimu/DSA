#include "SingleLinkedList.hpp"

void Test() {
    SL * s = new SL();
    s->pushFront(6);
    s->pushFront(5);
    s->pushFront(4);
    s->pushFront(3);
    s->pushFront(2);
    s->pushFront(1);

    Node * node = s->getHead();

    s->printL();

    s->popFront();
    s->popFront();
    s->popFront();
    s->popFront();
    s->popFront();
    s->popFront();

}

int main(void) {
    Test();

    return 0;
}