#include "Stack.hpp"
void TestSeqStack() {
    StackSeq SS;
    
    SS.Init();
    SS.Push(1);
    SS.Push(1);
    SS.Push(4);
    SS.Push(5);
    SS.Push(1);
    // SS.Push(4);

    SS.MakeEmpty();
}

void TestLinkedStack() {
    StackLinked SL;
    
    SL.Init();
    SL.Push(1);
    SL.Push(2);
    SL.Push(3);
    SL.Push(4);
    SL.Push(5);
    SL.Push(6);

    cout << SL.GetTop() << endl;

    SL.MakeEmpty();
}
int main(void) {
    // TestSeqStack();
    TestLinkedStack();

    return 0;
}