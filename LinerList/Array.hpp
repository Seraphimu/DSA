#include <iostream>
#include <cstring>
#define MAX 100

using namespace std;
typedef int DataType;

class Array {
public:
    //存放元素的数组
    DataType A[MAX];
    //元素的个数
    int Size;

    //插入方法
    //在给定位置处插入，在给定位置前一位插入，和后一位插入
    void ArrayPushBack(DataType X);
    void ArrayPushFront(DataType X);
    void ArrayInsertThisPos(int Pos, DataType X);
    void ArrayInsertAfterPos(int Pos, DataType X);
    void ArrayInsertPrePos(int Pos, DataType X);

    //删除方法
    //在给定位置删除，在给定位置后一位删除，和前一位删除
    void ArrayPopBack();
    void ArrayPopFront();
    void ArrayDeleteThisPos(int Pos);
    void ArrayDeleteAfterPos(int Pos);
    void ArrayDeletePrePos(int Pos);

    //排序方法
    void ArrayBubbleSort();
    void ArraySelectionSort();
    // 快速排序
    void ArrayQuicklySort();
    void QSort(DataType A[], int Low, int High);
    int Partition(DataType A[], int Low, int High);

    //查找方法
    //查找下标为Pos的元素
    DataType ArraySearchByPos(int Pos);
    //返回欲查找元素的下标，若不存在，则返回-1
    int ArraySearchByValue(DataType X);

    // 查找特殊值
    DataType ArrayFindMaxByLoop();
    DataType ArrayFindMaxBySort();
    DataType ArrayFindMinByLoop();
    DataType ArrayFindMinBySort();


    // 修改方法
    // 根据下标修改
    void ArrayModifyByPos(int Pos, DataType X);
    // 如果该值在数组中，则修改；
    // 若无，返回 -1
    void ArrayModifyByValue(DataType SourceX, DataType X);

    //辅助方法
    void ArrayInit();
    void ArrayPrint();
    void ArrayIsFull();
    void ArrayIsEmpty();
    void ArrayPosInsertErr(int Pos);
    void ArrayPosErr(int Pos);
    void Swap(int & a, int & b);
};