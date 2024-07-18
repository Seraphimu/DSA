#include "QueueLinked.hpp"

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

int main(void) {
    TestLinked();

    return 0;
}