#include "DoubleLinkedList.hpp"

void DoubleLinkedList::Init() {
    Head = nullptr;
}

bool DoubleLinkedList::IsEmpty() {
    return Head == nullptr;
}

Node * DoubleLinkedList::BuyNode(DataType X) {
    Node * NewNode = (Node *)malloc(sizeof (Node));
    if (NewNode == nullptr) {
        cout << "Malloc Failed!\n";
        exit(-1);
    }
    
    NewNode->A = X;
    NewNode->Prev = nullptr;
    NewNode->Next = nullptr;
    
    return NewNode;
}

void DoubleLinkedList::PushFront(DataType X) {
    //表空
    if (IsEmpty()) {
        Node * NewNode = BuyNode(X);
		Head = NewNode;
    }
    //表非空
    else {
        Node * NewNode = BuyNode(X);
        NewNode->Next = Head;
        Head->Prev = NewNode;
        Head = NewNode;
    }
}


void DoubleLinkedList::Print() {
    //表空时返回错误
    if (IsEmpty()) {
        cout << "List Is Empty!\n";
        exit(-1);
    }
    //表非空时遍历链表，并打印每一位元素的值
    Node * Cur = Head;
    while (Cur != nullptr) {
        cout << Cur->A << "\n";
        Cur = Cur->Next;
    }
}

void DoubleLinkedList::PopFront() {
    if (IsEmpty()) {
        cout << "List Is Empty!\n";
        exit(-1);
    }
    
    //非空
    //只有一个元素时
    if (Head->Next == nullptr) {
        free(Head);
        Head = nullptr;
    }
    //有多个元素时
    else {
        //临时变量保存
        Node * Tmp = Head;
        //头指针后移一位
        Head = Head->Next;
        //当前头指针的 Prev域置空
        Head->Prev = nullptr;
        //释放原来的头指针指向的节点
        free(Tmp);
        Tmp = nullptr;
    }
}

void DoubleLinkedList::MakeEmpty() {
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

void DoubleLinkedList::InsertThisPos(int Pos, DataType X) {
    if (Pos < 0) {
        cout << Pos << " Posiont is not exist!\n";
        exit(-1);  
    }
    //表头插入
    if (Pos == 0) {
        PushFront(X);
    }
	else {
        int i;
        //要插入位置的前一位
        Node * PreCur;
        for (i = 1, PreCur = Head; i < Pos && PreCur != nullptr; i++, PreCur = PreCur->Next) {
            ;
        }

        //表尾插入
        if (i == Pos && PreCur->Next == nullptr) {
            Node * NewNode = BuyNode(X);
            //设置新节点的指针域
            NewNode->Next = PreCur->Next;
            NewNode->Prev = PreCur;
            //修改节点之间的关系
            NewNode->Prev->Next = NewNode;
            //这一步在表尾插入时无法使用，对一个空指针取值无意义。
            //// NewNode->Next->Prev = NewNode;
        }
        //表中间插入
        else if (Pos == i && PreCur != nullptr) {
            Node * NewNode = BuyNode(X);
            //设置新节点的指针域
            NewNode->Next = PreCur->Next;
            NewNode->Prev = PreCur;
            //修改节点之间的关系
            NewNode->Prev->Next = NewNode;
            NewNode->Next->Prev = NewNode;
        }
        else {
            cout << Pos << " Posiont is not exist!\n";
            exit(-1);
        }
    }
}

void DoubleLinkedList::DeleteThisPos(int Pos) {
    if (Pos < 0) {
        cout << Pos << " Posiont is not exist!\n";
        exit(-1);  
    }
    //删除首个节点
    if (Pos == 0) {
        PopFront();
    }
	else {
        int i;
        //要删除的节点
		Node * Cur;
        //Cur->Next == nullptr则说明Cur是末尾元素
        for (i = 1, Cur = Head->Next; Cur->Next != nullptr && i < Pos; i++, Cur = Cur->Next) {
            ;
        }
        //是最后一位元素
        if (i == Pos && Cur->Next == nullptr) {
            Node * Tmp = Cur;
            //把倒数第二位元素向空指针，即把倒数第二位元素变成末尾元素
            Cur->Prev->Next = Cur->Next;
            //释放
            free(Tmp);
            Tmp = nullptr;
        }
        //非末尾元素
        else if (i == Pos && Cur->Next != nullptr) {
            Node * Tmp = Cur;
            //设置节点关系
            Cur->Prev->Next = Cur->Next;
            //非末尾元素多这一步，把后继的Prev指针重新设置位置
            Cur->Next->Prev = Cur->Prev;
            //释放
            free(Tmp);
            Tmp = nullptr;
        }
        else {
            cout << Pos << " Posiont is not exist!\n";
            exit(-1);
        }
    }
}

void DoubleLinkedList::PushBack(DataType X) {
    if (IsEmpty()) {
        Node * NewNode = BuyNode(X);
        Head = NewNode;
    }
    else {
        Node * NewNode = BuyNode(X);
        
        Node * Cur = Head;
        //Cur->Next == nullptr时退出循环，即Cur是末尾节点时退出循环
        while (Cur->Next != nullptr) {
            Cur = Cur->Next;
        }
        
        //设置新节点的指针域
        NewNode->Next = Cur->Next;
        NewNode->Prev = Cur;
        //在末尾插入该节点
        Cur->Next = NewNode;
    }
}

void DoubleLinkedList::PopBack() {
    if (IsEmpty()) {
        cout << "List Is Empty!\n";
        exit(-1);
    }
    //只有一个元素时
    if (Head->Next == nullptr) {
        free(Head);
        Head = nullptr;
    }
    else {
        //有多个元素时，遍历到末尾，删除末尾元素。
        Node * Cur = Head;
        while (Cur->Next != nullptr) {
            Cur = Cur->Next;
        }
        
        Cur->Prev->Next = Cur->Next;
        free(Cur);
        Cur = nullptr;
    }
}

Node * DoubleLinkedList::SearchByValue(DataType Target) {
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

void DoubleLinkedList::ModifyByValue(DataType Target, DataType NewValue) {
    Node * Ret = SearchByValue(Target);
    if (Ret == nullptr) {
        cout << "The Target Is Not Exist!\n";
        exit(-1);
    }
    
    Ret->A = NewValue;
}