#include "SeqList.hpp"

void test() {
    SL * s = new SL();

    s->pushBack(100);
    s->pushBack(2);
    s->pushBack(-3);
    s->pushBack(40);
    s->pushBack(5);
    s->pushBack(-10);
    
    cout << "prev operation: \n";
    s->print();

    // s->insertThisPos(3, 9);

    // s->deleteThisPos(0);
    // s->deleteThisPos(2);
    // s->deleteThisPos(3);
    // s->deleteThisPos(5);
    
    // cout << "looing for 0: " << s->searchByPos(0) << "\n";
    // cout << "looing for 1: " << s->searchByPos(1) << "\n";
    // cout << "looing for 2: " << s->searchByPos(2) << "\n";
    // cout << "looing for 3: " << s->searchByPos(3) << "\n";
    // cout << "looing for 4: " << s->searchByPos(4) << "\n";
    // cout << "looing for 5: " << s->searchByPos(5) << "\n";
    // // cout << "looing for 6: " << s->searchByPos(6) << "\n";
    // cout << "looing for -1: " << s->searchByPos(-1) << "\n";

    // for (int i = 0; i <= 6; i++) {
    //     cout << "looking for " << i << " " << s->searchByPos(i) << "\n";
    // }

    // cout << s->searchByValue(114514) << "\n";
    // cout << s->searchByValue(5) << "\n";

    s->insertionSort();

    cout << "after operation: \n";
    s->print();



    s->makeEmpty();
}

int main(void) {
    test();

    return 0;
}