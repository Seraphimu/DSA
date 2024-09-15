#include "LGraph.hpp"

void Graph::addVertices(DataType x) {
    //分配新顶点
    VNode * newNode = new VNode(x);
    //把顶点存放在顶点表中
    listVertices.push_back(newNode);
}

void Graph::addEdges(VNode * start, VNode * end) {
    //这里是无向图，所以要对相邻的这两个顶点都要进行操作
    //分配新的邻接链表节点
    ENode * newNode = new ENode(end);
    newNode->next = start->firstEdge;
    start->firstEdge = newNode;

    newNode = new ENode(start);
    newNode->next = end->firstEdge;
    end->firstEdge = newNode;
}

void Graph::createGraph() {
    addVertices('S');
    addVertices('A');
    addVertices('B');
    addVertices('C');
    addVertices('D');

    //如果把顶点表用链表来存放的话，这里就不太好处理了，得用list, list->next; list->next->next了
    addEdges(listVertices[0], listVertices[1]);
    addEdges(listVertices[0], listVertices[2]);
    addEdges(listVertices[0], listVertices[3]);
    addEdges(listVertices[1], listVertices[4]);
    addEdges(listVertices[2], listVertices[4]);
    addEdges(listVertices[3], listVertices[4]);
}

void Graph::disGraph() {
    ENode * cur;
    //遍历顶点数组
    for (int i = 0; i < (int)listVertices.size(); i++) {
        cout << listVertices[i]->data << "-> ";
        //用cur指向firstEdge，遍历整个邻接表
        cur = listVertices[i]->firstEdge;
        while (cur != nullptr) {
            // cout << "{Ptr: " << cur->ptrVNode << ", value: " << cur->ptrVNode->data << "}" << "-> ";
            
            cout << cur->ptrVNode->data << "-> ";
            cur = cur->next;
        }
        cout << "\n";
    }
}