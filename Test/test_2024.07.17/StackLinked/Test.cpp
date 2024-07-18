#include "StackLinked.hpp"

void TestStackLinked() {
    StackLinked SL;

    SL.Init();

    SL.Push(1);
    SL.Push(2);
    SL.Push(3);
    SL.Push(4);
    SL.Push(5);

    SL.Pop();
    SL.Pop();
    SL.Pop();

    cout << SL.GetTop() << endl;

    SL.MakeEmpty();
}


int main(void) {
    TestStackLinked();

    return 0;
}