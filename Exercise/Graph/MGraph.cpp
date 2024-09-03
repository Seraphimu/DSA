#include "MGraph.hpp"

int cntVertices = 0;

void addEdges(MGraph ** G, int start, int end) {

    (*G)->Edge[start][end] = 1;
    // (*G)->Edge[end][start] = 1;
}

void addVertices(MGraph ** G, char x) {
    //添加顶点，给定x
    //1. 创建一个存放数据x的顶点
    //2. 把顶点放入数组中
    (*G)->VerticesList[cntVertices++] = x;
}

void createGraph(MGraph * G) {
    addVertices(&G, 'a');
    addVertices(&G, 'b');
    addVertices(&G, 'c');
    addVertices(&G, 'd');

    addEdges(&G, 0, 1);
    addEdges(&G, 0, 3);
    addEdges(&G, 1, 2);
    addEdges(&G, 1, 3);
    addEdges(&G, 2, 3);
}

void displayGraph(MGraph * G) {
    int i, j;
    cout << "Graph is: \n";
    cout << "  ";
    for (i = 0; i < MAXV; i++) {
        cout << G->VerticesList[i] << " ";
    }
    cout << "\n";
    for (i = 0; i < MAXV; i++) {
        cout << G->VerticesList[i] << " ";
        for (j = 0; j < MAXV; j++) {
            cout << G->Edge[i][j] << " ";
        }
        cout << "\n";
    }
}

int printVertices(MGraph G) {
    int i, j, in, out;
    int count = 0;
    for (i = 0; i < MAXV; i++) {
        in = 0;
        out = 0;
        for (j = 0; j < MAXV; j++) {
            //计算顶点Vertex[i]的出度
            if (0 != G.Edge[i][j]) {
                out++;
            }
            //入度
            if (0 != G.Edge[j][i]) {
                in++;
            }
        }

        //一轮之后比较in和out的值
        if (out > in) {
            count++;
            cout << G.VerticesList[i] << " ";
        }
    }

    cout << " \n";

    return count;
}