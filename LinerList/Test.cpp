#include "Array.hpp"
#include "SingleLinkedList.hpp"

void TestArray() {
    Array a;
    a.ArrayInit();
    a.ArrayPushBack(1);
    a.ArrayPushBack(1);
    a.ArrayPushBack(4);
    a.ArrayPushBack(-5);
    a.ArrayPushBack(1);
    a.ArrayPushBack(-4);

    // a.ArrayPushFront(1);
    // a.ArrayPushFront(1);
    // a.ArrayPushFront(4);
    // a.ArrayPushFront(5);
    // a.ArrayPushFront(1);
    // a.ArrayPushFront(4);

    // a.ArrayInsertThisPos(3, 114514);
    // a.ArrayInsertPrePos(3, 114514);
    // a.ArrayInsertAfterPos(3, 1919810);
    // a.ArrayInsertThisPos(0, 114);
    // a.ArrayInsertThisPos(a.Size, 514);
    // a.ArrayInsertAfterPos(a.Size, 514);
    // a.ArrayInsertPrePos(0, 114);
    // a.ArrayDeleteThisPos(a.Size - 2);

    // a.ArrayDeleteAfterPos(a.Size - 3);
    // a.ArrayPopBack();
    // a.ArrayPopBack();
    // a.ArrayPopBack();

    // a.ArrayPopFront();
    // a.ArrayPopFront();
    // a.ArrayPopFront();
    // a.ArrayPopFront();
    // a.ArrayPopFront();
    // a.ArrayPopFront();
    // a.ArrayPopFront();
    // a.ArrayPopFront();
    // a.ArrayPopFront();

    // a.ArraySelectionSort();
    // a.ArrayQuicklySort();

    // cout << a.ArraySearchByPos(5) << endl;
    // cout << a.ArrayFindMaxByLoop() << endl;
    // cout << a.ArrayFindMaxBySort() << endl;

    // cout << a.ArrayFindMinByLoop() << endl;
    // cout << a.ArrayFindMinBySort() << endl;
    
    // a.ArrayModifyByPos(3, 114514);
    // a.ArrayModifyByPos(6, 114514);
    a.ArrayModifyByValue(1, 140);



    a.ArrayPrint();
}

void TestSingleLinkedList() {
    SL pl;

    pl.SLInit();
    // pl.SLPushFront(1);
    // pl.SLPushFront(1);
    // pl.SLPushFront(4);
    // pl.SLPushFront(5);
    // pl.SLPushFront(1);
    // pl.SLPushFront(4);

    pl.SLPushBack(1);
    pl.SLPushBack(1);
    pl.SLPushBack(4);
    pl.SLPushBack(5);
    pl.SLPushBack(1);
    pl.SLPushBack(4);

    // pl.SLInsertPos(pl.SLHead, 114);
    // cout << pl.SLHead->Next << endl;
    // pl.SLInsertPos(pl.SLHead->Next, 114514);

    // pl.SLInsertPos(pl.SLHead, 11);
    // pl.SLInsertPos(pl.SLHead->Next + sizeof(pl) * 2, 11);
    // pl.SLInsertPos(pl.SLHead->Next + sizeof (pl), 114514);

    // cout << pl.SLSearchByValue(1145) << endl;;
    // pl.SLModifyByValue(1145, 114514);
    // pl.SLModifyByValue(5, 114514);
    cout << pl.SLLength() << endl;
    cout << pl.SLSearchByPos(5)->A << endl;
    cout << pl.SLSearchByPos(45) << endl;
    pl.SLPrint();
    // pl.SLInsertPos(pl.SLHead->Next->Next, 114514);
    // pl.SLInsertPos(pl.SLHead, 114514);

    pl.SLMakeEmpty();
    // pl.SLPopFront();
    // pl.SLPopFront();
    // pl.SLPopFront();
}

int main(void) {
    TestArray();
    TestSingleLinkedList();

    return 0;
}