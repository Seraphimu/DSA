#include "SeqList.hpp"

void Test() {
    SL seq;
    seq.pushBack(1);
    seq.pushBack(2);
    seq.pushBack(3);
    seq.pushBack(4);
    seq.pushBack(5);
    seq.insertThisPos(114514, 2);
    seq.insertThisPos(114514, 6);

    seq.printList();

    seq.makeEmpty();
    // seq.printList();
}

int main(void) {
    Test();

    return 0;
}