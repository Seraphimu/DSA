#include <iostream>
using namespace std;
typedef int DataType;

class Node {
private:
    DataType a;
    Node * next;
    friend class CycSingleLinkedList;
};

class CycSingleLinkedList {
private:
    Node * head;
public:
    CycSingleLinkedList() {
        head = nullptr;
    }

    //头插
    void pushFront(DataType x);
    //尾插
    void pushBack(DataType x);
    //在pos处插入元素x
    void insertThisPos(int pos, DataType x);

    //头删
    void popFront();
    //尾删
    void popBack();
    //删除第pos位的元素
    void deleteThisPos(int pos);

    //查找第pos位的前驱节点
    Node * searchPrePos(int pos);
    //查找第pos位的节点
    Node * searchThisPos(int pos);

    //修改这第pos位的元素
    void modifyThisPos(int pos, DataType newValue);
    //修改第一位数据域为value的元素
    void modifyThisValue(DataType value, DataType newValue);


    //打印
    void printList();
    //判空
    bool isEmpty();
    //摧毁
    void makeEmpty();
    //分配节点
    Node * buyNode(DataType x);
};