#include "Queue.hpp"

void TestSeq() {
    QueueSeq QS;
    QS.Init();
    QS.Push(1);
    QS.Push(2);
    QS.Push(3);
    QS.Push(4);
    QS.Push(5);
    QS.Pop();
    QS.Push(6);

    cout << QS.GetFront() << endl;
    cout << QS.GetRear() << endl;
    cout << "Front == " << QS.Front << endl;
    cout << "Rear == " << QS.Rear << endl;
    cout << "IsFull() == " << QS.IsFull() << endl;
    cout << "IsEmpty() == " << QS.IsEmpty() << endl;

    QS.MakeEmpty();
}

void TestLinked() {
    QueueLinked QL;
    QL.Init();
    QL.Push(1);
    QL.Push(2);
    QL.Push(3);
    QL.Push(4);
    QL.Push(5);
    QL.Push(6);
    QL.Pop();
    QL.Pop();
    QL.Pop();
    QL.Pop();
    QL.Pop();
    QL.Pop();

    cout << QL.GetFront() << endl;
    cout << QL.GetRear() << endl;

    QL.MakeEmpty();
}

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