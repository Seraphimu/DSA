#include <iostream>

using namespace std;

typedef int DataType;

//单链表的节点描述
typedef struct Node {
private:
    //数据域
    DataType data;
    //指针域
    struct Node * next;
    //允许SingleLinkedList类访问
    friend class SingleLinkedList;
}Node;

typedef class SingleLinkedList {
private:
    Node * head;
public:
    //构造方法，初始化为空
    SingleLinkedList() {
        head = nullptr;
    }

    //头插
    void pushFront(DataType x);
    void popFront();


    //打印
    Node * buyNode(DataType x);
    void printL();
    Node * getHead();


    //ALG
    Node * deleteANode(Node * node);

}SL;