#include <iostream>
#include <cstdlib>
#include <cstring>
#define MAX 100
typedef int DataType;
using namespace std;

typedef class SeqList {
private:
    DataType * data;
    int size;
public:
    SeqList();
    //尾插
    void pushBack(DataType x);

    //在当前给出的位置pos处（前）插入元素x
    void insertThisPos(int pos, DataType x);
    //删除当前给出的位置pos处的元素
    void deleteThisPos(int pos);

    //按位置查找，返回元素
    DataType searchByPos(int pos);
    //按值查找，返回下标
    int searchByValue(DataType target);

    //为满时返回真
    bool isFull();
    //为空返回真
    bool isEmpty();
    //打印
    void print();
    void makeEmpty();
}SL;
