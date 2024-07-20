#include "CircularlySingleLinkedList.hpp"

bool CycSingleLinkedList::isEmpty() {
    return head == nullptr;
}

Node * CycSingleLinkedList::buyNode(DataType x) {
    Node * newNode = new Node();
    if (newNode == nullptr) {
        cout << "new Error!\n";
        exit(-1);
    }
    
    newNode->a = x;
    newNode->next = nullptr;
    
    return newNode;
}

void CycSingleLinkedList::pushFront(DataType x) {
    //为空
    if (isEmpty()) {
		Node * newNode = buyNode(x); 
        newNode->next = newNode;
        head = newNode;
    }
    //非空
    else {
        Node * newNode = buyNode(x);
        Node * tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        
        newNode->next = head;
        tail->next = newNode;
        //头指针指向新节点
        head = newNode;
    }
}


void CycSingleLinkedList::popFront() {
    if (isEmpty()) {
        cout << "List iS empty!\n";
        exit(-1);
    }
    
    //只有一个节点时
    if (head->next == head) {
        delete head;
        head = nullptr;
    }
    //有多个节点
    else {
        Node * tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }

        //使用临时变量暂存head
        Node * tmp = head;
        //head后移一位
        head = head->next;
        //尾节点指针域指向头指针，保持循环特性
        tail->next =head;
        //释放之前的head
        delete tmp;
        tmp = nullptr;
    }
}

void CycSingleLinkedList::pushBack(DataType x) {
    if (isEmpty()) {
        pushFront(x);
    }
}

void CycSingleLinkedList::printList() {
	if (isEmpty()) {
        cout << "List Is Empty!\n";
        exit(-1);
    }
    
    Node * cur = head;
    do {
        cout << cur->a << " ";
        cur = cur->next;
    } while (cur != head);
    
    cout << "\n";
}


void CycSingleLinkedList::makeEmpty() {
    if (isEmpty()) {
        cout << "List is Empty!\n";
        exit(-1);
    }
    
    while (!isEmpty()) {
        cout << head->a;
        popFront();
        cout << " Has been poped!\n";
    }
    cout << "Make Empty Successfully!\n";
}