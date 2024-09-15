#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#define MAX 5
using namespace std;

typedef char DataType;

//顶点
class VNode {
private:
    //顶点存放的数据
    DataType data;
    //是否被访问过的标记
    bool visited;
    friend class Graph;

public:
    VNode(DataType x) {
        data = x;
        visited = false;
    }
};

class Graph {
private:
    //用一维数组描述顶点，用其下标对应在邻接矩阵中的位置
    //DataType为顶点中存放的数据的类型
    //一个指针数组，存放所有顶点的指针
    VNode * lsitVertices[MAX];
    
    //存放当前顶点的个数
    int cntVertices;

    //用邻接矩阵描述边
    //例如adjMaritx[i][j]，表示从i到j是否存在路径，如果存在，则值为1，不存在则为0
    //亦可存放权值，非0表示有路径
    int adjMaritx[MAX][MAX];
public:
    //初始化，建立一个一个一个空图
    Graph() {
        cntVertices = 0;
        memset(adjMaritx, 0, sizeof(adjMaritx));
    }
    //添加边，给出边的两个端点，即存放顶点指针的下标
    void addEdges(int start, int end);
    //添加顶点，给出顶点存放的数据
    void addVertices(DataType x);
    //创建图
    void createGraph();
    //打印图
    void disGraph();

    //遍历图
    void DFS();
    void BFS();
    //寻找未被访问的顶点
    int getUnvisited(int index);
};