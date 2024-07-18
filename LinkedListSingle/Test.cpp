#include "SingleLinkedList.hpp"

void TestSingleLinkedList() {
    SingleLinkedList SL;
    SL.Init();
    // SL.PushFront(1);
    // SL.PushFront(2);
    // SL.PushFront(3);
    // SL.PushFront(4);
    // SL.PushFront(5);
    // SL.PushFront(6);
    SL.PushBack(1);
    SL.PushBack(2);
    SL.PushBack(3);
    SL.PushBack(4);
    SL.PushBack(5);
    SL.PushBack(6);

    SL.ModifyByValue(5, 114514);
    // SL.ModifyByValue(114, 114514);

    // Node * Ret5 = SL.SearchByValue(5);
    // Node * Ret114514 = SL.SearchByValue(114514);

    // cout << "Ret5 = " << Ret5 << " " << Ret5->Next->A << "\n";
    // cout << "Ret114514 = " << Ret114514 << "\n";

    // SL.InsertThisPos(0, 114514);
    // SL.InsertThisPos(1, 1919810);
    // SL.InsertThisPos(8, 114);

    // SL.InsertThisPos(1, 114514);

    // SL.DeleteThisPos(1);
    // SL.DeleteThisPos(3);
    // SL.PopFront();
    // SL.IsEmpty();
    // SL.PopBack();
    // SL.PopBack();
    // SL.PopBack();
    SL.Print();

    SL.MakeEmpty();
}

int main(void) {
    TestSingleLinkedList();

    return 0;
}