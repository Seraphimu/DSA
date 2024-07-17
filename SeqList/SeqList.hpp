#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAX 5
using namespace std;

typedef int DataType;

class SeqList {
private:
    DataType * A;
    int Size;
public:

    //在当前位置插入
    void InsertThisPos(int Pos, DataType X);
    void PushBack(DataType X);

    //删除当前位置的元素
    void DeleteThisPos(int Pos);

    //排序
    void SelectionSort();

    //查找
    int SearchByValue(DataType Value);
    DataType SearchByPos(int Pos);
    DataType GetMax();
    DataType GetMin();

    //修改S
    void ModifyByValue(DataType NowValue, DataType NewValue);
    void ModifyByPos(int Pos, DataType NewValue);

    //初始化
    void Init();
    //判空
    bool IsFull();
    //判满
    bool IsEmpty();
    //打印
    void Print();
    //交换
    void Swap(DataType & X, DataType & Y);
    //下标合法性
    bool PosOK(int Pos);
};