#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define MAX 5
using namespace std;
typedef char DataType;

//边
class EdgeNode {
private:
    // 邻接数组下标
    int adjVex;
    // 指向邻接点的指针
    EdgeNode * next;
    friend class Vertex;
    friend class Graph;
public:
    EdgeNode (int x) {
        adjVex = x;
        next = nullptr;
    }
};

//顶点
class Vertex {
private:
    // 顶点信息
    DataType info;
    // 指向第一个邻接点的指针
    EdgeNode * firstedge;
    friend class EdgeNode;
    friend class Graph;
public:
    Vertex(DataType x) {
        info = x;
        firstedge = nullptr;
    }
};

class Graph {
private:
    Vertex * listVertices[MAX];
    int countVertices;
public:
    Graph() {
        countVertices = 0;
    }
    void addEdges(int start, int end);
    void disGraph();
};












// //顶点
// class Vertex {
// private:
//     DataType value;
//     Vertex * next;
//     friend class Graph;
// public:
//     Vertex(DataType value) {
//         this->value = value;
//         next = nullptr;
//     }
// };

// //图
// class Graph {
// private:
//     //顶点数组
//     //也可以尝试这里也用链表
//     Vertex * listVertices[MAX];
//     //顶点个数，初始化为0
//     int vertexCount;
// public:
//     Graph() {
//         vertexCount = 0;
//     }
//     //添加一个数据域为x的顶点
//     void addVertices(DataType x);
//     //添加一个以start和end指针连接的边
//     //遍历链表，尾插，或者头插不用遍历也可以
//     void addEdges(Vertex * start, Vertex * end);
//     void createGraph();
// };