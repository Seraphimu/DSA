#include <iostream>
#include <vector>

using namespace std;

// 定义图的顶点和边的结构体
struct EdgeNode {
    int adjvex;     // 邻接点的索引
    EdgeNode* next;   // 指向下一个邻接点的指针

    EdgeNode(int x) : adjvex(x), next(NULL) {}
};

struct Vertex {
    string info;      // 顶点的信息
    EdgeNode* firstedge; // 指向第一个邻接点的指针

    Vertex(string s) : info(s), firstedge(NULL) {}
};

class AdjGraph {
private:
    vector<Vertex> vertices; // 顶点数组

public:
    AdjGraph(int num_vertices) : vertices(num_vertices) {}

    // 添加边
    void addEdge(int start, int end) {
        EdgeNode* edge = new EdgeNode(end);
        edge->next = vertices[start].firstedge;
        vertices[start].firstedge = edge;
    }

    // 打印图
    void display() {
        for (int i = 0; i < vertices.size(); ++i) {
            cout << "Vertex " << i << ": ";
            EdgeNode* edge = vertices[i].firstedge;
            while (edge) {
               cout << edge->adjvex << " ";
               edge = edge->next;
            }
            cout << endl;
        }
    }
};

int main() {
    AdjGraph g(5); // 创建一个含有5个顶点的图
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    g.display(); // 打印图

    return 0;
}