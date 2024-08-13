#include "Graph.hpp"

//无向图，两头接
void Graph::addEdges(int start, int end) {
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

void Graph::addVertices(char value) {
    //创建一个顶点
    Vertex * newVertex = new Vertex(value);
    //标记为未访问
    newVertex->visited = false;
    //把顶点指针存放在数组中
    listVertices[vertexCount++] = newVertex;
}

void Graph::createGraph() {
    // S A B C D
    // 0 1 2 3 4
    // 加顶点
    addVertices('S');
    addVertices('A');
    addVertices('B');
    addVertices('C');
    addVertices('D');

    // 加边
    addEdges(0, 1);
    addEdges(0, 2);
    addEdges(0, 3);
    addEdges(1, 4);
    addEdges(2, 4);
    addEdges(3, 4);
}

void Graph::disGraph() {
    for (int i = 0; i < vertexCount; i++) {
        cout << listVertices[i]->value << " ";
    }
    cout << "\n";
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

//判断一个顶点是否被访问过，没访问过返回顶点下标，访问过返回-1
//传入要被判断的顶点的下标，即第几行，然后遍历一整个列的下标，直到找到一个未访问的，或者发现没有未被访问的顶点
int Graph::getAdjUnvisitedVertex(int vertexIndex) {
    int i;
    for (i = 0; i < vertexCount; i++) {
        if (adjMatrix[vertexIndex][i] == 1 && listVertices[i]->visited == false) {
            return i;
        }
    }

    return -1;
}

void Graph::DFS() {
    stack<int> stackVertex;
    //第一个顶点访问
    listVertices[0]->visited = true;
    //打印第一个顶点元素
    cout << listVertices[0]->value << " ";
    //把顶点下标入栈
    stackVertex.push(0);

    //当栈不空时，持续执行
    while (!stackVertex.empty()) {
        //判断当栈顶的顶点是否被访问过，被访问过就弹出
        int unvisitedVertex = getAdjUnvisitedVertex(stackVertex.top());
        if (unvisitedVertex == -1) {
            stackVertex.pop();
        }
        //没有被访问过就继续访问
        else {
            //标记被访问
            listVertices[unvisitedVertex]->visited = true;
            //打印顶点
            cout << listVertices[unvisitedVertex]->value << " ";
            //入栈，找找
            stackVertex.push(unvisitedVertex);
        }

    }

    // 遍历完毕，把visited位置的值复位
    for (int i = 0; i < vertexCount; i++) {
        listVertices[i]->visited = false;
    }

}

void Graph::BFS() {
    queue<int> queueVertex;

    //标记
    listVertices[0]->visited = true;
    //打印
    cout << listVertices[0]->value << " ";
    //把S入队
    queueVertex.push(0);

    int unvisitedVertex;
    while (!queueVertex.empty()) {
        //获取队头元素
        int tempVertex = queueVertex.front();
        //出队
        queueVertex.pop();
        //获取与队头顶点相邻的顶点
        while ((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {
            //标记
            listVertices[unvisitedVertex]->visited = true;
            //打印
            cout << listVertices[unvisitedVertex]->value << " ";
            //入队
            queueVertex.push(unvisitedVertex);
        }
    }

    // 遍历完毕，把visited位置的值复位
    for (int i = 0; i < vertexCount; i++) {
        listVertices[i]->visited = false;
    }
}