#include "QueueLinkedCyc.hpp"

void QueueCycLinked::Init() {
    Front = Rear = nullptr;
}

Node * QueueCycLinked::BuyNode(DataType X) {
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

void QueueCycLinked::Push(DataType X) {
    if (IsEmpty()) {
        Front = Rear = BuyNode(X);
        Rear->Next = Front;
    }
    else {
        //生成新节点
        Node * NewNode = BuyNode(X);
        NewNode->Next = Front;
        Rear->Next = NewNode;
        Rear = Rear->Next;
    }
}

void QueueCycLinked::Pop() {
    if (IsEmpty()) {
        cout << "Queue Is Empty !" << endl;
        exit(-1);
    }
    else if (Front == Rear) {
        free(Front);
        Init();
    }
    else {
        //向后移动一位
        Node * Tmp = Front;
        Front = Front->Next;
        //保持循环链表结构
        Rear->Next = Front;
        //删除原来的Front指针指向的节点
        free(Tmp);
        Tmp = nullptr;
    }
}

void QueueCycLinked::MakeEmpty() {
    while (!IsEmpty()) {
        cout << Front->A << " ";
        Pop();
        // 释放过的节点无法打印，导致段错误
        // cout << Front->A << " Has Been Poped!" << endl;
        cout << "Has Been Poped!" << endl;
    }
    cout << "Queue Has Been Completed!" << endl;
}

bool QueueCycLinked::IsEmpty() {
    return Front == nullptr;
}


DataType QueueCycLinked::GetFront() {
    if (IsEmpty()) {
        cout << "Queue Is Empty!" << endl;
        exit(-1);
    }
    return Front->A;
}
DataType QueueCycLinked::GetRear() {
       if (IsEmpty()) {
        cout << "Queue Is Empty!" << endl;
        exit(-1);
    }
    return Rear->A;
}