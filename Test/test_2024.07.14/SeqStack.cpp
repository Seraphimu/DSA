#include "SeqStack.hpp"

bool SeqStack::IsFull() {
    return MAX - 1 == Top;
}

bool SeqStack::IsEmpty() {
    return -1 == Top;
}

void SeqStack::Push(DataType X) {
    if (IsFull()) {
        cout << "Stack Is Full!" << endl;
        exit(-1);
    }
    else {
        Top++;
        A[Top] = X;
    }
}

void SeqStack::Pop() {
    if (IsEmpty()) {
        cout << "Stack Is Empty!" << endl;
        exit(-1);
    }
    else {
        Top--;
    }
}

DataType SeqStack::GetTop() {
    if (IsEmpty()) {
        cout << "Stack Is Empty!" << endl;
        exit(-1);
    }
    else {
        return A[Top];
    }
}

void SeqStack::MakeEmpty() {
    while (!IsEmpty()) {
        cout << A[Top] << " ";
        Pop();
        cout << "Has Been Poped!" << endl;
    }

    cout << "Stack Has Been Completed!" << endl;
}

void SeqStack::Init() {
    Top = -1;
    A = (DataType *)malloc(sizeof (DataType) * MAX);
}