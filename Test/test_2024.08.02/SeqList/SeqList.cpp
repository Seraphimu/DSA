#include "SeqList.hpp"

void SL::pushBack(DataType x) {
    if (!isFull()) {
        pData[size] = x;
        size++;
    }
    else {
        cout << "List is Full!\n";
    }
}

bool SL::isFull() {
    return size == MAX;
}

bool SL::isEmpty() {
    return size == 0;
}

void SL::makeEmpty() {
    delete pData;
    pData = nullptr;
    size = 0;
}

void SL::printList() {
    if (!isEmpty()) {
        int i;
        for (i = 0; i < size; i++) {
            cout << pData[i] << " ";
        }

        cout << "\n";
    }
    else {
        cout << "List is Empty!\n";
    }
}


void SL::insertThisPos(DataType x, int pos) {
    if (isFull()){
        cout << "List is Full!\n";
        exit(-1);
    }
    //pos == size is correct when insert, but delete is not correct.
    else if (pos < 0 || pos > size) {
        cout << "Position is error!\n";
        exit(-1);
    }
    else {
        int i;
        // //when i == size - 1: pData[size] = pData[size - 1];
        // //Error
        // for (i = pos; i < size; i++) {
        //     pData[i + 1] = pData[i];
        // }
        //back to pos is correct, pos to back will cover the values of the index that after pos
        //when i = pos + 1: pData[pos + 1] = pData[pos]
        for (i = size; i > pos; i--) {
            pData[i] = pData[i - 1];
        }
        pData[pos] = x;
        size++;
    }
}

bool SL::posErr(int pos) {
    return pos >= size || pos < 0;
}