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


void TestReserved() {
    SingleLinkedList * SL = new SingleLinkedList();

    SL->Init();
    // SL->PushBack(1);
    // SL->PushBack(2);
    // SL->PushBack(3);
    // SL->PushBack(4);
    // SL->PushBack(5);
    // SL->PushBack(6);
    for (int i = 0; i < 114; i++) {
        SL->PushBack(i);
    }
    cout << "before reserved: \n";
    SL->Print();
    SL->ReservedList();
    cout << "after reserved: \n";
    SL->Print();
}

void TestMergeTwoList() {
    //创建两个链表
    SingleLinkedList * ListA = new SingleLinkedList();
    SingleLinkedList * ListB = new SingleLinkedList();

    ListA->Init();
    ListB->Init();

    ListA->PushBack(1);
    ListA->PushBack(2);
    ListA->PushBack(3);
    ListA->PushBack(4);
    ListA->PushBack(5);
    ListA->PushBack(6);

    ListB->PushBack(114);
    ListB->PushBack(514);
    ListB->PushBack(114514);
    ListB->PushBack(1919810);


    //合并前
    cout << "before merge: \n";
    ListA->Print();

    //合并后
    cout << "after merge: \n";
    ListA->MergeInBetween(ListA->GetHead(), ListB->GetHead(), 2, 5);
    ListA->Print();
}


void TestMergeSeq() {
    SingleLinkedList * ListA = new SingleLinkedList();
    SingleLinkedList * ListB = new SingleLinkedList();

    ListA->Init();
    ListB->Init();

    ListA->PushBack(1);
    ListA->PushBack(1);
    ListA->PushBack(4);
    ListA->PushBack(5);

    ListB->PushBack(0);
    ListB->PushBack(0);
    ListB->PushBack(1);
    ListB->PushBack(6);
    ListB->PushBack(6);

    ListA->MergeSeq(ListA, ListB);

    ListA->Print();
}


int main(void) {
    // TestSingleLinkedList();
    // TestReserved();
    // f();
    // TestMergeTwoList();
    TestMergeSeq();

    return 0;
}