#include "SeqList.hpp"

void SL::pushBack(DataType x) {
    //表不满，可插入
    if (isFull()) {
        cout << "list is full!\n";
        exit(-1);
    }
    else {
        data[size++] = x;
    }
}

void SL::insertThisPos(int pos, DataType x) {
    //表满或者下标超出范围时无法插入
    if (isFull() ) {
        cout << "list is full!\n";
        exit(-1);
    }
    // else if (pos > MAX || pos < 0) {     //这里是size
    else if (pos >= size || pos < 0) {
        cout << "position is not correct!\n";
        exit(-1);
    }
    else {
        //可以插入
        int i = size;
        //把[pos, size)的数据移动到[pos + 1, size]中
        while (i > pos) {
            data[i] = data[i - 1];
            i--;
        }
        data[i] = x;
        size++;
    }
}

SL::SeqList() {
    data = new DataType[MAX];
    // data = new DataType(MAX);    //错误
    // data = (DataType *)malloc(sizeof(DataType) * MAX);
    // sizeof (data) 是一个指针的大小，大错特错，以下是调试结果，只有8个字节被置为0
    // (gdb) p data[0] 
    // $5 = 0
    // (gdb) p data[1]
    // $6 = 0
    // (gdb) p data[2]
    // $7 = -1414812757
    // (gdb) p data[3]
    // $8 = -1414812757
    // (gdb) p data[99]
    // $9 = -17891602
    memset(data, 0, sizeof (DataType) * MAX);
    size = 0;
}

void SL::deleteThisPos(int pos) {
    //排除表空的情况
    if (isEmpty()) {
        cout << "list is empty!\n";
        exit(-1);
    }
    //排除下标不正确的情况
    // else if (pos > MAX || pos < 0) {         //这里应该是size
    else if (pos >= size || pos < 0) {
        cout << "position is not correct!\n";
        exit(-1);
    }
    else {
        int i = pos;
        // while (i++ < size - 1) {             //别假能了草
        while (i < size - 1) {
            data[i] = data[i + 1];
            i++;
        }
        size--;
    }
}

DataType SL::searchByPos(int pos) {
    if (pos < 0 || pos >= size) {
        cout << "pos is not correct!\n";
        exit(-1);
    }
    else {
        return data[pos];
    }
}

int SL::searchByValue(DataType target) {
    if (isEmpty()) {
        cout << "list is empty!\n";
        exit(-1);
    }
    else {
        int i;
        for (i = 0; i < size; i++) {
            if (target == data[i]) {
                return i;
            }
        }

        return -1;
    }
}

bool SL::isFull() {
    return size == MAX;
}

bool SL::isEmpty() {
    return size == 0;
}

void SL::print() {
    int i = 0;
    cout << "list is: \n";
    while (i < size) {
        cout << data[i] << " ";
        i++;
    }
    cout << "\n";
}

void SL::makeEmpty() {
    size = 0;
    delete data;
    data = nullptr;
}

void SL::insertionSort() {
    int i;
    int j;
    DataType tmp;
    for (i = 1; i < size; i++) {
        tmp = data[i];
        //前移
        for (j = i; j > 0 && data[j - 1] > tmp; j--) {
            data[i] = data[i - 1];
        }
        //植入
        data[i] = tmp;
    }
}