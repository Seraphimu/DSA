#include "MGraph.h"

//初始化栈
void STInit(ST ** top) {
    *top = NULL;
}
//入栈（头插法）
void STPush(ST ** top, STDataType x) {
    //分配节点，并用头插法进栈
    ST * newNode = (ST *)malloc(sizeof (ST));
    newNode->data = x;
    newNode->next = *top;
    *top = newNode;
}
//出栈（头删法）
void STPop(ST ** top) {
    if (STIsEmpty(*top)) {
        printf("Stack is Empty!\n");
        exit(-1);
    }

    ST * tmp = *top;
    *top = (*top)->next;
    free(tmp);
    tmp = NULL;
}
//判空
bool STIsEmpty(const ST * top) {
    return top == NULL;
}

//置空
void STMakeEmpty(ST ** top) {
    if (STIsEmpty(*top)) {
        printf("Stack is Empty!\n");
        exit(-1);
    }
    //栈不空就一直用头删法出栈
    printf("Making Empty:\n");
    while (!STIsEmpty(*top)) {
        printf("%c has been poped!\n", (*top)->data.data);
        STPop(top);
    }
    printf("Make Empty Successful");
}