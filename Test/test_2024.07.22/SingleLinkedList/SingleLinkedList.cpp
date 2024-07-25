#include "SingleLinkedList.hpp"

Node * SL::buyNode(DataType x) {
    Node * newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;

    return newNode;
}

void SL::pushFront(DataType x) {
    Node * newNode = buyNode(x);
    newNode->next = head;
    head = newNode;
}

void SL::popFront() {
    if (head == nullptr) {
        cout << "List Is Empty!\n";
        exit(-1);
    }

    Node * tmp = head;
    head = head->next;
    delete tmp;
    tmp = nullptr;
}

void SL::printL() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        exit(-1);
    }

    Node * cur = head;
    while (cur != nullptr) {
        cout << cur->data << "\n";
        cur = cur->next;
    }
    cout << "Print Successfully!\n";
}

Node * SL::getHead() {
    return head;
}


Node * SL::deleteANode(Node * node) {
    //不给头指针，直接把要删除节点的数据域，用其后继节点的数据域覆盖掉，再删除其后继节点即可。
    Node * tmp = node->next;
    //复制数据域
    node->data = tmp->data;
    //指向其后继节点的下一位
    node->next = tmp->next;
    //释放节点
    delete tmp;
    tmp = nullptr;

    return node;
}