#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define MAX 5
using namespace std;
//顶点存放的数据
typedef char DataType;

//前向声名
class ENode;
class VNode;

//边描述
class ENode {
private:
    //存放相邻顶点的指针
    VNode * ptrVNode;
    //指向下一个顶点的指针
    ENode * next;
    friend class VNode;
    friend class Graph;
public:
    ENode(VNode * newNode) {
        ptrVNode = newNode;
        next = nullptr;
    }
};

//顶点描述
class VNode {
private:
    // 存放顶点要存放的数据
    DataType data;
    //访问信息（遍历时用
    bool visited;
    // 指向邻接顶点的指针
    ENode * firstEdge;
    friend class ENode;
    friend class Graph;
public:
    VNode(DataType x) {
        data = x;
        visited = false;
        firstEdge = nullptr;
    }
};



class Graph {
private:
    // 存放顶点的指针
    VNode * listVNode[MAX];
    int cntVNode;
public:
    Graph() {
        cntVNode = 0;
    }
    // 添加顶点和边
    void addVertiecs(DataType x);
    //在边中存储以VNode *类型的数据为数据的节点
    void addEdges(VNode * start, VNode * end);
    //创建图
    void createGraph();
    //打印图
    void disGraph();
    //遍历
    void BFS();
    void DFS();
};