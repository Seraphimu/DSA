#include "Graph.hpp"

void test() {
    Graph * g = new Graph();

    g->createGraph();
    g->disGraph();

    cout << "DFS is: ";
    g->DFS();
    cout << "\n";

    cout << "BFS is: ";
    g->BFS();
    cout << "\n";
}

int main(void) {
    test();

    return 0;
}