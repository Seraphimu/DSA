#include <stdio.h>
#include <stdlib.h>

#define MAX 12
#define NULLKEY -65535

typedef struct HashTable
{
    int * elem;     //存放元素的数组
    int count;      //存放元素的总数
}HT;

void HTInit(HT * H);
int HTMod(int key);
void HTInsert(HT * H, int key);
int HTSearch(HT * H, int target);
