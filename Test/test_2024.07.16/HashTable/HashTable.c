#include "HashTable.h"

int m = 0;

//Create a table that is empty.
void HTInit(HT * H)
{
    int i;

    H->elem = (int *)malloc(sizeof(int) * MAX);
    
    for (i = 0; i < MAX; i++)
        H->elem[i] = NULLKEY;
}

//Get the index for the value that will be storaged by mod.
int HTMod(int key)
{
   return key % MAX; 
}

void HTInsert(HT * H, int key)
{
    int addr = HTMod(key);
    while (H->elem[addr] != NULLKEY) //如果当前addr位不为空，则继续+1，找下一个位置
        addr = (addr + 1) % MAX;
    H->elem[addr] = key;             //存入值
}

int HTSearch(HT * H, int target) {
    int i = HTMod(target);

    //Send error when the first NULLKEY has been detected.
    while (i < H->count) {
        if (H->elem[i] == NULLKEY) {
            printf("Target is not exist!");
            return -1;
        }

        if (H->elem[i] == target) {
            printf("index: %d\n", i);
            break;
        }
        //The i is forget the INFTH
        i++;
    }

    return i;
}