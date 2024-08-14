#include "MGraph.hpp"

void test() {
    Graph * g = new Graph();
    g->createGraph();

    cout << "Graph is: \n";
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