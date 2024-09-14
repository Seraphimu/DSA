#include "SL.h"

void test() {
    Node * PList;       //此时plist应该存放了一个随机值
    SLInit(&PList);     //在调用SLInit之后plist会变成空
	SLPushBack(&PList, 1);
	SLPushBack(&PList, 2);
	SLPushBack(&PList, 3);
	SLPushBack(&PList, 4);
	SLPushBack(&PList, 5);
}

int main(void) {
    test();

    return 0;
}
