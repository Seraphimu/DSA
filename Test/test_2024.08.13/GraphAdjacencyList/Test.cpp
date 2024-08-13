// #include "GAL.hpp"
//包错头文件，害我调试半天
// #include "LGraph.cpp"
#include "LGraph.hpp"

void test() {
    Graph * g = new Graph();
    g->createGraph();

    cout << "Graph is: \n";
    g->disGraph();
    cout << "\n";
}

int main(void) {
    test();

    return 0;
}