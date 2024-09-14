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


SL * SL::reverseList() {
    if (head == nullptr) {
        return nullptr;
    }
    Node * cur = head;
    SL * newList = new SL();

    while (cur) {
        newList->pushFront(cur->data);
        cur = cur->next;
    }
    
    return newList;


    // if (head == nullptr) {
    //     return head;
    // }
    // Node * p, * q, * tmp;
    // p = nullptr;
    // q = head;
    // tmp = q->next;

    // //处理前n-1个节点
    // while (tmp) {
    //     q->next = p;
    //     p = q;
    //     q = tmp;
    //     tmp = tmp->next;
    // }
    // //处理第n个节点
    // q->next = p;

    // return q;
}


DataType SL::kthToLast(int k) {
    //双指针
    Node * p;
    Node * q;
    p = q = head;

    //思路：双指针
    //让前指针p先走k步
    //再让q指针和p指针一起走到空
    //p要走len - k步才能走到空
    //即让q跟着p走len - k步，即可返回倒数第k个节点
    
    //让p走k步
    while (k > 0) {
        k--;
        p = p->next;
    }

    //p和q一起走len-k步
    while (p) {
        p = p->next;
        q = q->next;
    }

    return q->data;

    // // 先求长再走
    // Node * p;
    // Node * q;
    // p = q = head;
    // //求链表长度
    // int len = 0;
    // while (p) {
    //     p = p->next;
    //     len++;
    // }

    // //返回倒数第k个就是指针走len - k步
    // //链表从头指针走到空要走len步
    // //返回倒1用len - 1
    // //返回倒k用len - k
    // for (int i = 0; i < len - k; i++) {
    //     q = q->next;
    // }

    // return q->data;
}


void SL::deleteNode(Node * node) {
    Node * tmp = node->next;
    //思路：把node的后继节点的数据拷贝至node中，然后把node->next给删除掉
    //换数据
    node->data = tmp->data;
    //指针向后指
    node->next = tmp->next;
    delete tmp;
    tmp = nullptr;
}