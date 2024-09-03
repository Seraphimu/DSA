#include "MGraph.hpp"

void test() {
    MGraph * G = new MGraph();
    createGraph(G);
    displayGraph(G);
    cout << "K Vertex:\n";
    cout << "all of this is " << printVertices(*G);
}

int main(void) {
    test();

    return 0;
}