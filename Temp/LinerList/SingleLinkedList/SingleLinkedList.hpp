#include <iostream>
#include <cstdlib>

typedef int DataType;

using namespace std;

class Node {
private:
    DataType data;
    Node * next;
    friend class SingleLinkedList;
public:
    Node (DataType x);
};

typedef class SingleLinkedList {
private:
    Node * head;
public:
    SingleLinkedList();
    //头插
    void pushFront(DataType x);
    //尾插
    void pushBack(DataType x);
    //头删
    void popFront();
    //尾删
    void popBack();
    //置空
    void makeEmpty();
    //在当前位置（的前面）插入
    void insertThisPos(int pos, DataType x);
    //删除当前位置的元素
    void deleteThisPos(int pos);

    //判空
    bool isEmpty();
}SL;