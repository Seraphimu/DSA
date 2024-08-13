#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>

#define MAX 5
using namespace std;

class Vertex {
private:
    char value;
    bool visited;
    friend class Graph;
public:
    Vertex(char value) {
        this->value = value;
    }
};

class Graph {
private:
    //存放顶点指针的数组
    Vertex * listVertices[MAX];
    //存放边的矩阵
    int adjMatrix[MAX][MAX];
    //顶点的数量
    int vertexCount;
    //加边
    void addEdges(int start, int end);
    //加顶点
    void addVertices(char value);
public:
    Graph() {
        vertexCount = 0;
        memset(adjMatrix, 0, sizeof(adjMatrix));
    }
    void createGraph();
    void disGraph();

    int getAdjUnvisitedVertex(int vertexIndex);
    void DFS();
    void BFS();
};