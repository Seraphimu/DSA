#include "SeqStack.hpp"

void Test() {
    SeqStack SS;

    SS.Init();

    SS.Push(1);
    SS.Push(2);
    SS.Push(3);
    SS.Push(4);
    SS.Push(5);
    SS.Push(6);

    SS.Pop();
    SS.Pop();
    SS.Pop();

    cout << SS.GetTop() << endl;
    SS.MakeEmpty();
}

int main(void) {
    Test();

    return 0;
}