#include "SL.h"

void SLInit(Node ** PPHead) {
    *PPHead = NULL;
}

//分配节点函数
Node * SLBuyNode(DataType x) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	//分配失败
	if (newNode == NULL) {
		printf("Malloc failed!\n");
		exit(-1);
	}

	//能走到这里，程序一切正常，分配成功
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}

//头插法
void SLPushBack(Node ** PPHead, DataType x) {
	//分配节点
	Node * newNode = SLBuyNode(x);
	//新节点指针域指向头指针
	newNode->next = *PPHead;
	//重置头指针为newNode
	*PPHead = newNode;	
}
