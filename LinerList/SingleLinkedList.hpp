#include <iostream>
#include <cstdlib>

using namespace std;

typedef int DataType;

//链表结构
typedef struct Node {
    DataType A;
    struct Node * Next;
}Node;

//链表头指针及链表操作
typedef class SingleLinkedList {
public:
    Node * SLHead; 
    //初始化，建立空表，初始化头指针为空指针
    void SLInit();
    //分配空间，成功返回节点指针，失败返回空指针
    Node * SLBuyNode(DataType X);

    //插入方法
    //尾插
    void SLPushBack(DataType X);
    //头插
    void SLPushFront(DataType X);
    //在Pos位置插入
    void SLInsertPos(Node * Pos, DataType X);

    //删除方法
    //尾删
    void SLPopBack();
    //头删
    void SLPopFront();
    void SLDeletePos(Node * Pos);

    void SLMakeEmpty();

    //修改方法
    void SLModifyByValue(DataType NowValue, DataType NewValue);
    //查找方法
    Node * SLSearchByValue(DataType Value);
    Node * SLSearchByPos(int Pos);

    //辅助方法
    //判空：如果为空返回true，反之返回false
    bool SLIsEmpty();
    int SLLength();
    //判断下标是否合法：不合法返回true，合法返回false
    bool SLPosErr(Node * Pos);
    void SLPrint();
}SL;
