#include "SingleLinkedList.hpp"

Node::Node(DataType x) {
    data = x;
    next = nullptr;
}

SL::SingleLinkedList() {
    head = nullptr;
}

void SL::pushFront(DataType x) {
    //用构造方法分配节点
    Node * newNode = new Node(x);

    newNode->next = head;
    head = newNode;
}

void SL::pushBack(DataType x) {
    //如果链表为空
    if (head == nullptr) {
        head = new Node(x);
    }
    //不为空
    else {
        //遍历到表尾
        Node * tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        //退出循环时，tail为尾节点
        //插入节点
        Node * newNode = new Node(x);
        tail->next = newNode;
    }
}

void SL::popFront() {
    if (isEmpty()) {
        cout << "List is Empty!\n";
        exit(-1);
    }
    else {
        //暂存
        Node * tmp = head;
        //后移
        head = head->next;
        //释放
        delete tmp;
        tmp = nullptr;
    }
}

void SL::popBack() {
    if (isEmpty()) {
        cout << "List is Empty!\n";
        exit(-1);
    }
    //只有一个节点时
    else if (head->next == nullptr) {
        popFront();
    }
    else {
        Node * preTail = head;
        while (preTail->next->next != nullptr) {
            preTail = preTail->next;
        }
        //找到前驱
        Node * tmp = preTail->next;
        preTail->next = tmp->next;
        delete tmp;
        tmp = nullptr;
    }
}

void SL::makeEmpty() {
    while (!isEmpty()) {
        cout << head->data << " ";
        popFront();
        // popBack();
        cout << "Has Been Poped!\n";
    }
    cout << "List has been made empty!\n";
}

void SL::insertThisPos(int pos, DataType x) {
    //在第0个位置插入的情况
    if (pos == 0) {
        pushFront(x);
    }
    else {
        int i;
        Node * pre = nullptr;
        for (i = 1, pre = head; i < pos && pre != nullptr; i++, pre = pre->next) {
            ;
        }
        //退出循环的条件有两个：
        // 1. i == pos;
        // 2. pre == nullptr;

        //以下这两个条件都满足，则下标存在
        //pos->next是第pos个元素
        if (pre != nullptr && i == pos) {
            Node * newNode = new Node(x);
            newNode->next = pre->next;
            pre->next = newNode;
        }
        // 否则，不存在
        else {
            cout << pos << " Posiont is not exist!\n";
            exit(-1);
        }
    }
}

void SL::deleteThisPos(int pos) {
    //表空，不允许操作
    if (isEmpty()) {
        cout << "List is empty!\n";
        exit(-1);
    }
    //表非空
    //删除第一个元素
    if (pos == 0) {
        popFront();
    }
    //删除其他元素
    else {
        int i;
        Node * pre;
        for (i = 1, pre = head; i < pos && pre != nullptr; i++, pre = pre->next) {
            ;
        }

        //找到要删除元素的前驱
        //考虑删除时，还要考虑第pos位上的元素是否为空，即pre->next是否为空
        if (pre != nullptr && pre->next != nullptr && i == pos) {
            Node * tmp = pre->next;
            pre->next = tmp->next;
            delete tmp;
            tmp = nullptr;
        }
        else {
            cout << pos << " Posiont is not exist!\n";
            exit(-1);
        }
    }
}

bool SL::isEmpty() {
    return head == nullptr;
}