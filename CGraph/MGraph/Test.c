#include "MGraph.h"

void test() {
    MG * g;
    MGInit(&g);
    MGCreateGraph(&g);
    MGPrint(g);

    ST * st;
    STInit(&st);
    STPush(&st, g->listV[0]);
    STPush(&st, g->listV[1]);
    STPush(&st, g->listV[2]);
    STPush(&st, g->listV[3]);
    STPush(&st, g->listV[4]);

    STMakeEmpty(&st);
}

int main(void) {
    test();

    return 0;
}