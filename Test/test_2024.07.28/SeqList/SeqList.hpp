#include <iostream>
#include <cstring>
#define MAX 100
typedef int DataType;
using namespace std;

typedef class SeqList {
private:
    DataType * data;
    int size;

    void pushBack(DataType * arr, DataType x);
    int searchBySentinel(DataType * arr, DataType x);

public:
    //构造方法写到private中使用new时默认会报错
    SeqList() {
        data = new DataType[MAX];
        memset(data, 0, sizeof(DataType) * MAX);
        size = 0;
    }
    void pushBack(DataType x);
    void searchBySentinel(DataType x);
}SL;