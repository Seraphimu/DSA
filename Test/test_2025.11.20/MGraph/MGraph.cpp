#include "MGraph.hpp"

void Graph::addEdges(int start, int end) {
    adjMaritx[start][end] = 1;
}

void Graph::addVertices(DataType x) {
    listVertices[cntVertices++]->data = x;
}

void Graph::disGraph() {
    
}