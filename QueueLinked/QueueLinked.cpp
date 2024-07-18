#include "QueueLinked.hpp"

Node * QueueLinked::BuyNode(DataType X) {
    Node * NewNode = (Node *)malloc(sizeof(Node));
    // Node * NewNode = (Node *)malloc(sizeof(DataType));
    
    if (NewNode == nullptr) {
        cout << "Malloc Failed!" << endl;
        exit(-1);
    }
    else {
        NewNode->A = X;
        NewNode->Next = nullptr;
    }
    
    return NewNode;
}

void QueueLinked::Push(DataType X) {
    if (IsEmpty()) {
        Node * NewNode = BuyNode(X);
        Front = Rear = NewNode;
    }
    else {
        Node * NewNode = BuyNode(X);
        Rear->Next = NewNode;
        Rear = Rear->Next;
    }
}

void QueueLinked::Pop() {
    if (IsEmpty()) {
        cout << "Queue Is Empty!" << endl;
        exit(-1);
    }
    else {
        Node * Tmp = Front;
        Front = Front->Next;
        free(Tmp);
        Tmp = nullptr;
    }
    if (IsEmpty()) {
        Rear = nullptr;
    }
}

DataType QueueLinked::GetFront() {
    if (IsEmpty()) {
        cout << "Queue Is Empty!" << endl;
        exit(-1);
    }
    return Front->A;
}
DataType QueueLinked::GetRear() {
       if (IsEmpty()) {
        cout << "Queue Is Empty!" << endl;
        exit(-1);
    }
    return Rear->A;
}

void QueueLinked::Init() {
    Front = Rear = nullptr;
}

bool QueueLinked::IsEmpty() {
    return Front == nullptr;
}
void QueueLinked::MakeEmpty() {
    while (!IsEmpty()) {
        Pop();
    }
}