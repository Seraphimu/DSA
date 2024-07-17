#include "HashTable.h"

void Test()
{
    HT H;
    HTInit(&H);
    HTInsert(&H, 114);
    HTInsert(&H, 514);
    HTInsert(&H, 1919);
    HTInsert(&H, 810);
    HTInsert(&H, 114514);
    HTInsert(&H, 1919810);
    HTInsert(&H, 14);


    for (int i = 0; i < MAX; i++)
        printf("H.elem[%d] = %d\n", i, H.elem[i]);

    HTSearch(&H, 14);
    
}

int main(void)
{
    Test();

    return 0;
}
