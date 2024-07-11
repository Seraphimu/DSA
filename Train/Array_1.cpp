#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 100
typedef int DataType;
class Array {
public:
    //存放元素的数组
    DataType A[MAX];
    //元素的个数
    int Size;

    //插入方法
    void ArrayPushBack(DataType X);
    void ArrayPushFront(DataType X);
    void ArrayInsertThisPos(int Pos, DataType X);

    //删除方法
    void ArrayPopBack();
    void ArrayPopFront();
    void ArrayDeleteThisPos(int Pos);

    //排序方法
    void ArraySelectionSort();

    //查找方法
    //查找下标为Pos的元素
    DataType ArraySearchByPos(int Pos);
    //返回欲查找元素的下标，若不存在，则返回-1
    int ArraySearchByValue(DataType X);

    // 查找特殊值
    DataType ArrayFindMax();
    DataType ArrayFindMin();


    // 修改方法，根据下标修改
    void ArrayModifyByPos(int Pos, DataType X);
    // 如果该值在数组中，则修改；若无，返回 -1
    void ArrayModifyByValue(DataType SourceX, DataType X);

    //辅助方法
    //初始化：创建一个空表
    void ArrayInit();
    //打印
    void ArrayPrint();
    //判断表是否满
    bool ArrayIsFull();
    //判断表是否空
    bool ArrayIsEmpty();
    //判断下标是否合法
    bool ArrayPosErr(int Pos);
    //交换两个元素的值
    void Swap(int & a, int & b);
};

void Array::ArrayInit() {
    //初始化数组，全0
    memset(A, 0, sizeof(A));
    //初始大小为0
    Size = 0;
}

bool Array::ArrayIsEmpty() {
    if (Size == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool Array::ArrayIsFull() {
    if (Size == MAX) {
        return true;
    }
    else {
        return false;
    }
}

void Array::ArrayPushBack(DataType X) {
    //如果表满，无法插入
    if (ArrayIsFull()) {
        cout << "Is Full!" << endl;
        exit(-1);
    }
    //如果表不满，在数组末尾插入元素
    A[Size] = X;
    Size++;
}
