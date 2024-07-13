#include "Stack.hpp"

//顺序

void StackSeq::Init() {
    A = (DataType*)malloc(sizeof(StackSeq) * MAX);
    Top = -1;
}

bool StackSeq::IsEmpty() {
    return Top == -1;
}

bool StackSeq::IsFull() {
    return Top == MAX - 1;
}

void StackSeq::Push(DataType X) {
    //Send an error message when the stack is full.
    if (IsFull()) {
        cout << "Stack Is Full!" << endl;
        exit(-1);
    }

    //Push an element when the stack is not full.
    Top++;
    A[Top] = X;
}

void StackSeq::Pop() {
    if (IsEmpty()) {
        cout << "Stack Is Empty!" << endl;
        exit(-1);
    }

    Top--;
}

DataType StackSeq::GetTop() {
    return A[Top];
}

void StackSeq::MakeEmpty() {
    while(!IsEmpty()) {
        Pop();
    }
}


//------------------------------------------------------------------------------------------------------------------------

//链式


//初始化
void StackLinked::Init() {
    STHead = nullptr;
}

//分配节点
Node * StackLinked::BuyNode(DataType X) {
    Node * NewNode = (Node *)malloc(sizeof (Node));

    //分配失败
    if (NewNode == nullptr) {
        cout << "Malloc Error!" << endl;
        exit(-1);
    }

    //建立节点
    NewNode->A = X;
    NewNode->Next = nullptr;

    return NewNode;
}

void StackLinked::Push(DataType X) {
    //头插不用考虑各种特殊情况，即使表头为空，也可以如此操作
    Node * NewNode = BuyNode(X);

    NewNode->Next = STHead;
    STHead = NewNode;
}

void StackLinked::Pop() {
    if (IsEmpty()) {
        cout << "Stack Is empty" << endl;
        exit(-1);
    }

    Node * Tmp = STHead;
    STHead = STHead->Next;
    free(Tmp);
}

DataType StackLinked::GetTop() {
    return STHead->A;
}

void StackLinked::MakeEmpty() {
    while (!IsEmpty()) {
        Pop();
    }
}

bool StackLinked::IsEmpty() {
    return STHead == NULL;
}