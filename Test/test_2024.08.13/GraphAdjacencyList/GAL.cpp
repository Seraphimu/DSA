#include "GAL.hpp"

void Graph::addEdges(int start, int end) {
    EdgeNode * edge = new EdgeNode(end);
    edge->next = listVertices[start]->firstedge;
    listVertices[start]->firstedge = edge;
}

void Graph::disGraph() {
    for (int i = 0; i < countVertices; i++) {
        cout << "Vertex " << i << ": ";
        EdgeNode * edge = listVertices[i]->firstedge;

        while (edge != nullptr) {
            cout << edge->adjVex << " ";
            edge = edge->next;
        }
        cout << "\n";
    }
}



// void Graph::addVertices(DataType value) {
//     //分配顶点
//     Vertex * newVertex = new Vertex(value);
//     //加入顶点数组
//     listVertices[vertexCount++] = newVertex;
// }

// void Graph::addEdges(Vertex * start, Vertex * end) {
//     //头插法建立连接
//     end->next = start->next;
//     start->next = end;
// } 

// void Graph::createGraph() {
//     addVertices('S');
//     addVertices('A');
//     addVertices('B');
//     addVertices('C');
//     addVertices('D');

//     addEdges(listVertices[0], listVertices[1]);
//     addEdges(listVertices[0], listVertices[2]);
//     addEdges(listVertices[0], listVertices[3]);
//     addEdges(listVertices[1], listVertices[4]);
// }