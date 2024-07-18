#include "QueueSeq.hpp"

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


int main(void) {
    TestSeq();

    return 0;
}