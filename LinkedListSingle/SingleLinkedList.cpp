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

Node * SingleLinkedList::GetHead() {
    return Head;
}

Node * SingleLinkedList::ReservedList() {
    if (IsEmpty()) {
        cout << "List Is Empty!\n";
        exit(-1);
    }

    Node * p = nullptr;
    Node * q = Head;
    Node * tmp = q->Next;

    while (tmp != nullptr) {
        q->Next = p;
        p = q;
        q = tmp;
        tmp = tmp->Next;
    }

    q ->Next = p;

    Head = q;

    return q;
}

void SingleLinkedList::DeleteNode(Node * Target) {
    if (Head == nullptr) {
        cout << "List Is Empty!\n";
        exit(-1);
    }
    if (Target == nullptr) {
        cout << "Target is nullptr!\n";
        exit(-1);
    }

    //只有一个节点的时候
    if (Target = Head) {
        delete Target;
        Target == nullptr;
    }
    //有多个节点的时候
    else {
        Node * Tmp = Target->Next;
        Target->A = Tmp->A;
        Target->Next = Tmp->Next;
    }
}

//删除ListA的一部分，并把ListB接入
//思路：找到ListA删除端点a和b的前驱和后继，然后对链表A进行释放操作，再把链表B接入链表A
Node * SingleLinkedList::MergeInBetween(Node * ListA, Node * ListB, int a, int b) {
    if (IsEmpty()) {
        cout << "List Is Empty!\n";
        exit(-1);
    }

    Node * Cur = nullptr;
    Node * aPrev = nullptr;
    Node * bNext = nullptr;

    int i = 0;
    //踩坑，这个地方应该使用闭区间遍历，a和b都是下标
    for (i = 0, Cur = ListA; i <= b && Cur != nullptr; i++, Cur = Cur->Next) {
        //保存第a个节点的前驱
        if (a - 1 == i) {
            aPrev = Cur;
        }
        //保存第b个节点的后继
        if (b == i) {
            bNext = Cur->Next;
        }
    }

    //决断a和b的下标合法性
    //循环结束时i<b，则必定是下标不合法，即使a合法，但是b不合法，也一样无法进行操作
    if (i < b && Cur == nullptr) {
        cout << "Index is Not Exist!\n";
        exit(-1);
    }

    //释放节点
    Node * Tmp = nullptr;
    //释放错了
    // Cur = ListA;
    Cur = aPrev->Next;
    while (Cur != bNext) {
        Tmp = Cur;
        Cur = Cur->Next;
        delete Tmp;
        Tmp = nullptr;
    }

    //ListA的前半部分连接ListB
    aPrev->Next = ListB;
    // aPrev = ListB;       //接错了
    //遍历到ListB的尾节点，并连接ListA的剩余部分
    Cur = ListB;
    while (Cur->Next != nullptr) {
        Cur = Cur->Next;
    }

    Cur->Next = bNext;

    //返回合并后的链表
    return ListA;
}

// Node * SingleLinkedList::MergeSeq(Node * ListA, Node * ListB) {
//     if (ListA == nullptr) {
//         return ListB;
//     }
//     if (ListB == nullptr) {
//         return ListA;
//     }

//     Node * Cur1 = ListA;
//     Node * Cur2 = ListB;
//     Node * Tmp = nullptr;
//     //遍历表2
//     while (Cur2 != nullptr) {
//         while (Cur1 != nullptr) {
//             //插入元素到最左边（头插）
//             //表2的元素大于等于表1中的
//             if (Cur2->A < Cur1->A && Cur1 == Head) {
//                 Tmp = Cur2;
//                 Cur2 = Cur2->Next;

//                 Tmp->Next = ListA;
//                 ListA = Tmp;
//                 //重置索引至表头
//                 Cur1 = ListA;
//             }
//             //表1走到头了
//             else if (Cur2->A > Cur1->A && Cur1->Next == nullptr) {
//                 Cur1->Next = Cur2;
//                 break;
//             }
//             //非递减排序插入
//             else if (Cur2->A >= Cur1->A && Cur2->A <= Cur1->Next->A) {
//                 //临时保存
//                 Tmp = Cur2;
//                 //Cur2后移一位
//                 Cur2 = Cur2->Next;
//                 //插入节点
//                 Tmp->Next = Cur1->Next;
//                 Cur1->Next = Tmp;
//             }

//             Cur1->Next;
//         }

//         //注意这里的变化，不需要
//         // Cur2 = Cur2->Next;
//     }

//     return nullptr;
// }

Node * SingleLinkedList::MergeSeq(SingleLinkedList *& ListA, SingleLinkedList *& ListB) {
    if (ListA->GetHead() == nullptr) {
        return ListB->GetHead();
    }
    if (ListB->GetHead() == nullptr) {
        return ListA->GetHead();
    }

    //用一个新链表比较两个链表的值
    SingleLinkedList * ListC = new SingleLinkedList();
    ListC->Init();

    while (ListA->Head != nullptr) {
        while (ListB->Head != nullptr) {
            if (ListB->Head == nullptr) {
                break;
            }
            //比较两个链表里边的值，小的放C里，然后删除
            if (ListA->Head->A <= ListB->Head->A) {
                ListC->PushBack(ListA->Head->A);
                ListA->PopFront();
            }
            else {
                ListC->PushBack(ListB->Head->A);
                ListB->PopFront();
            }
        }
        if (ListA->Head == nullptr) {
            break;
        }
    }

    //遍历ListC，找到尾节点，插入剩余的表
    if (ListA->Head == nullptr) {
        Node * Tmp = ListC->Head;
        while (Tmp->Next != nullptr) {
            Tmp = Tmp->Next;
        }

        //接入链表
        Tmp->Next = ListB->Head;

    }
    
    if (ListB->Head == nullptr) {
        Node * Tmp = ListC->Head;
        while (Tmp->Next != nullptr) {
            Tmp = Tmp->Next;
        }

        //接入链表
        Tmp->Next = ListA->Head;

    }
    return ListC->Head;
}