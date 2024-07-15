#include "DoubleStack.hpp"

void TestDoubleStack() {
    DoubleStack DS;

    DS.Init();

    DS.Push(1, DS.GetTP());
    DS.Push(2, DS.GetTP());
    DS.Push(3, DS.GetTP());
    DS.Push(4, DS.GetTP());
    DS.Push(5, DS.GetTP());
    DS.Push(6, DS.GetTP());

    DS.Push(114, DS.GetTB());
    DS.Push(514, DS.GetTB());
    DS.Push(1919, DS.GetTB());
    DS.Push(810, DS.GetTB());
    DS.Push(114514, DS.GetTB());

    cout << DS.GetTopValue(DS.GetTP()) << endl;
    cout << DS.GetTopValue(DS.GetTB()) << endl;

    DS.MakeEmpty();
}


int main(void) {
    TestDoubleStack();

    return 0;
}