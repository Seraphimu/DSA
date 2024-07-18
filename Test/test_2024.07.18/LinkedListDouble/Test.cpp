#include "DoubleLinkedList.hpp"

void TestDoubleLinkedList() {
    DoubleLinkedList DL;
    DL.Init();
    // DL.PushFront(6);
    // DL.PushFront(5);
    // DL.PushFront(4);
    // DL.PushFront(3);
    // DL.PushFront(2);
    // DL.PushFront(1);

    DL.PushBack(1);
    DL.PushBack(2);
    DL.PushBack(3);
    DL.PushBack(4);
    DL.PushBack(5);
    DL.PushBack(6);

    DL.ModifyByValue(0, 114514);

    // DL.ModifyByValue(6, 114514);
    // DL.ModifyByValue(1, 1919180);

    // DL.PopBack();
    // DL.PopBack();
    // DL.PopBack();
    // DL.PopBack();

    // DL.DeleteThisPos(6);

    // DL.PopFront();


    DL.Print();

    DL.MakeEmpty();
}

int main(void) {
    TestDoubleLinkedList();

    return 0;
}