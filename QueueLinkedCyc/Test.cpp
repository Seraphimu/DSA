#include "QueueLinkedCyc.hpp"

void TestCycLinked() {
    QueueCycLinked QCL;
    QCL.Init();
    QCL.Push(1);
    // QCL.Push(2);
    // QCL.Push(3);
    // QCL.Push(4);
    // QCL.Push(5);
    // QCL.Push(6);
    // QCL.Push(1);
    // QCL.Push(2);
    // QCL.Push(3);
    // QCL.Push(4);
    // QCL.Push(5);
    // QCL.Push(6);
    // QCL.Push(1);
    // QCL.Push(2);
    // QCL.Push(3);
    // QCL.Push(4);
    // QCL.Push(5);
    // QCL.Push(6);
    // QCL.Push(1);
    // QCL.Push(2);
    // QCL.Push(3);
    // QCL.Push(4);
    // QCL.Push(5);
    // QCL.Push(6);

    cout << QCL.GetFront() << endl;
    cout << QCL.GetRear() << endl;


    QCL.MakeEmpty();
}

int main(void) {
    // TestSeq();
    // TestLinked();
    TestCycLinked();

    return 0;
}