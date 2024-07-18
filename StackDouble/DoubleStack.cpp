#include "DoubleStack.hpp"

void DoubleStack::Init() {
    A = (DataType *)malloc(sizeof (DataType) * MAX);
    TP = -1;
    TB = MAX;
}

bool DoubleStack::IsFull() {
    return TP + 1 == TB;
}

bool DoubleStack::IsEmpty() {
    return TP == -1 && TB == MAX;
}

void DoubleStack::Push(DataType X, int Top) {
    //栈非空
    if (IsFull()) {
        cout << "Stack Is Full!" << endl;
        exit(-1);
    }

    if (Top == TP) {
        A[++TP] = X;
    }
    
    else if (Top == TB) {
        A[--TB] = X;
    }
    else {
        cout << "This is not the top of the stack!" << endl;
        exit(-1);
    }

    // 把TP自增，却用Top为下标给其赋值，怪不得会出错
    // 非空
    // if (Top == TP) {
    //     TP++;
    // }
    
    // else if (Top == TB) {
    //     TB--;
    // }
    // else {
    //     cout << "This is not the top of the stack!" << endl;
    //     exit(-1);
    // }

    // A[Top] = X;
}

void DoubleStack::Pop(int Top) {
    if (IsEmpty()) {
        cout << "Stack is Empty!" << endl;
        exit(-1);
    }

    if (Top == TP) {
        TP--;
    }
    else if (Top == TB) {
        TB++;
    }
    else {
        cout << "This is not the top of stack!" << endl;
        exit(-1);
    }
}

DataType DoubleStack::GetTopValue(int Top) {
    if (IsEmpty()) {
        cout << "Stack is empty!\n";
        exit(-1);
    }
    else {
        return A[Top];
    }
}

void DoubleStack::MakeEmpty() {
    if (IsEmpty()) {
        cout << "Stack is empty!\n";
        exit(-1);
    }

    while (TP != -1) {
        Pop(TP);
    }

    while (TB != MAX) {
        Pop(TB);
    }
}

int DoubleStack::GetTP() {
    return TP;
}
int DoubleStack::GetTB() {  
    return TB;
}