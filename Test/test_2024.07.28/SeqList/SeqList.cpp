#include "SeqList.hpp"

void SL::pushBack(DataType * arr, DataType x) {
    try {
        arr[size] = x;
        size++;
    }
    catch (DataType * arr){
        cout << arr << endl;
    }
}

void SL::pushBack(DataType x) {
    try {
        pushBack(data, x);
    }
    catch (DataType * arr) {
        cout << arr << endl;
    }
}

int SL::searchBySentinel(DataType * arr, DataType x) {
    
}

int SL::searchBySentinel(DataType * arr, DataType x) {

}