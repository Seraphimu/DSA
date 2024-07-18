#include "SingleLinkedList.hpp"

void SingleLinkedList::Init() {
    Head = nullptr;
}

bool SingleLinkedList::IsEmpty() {
    return Head == nullptr;
}

void SingleLinkedList::Print() {
    Node * Cur = Head;
    while (Cur != nullptr) {
        cout << Cur->A << "\n";
        Cur = Cur->Next;
    }
}

Node * SingleLinkedList::BuyNode(DataType X) {
    //分配空间，并判断是否成功
    Node * NewNode = (Node *)malloc(sizeof (Node));
    if (NewNode == nullptr) {
        cout << "Malloc Failed!" << "\n";
        exit(-1);
    }
    
    //给节点赋值
    NewNode->A = X;
    NewNode->Next = nullptr;
    
    return NewNode;
}

void SingleLinkedList::PushFront(DataType X) {
    Node * NewNode = BuyNode(X);
    NewNode->Next = Head;
    Head = NewNode;
}

void SingleLinkedList::PushBack(DataType X) {
    //表空
    if (IsEmpty()) {
        Head = BuyNode(X);
    }
    //非空
    else {
        Node * Cur = Head;
        //Cur->Next为空时，找到尾节点，退出循环
        while (Cur->Next != nullptr) {
            Cur = Cur->Next;
        }
        
        Node * NewNode = BuyNode(X);
        Cur->Next = NewNode;
    }
}

void SingleLinkedList::PopFront() {
    //表空
    if (IsEmpty()) {
        cout << "List Is Empty!\n";
        exit(-1);
    }
    
    //非空
    Node * Tmp = Head;
    Head = Head->Next;
    free(Tmp);
    Tmp = nullptr;
}

void SingleLinkedList::MakeEmpty() {
    if (IsEmpty()) {
        cout << "List Is Empty!\n";
        exit(-1);
    }
    
    while (!IsEmpty()) {
        cout << Head->A << " ";
        PopFront();
        cout << "Has Been Poped!\n";
    }
    cout << "Make Empty Successfully!\n";
}

void SingleLinkedList::PopBack() {
    //表为空
    if (IsEmpty()) {
		cout << "List Is Empty!\n";
        exit(-1);
    }
    
    //只有一个节点
    if (Head->Next == nullptr) {
        free(Head);
        Head = nullptr;
    }
    //有两个及以上个节点
    else {
        Node * Cur = Head;
        //找倒数第二个节点
        while (Cur->Next->Next != nullptr) {
            Cur = Cur->Next;
        }
        //保存倒数第一个节点
        Node * Tmp = Cur->Next;
        //把倒数第二个节点指向空指针，Tmp指向尾节点，故其指针域为空指针
        Cur->Next = Tmp->Next;
        //释放
        free(Tmp);
        Tmp = nullptr;
    }
}

void SingleLinkedList::InsertThisPos(int Pos, DataType X) {
    if (Pos == 0) {
        PushFront(X);
    }
	else {
        int i;
        Node * Pre;
        for (i = 1, Pre = Head; i < Pos && Pre != nullptr; i++, Pre = Pre->Next) {
            ;
        }
        //退出循环时，不是i == Pos, 就是 Pre == nullptr
        if (Pos == i && Pre != nullptr) {
            Node * NewNode = BuyNode(X);
            NewNode->Next = Pre->Next;
            Pre->Next = NewNode;
        }
        else {
            cout << Pos << " Posiont is not exist!\n";
            exit(-1);
        }
    }
}

void SingleLinkedList::DeleteThisPos(int Pos) {
    //判空
    if (IsEmpty()) {
        cout << "List Is Empty!\n";
    	exit(-1);
    }
    
    //非空，删除第0个元素
    if (Pos == 0) {
        PopFront();
    }
    else {
        //非空，删除第N个元素（N > 0）
        int i = 0;
        Node * Pre = nullptr;
        for (i = 1, Pre = Head; Pre->Next != nullptr && i < Pos; i++, Pre = Pre->Next) {
            ;
        }
        
        if (i == Pos && Pre->Next != nullptr) {
            Node * Tmp = Pre->Next;
            Pre->Next = Tmp->Next;
            free(Tmp);
            Tmp = nullptr;
        }
        else {
            cout << Pos << " Position is not exist!\n";
        }
    }
    
}

Node * SingleLinkedList::SearchByValue(DataType Target) {
    if (IsEmpty()) {
        cout << "List Is Empty!\n";
        exit(-1);
    }
    
    Node * Cur = Head;
    while (Cur != nullptr) {
        if (Cur->A == Target) {
            return Cur;
        }
        Cur = Cur->Next;
    }
    
    return nullptr;
}

void SingleLinkedList::ModifyByValue(DataType Target, DataType NewValue) {
    Node * Ret = SearchByValue(Target);
    if (Ret == nullptr) {
        cout << "The Target Is Not Exist!\n";
        exit(-1);
    }
    
    Ret->A = NewValue;
}