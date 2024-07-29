#include "SeqList.hpp"

void Test() {
    SL * sl = new SL();
    
    sl->pushBack(1);
    sl->pushBack(2);
    sl->pushBack(3);
    sl->pushBack(4);
    sl->pushBack(5);

}

int main(void) {
    Test();

    return 0;
}