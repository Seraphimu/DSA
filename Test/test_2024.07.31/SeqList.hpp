#include <iostream>

using namespace std;
typedef int DataType;

typedef class Array {
private:
    DataType * data;
    int size;
    friend class SeqList;
};

typedef class SeqList {
private:
    Array arr;
public:
    SeqList() {
        arr.data = nullptr;
        arr.size = 0;
    }
}SL;