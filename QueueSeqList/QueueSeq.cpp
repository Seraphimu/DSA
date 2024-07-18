#include "QueueSeq.hpp"

void QueueSeq::Push(DataType X) {
    if (IsFull()) {
        cout << "Queue Is Full!" << endl;
        exit(-1);
    }

    A[Rear] = X;
    Rear = (Rear + 1) % MAX;
}

void QueueSeq::Pop() {
    if (IsEmpty()) {
        cout << "Queue Is Empty!" << endl;
        exit(-1);
    }
    A[Front] = -65535;
    Front = (Front + 1) % MAX;
}

DataType QueueSeq::GetFront() {
    return A[Front];
}

DataType QueueSeq::GetRear() {
    return A[Rear];
}

void QueueSeq::MakeEmpty() {
    while (!IsEmpty()) {
        Pop();
    }
}

void QueueSeq::Init() {
    A = (DataType *)malloc(sizeof (DataType) * MAX);
    Front = Rear = 0;
}

bool QueueSeq::IsFull() {
    return (Rear + 1) % MAX == Front;
}

bool QueueSeq::IsEmpty() {
    return Rear == Front;   
}
