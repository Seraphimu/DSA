#include "LGraph.hpp"

void Graph::addVertiecs(DataType x) {
    //创建一个节点
    VNode * newNode = new VNode(x);
    //把节点放入存放顶点的数组中
    listVNode[cntVNode++] = newNode;
}

void Graph::addEdges(VNode * start, VNode * end) {
    //以start->firstEdge指向的元素为头指针，插入边可用头插法在firstEdge之前插入
    //分配一个数据域为end的节点，把它接在相邻顶点的后面
    ENode * newNode = new ENode(end);
    newNode->next = start->firstEdge;
    start->firstEdge = newNode;
    //由于是无向图，所以要对end做和start一样的操作
    newNode = new ENode(start);
    newNode->next = end->firstEdge;
    end->firstEdge = newNode;
}

void Graph::createGraph() {
    addVertiecs('S');
    addVertiecs('A');
    addVertiecs('B');
    addVertiecs('C');
    addVertiecs('D');

    //加入边的操作中没有加去重，所以只加一遍防止bug罢（悲
    addEdges(listVNode[0], listVNode[1]);
    addEdges(listVNode[0], listVNode[2]);
    addEdges(listVNode[0], listVNode[3]);
    addEdges(listVNode[1], listVNode[4]);
    addEdges(listVNode[2], listVNode[4]);
    addEdges(listVNode[3], listVNode[4]);
}

void Graph::disGraph() {
    ENode * cur;
    //遍历顶点数组
    for (int i = 0; i < cntVNode; i++) {
        cout << listVNode[i]->data << "-> ";
        //用cur指向firstEdge，遍历整个邻接表
        cur = listVNode[i]->firstEdge;
        while (cur != nullptr) {
            // cout << "{Ptr: " << cur->ptrVNode << ", value: " << cur->ptrVNode->data << "}" << "-> ";
            
            cout << cur->ptrVNode->data << "-> ";
            cur = cur->next;
        }
        cout << "\n";
    }
}