#include "LGraph.hpp"

void test() {
    Graph * g = new Graph();
    g->createGraph();

    cout << "Graph is: \n";
    g->disGraph();
}

int main(void) {
    test();

    return 0;
}