#include "SeqList.hpp"


void TestSeqList() {
    SeqList SL;
    SL.Init();

    SL.PushBack(912);
    SL.PushBack(114);
    SL.PushBack(514);
    SL.PushBack(101);
    SL.PushBack(201);

    SL.Print();
    // SL.ModifyByPos(1, 114514);
    // SL.ModifyByPos(10, 114514);
    // SL.ModifyByValue(101, 502);
    SL.ModifyByValue(10, 502);
    SL.Print();

    // cout << "Max: " << SL.GetMax() << endl;
    // cout << "Min: " << SL.GetMin() << endl;
    
    // cout << "Pre" << endl;
    // SL.Print();
    // // SL.DeleteThisPos(0);
    // // SL.SelectionSort();
    // cout << "114: " << SL.SearchByValue(114) << endl;
    // cout << "1" << SL.SearchByPos(1) << endl;
    // cout << "After" << endl;
    // SL.Print();
    // cout << "224: " << SL.SearchByValue(224) << endl;
    // cout << "6" << SL.SearchByPos(6);
}


int main(void) {
    TestSeqList();

    return 0;
}