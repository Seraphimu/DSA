#include "SingleLinkedList.hpp"

//初始化
void SL::SLInit() {
    SLHead = nullptr;
    //头一次把赋值号写成判定等于号！！
    // SLHead == nullptr;
    //这里踩了个大坑
    // SLHead->Next == nullptr;
}

//分配节点
Node * SL::SLBuyNode(DataType X) {
    Node * NewNode = (Node *)malloc(sizeof (Node));

    //分配失败
    if (NewNode == nullptr) {
        cout << "Malloc Error!" << endl;
        exit(-1);
    }

    //建立节点
    NewNode->A = X;
    NewNode->Next = nullptr;

    return NewNode;
}

void SL::SLPushFront(DataType X) {
    //头插不用考虑各种特殊情况，即使表头为空，也可以如此操作
    Node * NewNode = SLBuyNode(X);

    NewNode->Next = SLHead;
    SLHead = NewNode;
}

void SL::SLPushBack(DataType X) {
    if (SLIsEmpty()) {
        SLHead = SLBuyNode(X);
    }
    else {
        Node * SLTail = SLHead;
        Node * NewNode = SLBuyNode(X);
        //表尾指针域为0
        while (SLTail->Next != nullptr) {
            SLTail = SLTail->Next;
        }

        // 找到表尾
        SLTail->Next = NewNode;
    }
}

void SL::SLPopFront() {
    if (SLIsEmpty()) {
        cout << "List Is empty" << endl;
        return;
    }

    Node * Tmp = SLHead;
    SLHead = SLHead->Next;
    free(Tmp);
}


void SL::SLMakeEmpty() {
    if (SLIsEmpty()) {
        cout << "List Is Empty!" << endl;
        return;
    }
    while (!SLIsEmpty()) {
        SLPopFront();
    }
}


void SL::SLModifyByValue(DataType NowValue, DataType NewValue) {
    Node * Tmp = SLSearchByValue(NowValue);

    //如果查找成功，则说明：
    //1. 表非空
    //2. 值存在

    if (Tmp) {
        Tmp->A = NewValue;
    }
    
}

Node * SL::SLSearchByValue(DataType Value) {
    if (SLIsEmpty()) {
        cout << "List Is Empty" << endl;
        return nullptr;
    }

    //遍历链表，对比各个值，若当前值匹配成功，则返回当前节点的指针，反之返回空
    Node * Cur = SLHead;
    while (Cur) {
        if (Cur->A == Value) {
            return Cur;
        }
        else {
            Cur = Cur->Next;
        }
    }

    //如果在循环中没有返回Cur，则表明表中没有符合条件的值
    cout << "Value is Not Exist!" << endl;
    return Cur;
}

void SL::SLInsertPos(Node * Pos, DataType X) {
    //如果头节点为空，直接调用头插
    if (Pos == SLHead) {
        SLPushFront(X);
    }
    else {
        //头节点不空，且位置合法
        if (SLPosErr(Pos)) {
            cout << "Pos Error!" << endl;
            return;
        }
        Node * PrePos = SLHead;
        
        //要找到Pos的前一个节点
        while (PrePos != nullptr && PrePos->Next != Pos) {
            PrePos = PrePos->Next;
        }
        
        //查找成功
        if (PrePos != nullptr && PrePos->Next == Pos) {
            Node * NewNode = SLBuyNode(X);
            //插入节点
            NewNode->Next = Pos;
            PrePos->Next = NewNode;
        }
    }
}

Node * SL::SLSearchByPos(int Pos) {
    int i;
    Node * Cur;
    for (i = 0, Cur = SLHead; i < Pos && Cur; i++, Cur = Cur->Next) {
        ;
    }

    if (i == Pos) {
        return Cur;
    }
    else {
        cout << "Pos is not Exist!" << endl;
        return nullptr;
    }
}


bool SL::SLIsEmpty() {
    return SLHead == nullptr;
    // return SLHead->Next == nullptr;
}

void SL::SLPrint() {
    Node * Cur = SLHead;

    while (Cur != nullptr) {
        cout << Cur->A << " ";
        Cur = Cur->Next;
    }

    cout << endl;
}

bool SL::SLPosErr(Node * Pos) {
    if (Pos == nullptr) {
        return false;
    }

    Node * Cur = SLHead;

    //从头到尾遍历链表节点，找到相同的就返回匹配成功返回false
    while (Cur) {
        if (Pos == Cur) {
            return false;
        }
        Cur = Cur->Next;
    }
    //找不到返回true
    return true;
}

int SL::SLLength() {
    int i = 0;
    Node * Cur = SLHead;
    while (Cur) {
        Cur = Cur->Next;
        i++;
    }

    return i;
}
