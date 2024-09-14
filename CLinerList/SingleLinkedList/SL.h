#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node {
	DataType data;
	struct Node * next;
}Node;

//初始化链表（建立一个一个一个空表）
void SLInit(Node ** PPHead);

//分配节点函数
Node * SLBuyNode(DataType x);

//头插法
void SLPushBack(Node ** PPHead, DataType x);
