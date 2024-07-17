#include "SeqList.hpp"

void SeqList::Init() {
    A = (DataType *)malloc(sizeof (DataType) * MAX);
    Size = 0;
    memset(A, 0, sizeof (*A) * MAX);
}

bool SeqList::IsFull() {
    return MAX == Size;
}

bool SeqList::IsEmpty() {
    return 0 == Size;
}

bool SeqList::PosOK(int Pos) {
    return Pos >= 0 && Pos < Size;
}

void SeqList::Print() {
    int i;
    for (i = 0; i < Size; i++) {
        printf("A[%d] == %d\t%c", i, A[i], (i+1) % 5 == 0? '\n': ' ');
    }
}

void SeqList::InsertThisPos(int Pos, DataType X) {
    if (Pos > MAX || Pos < 0) {
        cout << "Position Error!" << endl;
        exit(-1);
    }

    //下标正常
    for (int i = Size; i > Pos; i--) {
        A[i+1] = A[i];
    }

    A[Pos] = X;
    Size++;
}

void SeqList::PushBack(DataType X) {
    InsertThisPos(Size, X);
}

void SeqList::Swap(DataType & X, DataType & Y) {
    DataType Tmp = X;
    X = Y;
    Y = Tmp;
}

void SeqList::DeleteThisPos(int Pos) {
    //表空，或者下标不合法
    if (IsEmpty() || !PosOK(Pos)) {
        cout << "List Is Empty!" << endl;
        exit(-1);
    }

    int i;
    for (i = Pos; i < Size - 1; i++) {
        A[i] = A[i + 1];
    }

    Size--;
}

void SeqList::SelectionSort() {
    if (IsEmpty()) {
        cout << "List Is Empty" << endl;
        exit(-1);
    }

    int i, j;
    int Min = 0;
    for (i = 0; i < Size - 1; i++) {
        Min = i;
        for (j = i + 1; j < Size; j++) {
            if (A[Min] > A[j]) {
                Min = j;
            }
        }
        Swap(A[Min], A[i]);
    }
}

int SeqList::SearchByValue(DataType Value) {
    if (IsEmpty()) {
        cout << "List Is Empty!" << endl;
        exit(-1);
    }

    int i;
    for (i = 0; i < Size; i++) {
        if (A[i] == Value) {
            return i;
        }
    }

    return -1;
}

DataType SeqList::SearchByPos(int Pos) {
    if (IsEmpty() || !PosOK(Pos)) {
        cout << "List Is Empty or Position Error!" << endl;
        exit(-1);
    }

    return A[Pos];
}

DataType SeqList::GetMax() {
    if (IsEmpty()) {
        cout << "List Is Empty!" << endl;
        exit(-1);
    }

    int i;
    int Max = 0;
    for (i = 1; i < Size; i++) {
        if (A[Max] < A[i]) {
            Max = i;
        }
    }

    return A[Max];
}

DataType SeqList::GetMin() {
    if (IsEmpty()) {
        cout << "List Is Empty!" << endl;
        exit(-1);
    }

    int i;
    int Min = 0;
    for (i = 1; i < Size; i++) {
        if (A[Min] > A[i]) {
            Min = i;
        }
    }

    return A[Min];   
}

void SeqList::ModifyByValue(DataType NowValue, DataType NewValue) {
    int Tmp = SearchByValue(NowValue);
    if (Tmp == -1) {
        cout << "Value is Not Exist" << NowValue << endl;
        exit(-1);
    }

    A[Tmp] = NewValue;
    cout << "Modify Success!" << endl;
}

void SeqList::ModifyByPos(int Pos, DataType X) {
    //检测下标
    if (IsEmpty() || !PosOK(Pos)) {
        cout << "List Is Empty or Position Error!" << endl;
        exit(-1);
    }

    A[Pos] = X;
    cout << "Modify Success!" << endl;
}