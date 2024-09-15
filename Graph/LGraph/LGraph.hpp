#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

typedef char DataType;

class VNode;
class ENode;

//顶点描述
class VNode {
private:
    DataType data;
    ENode * firstEdge;
    
    friend class Graph;
    friend class ENode;
public:
    VNode (DataType x) {
        data = x;
        firstEdge = nullptr;
    }
};

//边描述
class ENode {
private:
    //邻接链表中存放与顶点相邻的指针
    VNode * ptrVNode;
    ENode * next;
    friend class Graph;
    friend class VNode;
public:
    ENode(VNode * x) {
        ptrVNode = x;
        next = nullptr;
    }
};

//图描述

class Graph {
private:
    //存放顶点的链表
    vector<VNode *> listVertices;
public:

    void addVertices(DataType x);
    void addEdges(VNode * start, VNode * end);
    void createGraph();
    void disGraph();
};

