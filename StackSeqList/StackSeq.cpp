#include "StackSeq.hpp"

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
