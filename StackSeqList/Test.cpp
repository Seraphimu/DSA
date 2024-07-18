#include "StackSeq.hpp"
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


int main(void) {
    // TestSeqStack();

    return 0;
}