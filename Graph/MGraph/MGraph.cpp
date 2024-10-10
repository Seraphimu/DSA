#include "MGraph.hpp"

void Graph::addEdges(int start, int end) {
    //加边，因为是无向图，故来回都加边
    //有边就把值设置为1，无边就是0
    adjMaritx[start][end] = 1;
    adjMaritx[end][start] = 1;
}

void Graph::addVertices(DataType x) {
    //添加顶点，给定x
    //1. 创建一个存放数据x的顶点
    //2. 把顶点放入数组中

    lsitVertices[cntVertices++] = new VNode(x);
}

void Graph::createGraph() {
    addVertices('S');
    addVertices('A');
    addVertices('B');
    addVertices('C');
    addVertices('D');

    addEdges(0, 1);
    addEdges(0, 2);
    addEdges(0, 3);
    addEdges(1, 4);
    addEdges(2, 4);
    addEdges(3, 4);
}

void Graph::disGraph() {
    //打印顶点
    cout << "  ";
    for (int i = 0; i < cntVertices; i++) {
        cout << lsitVertices[i]->data << " ";
    }
    cout << "\n";
    //打印矩阵（边）
    for (int i = 0; i < cntVertices; i++) {
        cout << lsitVertices[i]->data << " ";

        for (int j = 0; j < cntVertices; j++) {
            cout << adjMaritx[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}



void Graph::BFS() {
    //创建一个存放顶点下标的队列
    queue<int> q;
    //处理第一个顶点
    cout << lsitVertices[0]->data << " ";
    lsitVertices[0]->visited = true;
    q.push(0);

    int unVisited;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        // while ((unVisited = getUnvisited(tmp) != -1)) {      //这么写,遍历到第二个顶点时死循环
        while ((unVisited = getUnvisited(tmp)) != -1) {
            cout << lsitVertices[unVisited]->data << " ";
            lsitVertices[unVisited]->visited = true;
            q.push(unVisited);
        }
    }

    for (int i = 0; i < cntVertices; i++) {
        lsitVertices[i]->visited = false;
    }
}

//找到第index行中有路径且未被访问过的顶点
int Graph::getUnvisited(int index) {
    // 对第index行第i列的顶点逐一扫描，其visited域为false直接返回其在顶点表中的下标
    for (int i = 0; i < cntVertices; i++) {
        if (adjMaritx[index][i] == 1 && lsitVertices[i]->visited == false) {
            return i;
        }
    }

    //没找到返回-1
    return -1;
}


void Graph::DFS() {
    //建立一个栈，存放顶点下标
    stack<int> * s = new stack<int>;
    //处理第一个顶点
    cout << lsitVertices[0]->data << " ";
    lsitVertices[0]->visited = true;
    s->push(0);

    int unVisited;
    while (!s->empty()) {
        unVisited = getUnvisited(s->top());
        if (unVisited == -1) {
            s->pop();
        }
        else {
            s->push(unVisited);
            cout << lsitVertices[unVisited]->data << " ";
            lsitVertices[unVisited]->visited = true;
        }
    }
    //不改回来会影响同一个程序中的其他遍历算法
    for (int i = 0; i < cntVertices; i++) {
        lsitVertices[i]->visited = false;
    }
}












// void Graph::DFS() {
//     //建立一个存放顶点下标的栈
//     stack<int> s;
//     //处理第一个顶点
//     cout << lsitVertices[0]->data << " ";
//     lsitVertices[0]->visited = true;
//     s.push(0);

//     int unVisited;
//     //直至栈空为止
//     while (!s.empty()) {
//         //扫描与栈顶元素有边的顶点,有就返回下标,没有就返回-1
//         unVisited = getUnvisited(s.top());
//         //没有任何顶点与当前顶点有边,则出栈
//         if (unVisited == -1) {
//             s.pop();
//         }
//         //有边则打印、进栈、打访问标记
//         else {
//             cout << lsitVertices[unVisited]->data << " ";
//             lsitVertices[unVisited]->visited = true;
//             s.push(unVisited);
//         }
//     }

//     for (int i = 0; i < cntVertices; i++) {
//         lsitVertices[i]->visited = false;
//     }
// }



// //原版代码保存
// void Graph::DFS() {
//     //存放顶点指针的栈
//     stack<int> s;

//     //让第一个顶点进栈（标记 + 输出）
//     cout << lsitVertices[0]->data << " ";
//     lsitVertices[0]->visited = true;
//     s.push(0);

//     int unVisited;
//     while (!s.empty()) {
//         //遍历寻找与栈顶顶点相邻的顶点
//         unVisited = getUnvisited(s.top());
//         //如果没有符合条件的顶点
//         if (unVisited == -1) {
//             //出栈，回溯到前一个顶点，来判断有没有符合条件的顶点
//             s.pop();
//         }
//         //如果顶点符合条件
//         else {
//             //把下标入栈
//             cout << lsitVertices[unVisited]->data << " ";
//             lsitVertices[unVisited]->visited = true;
//             s.push(unVisited);
//         }
//     }

//     //遍历结束，清除访问标记
//     for (int i = 0; i < cntVertices; i++) {
//         lsitVertices[i]->visited = false;
//     }
// }

// void Graph::BFS() {
//     //存放顶点下标的队列
//     queue<int> q;

//     //处理第一个顶点
//     cout << lsitVertices[0]->data << " ";
//     lsitVertices[0]->visited = true;
//     q.push(0);

//     int unVisted;
//     int tmp;
//     while (!q.empty()) {
//         //临时变量保存队头
//         tmp = q.front();
//         //出队
//         q.pop();
//         //用队头遍历，把每个符合条件的顶点入队
//         while ((unVisted = getUnvisited(tmp)) != -1) {
//             cout << lsitVertices[unVisted]->data << " ";
//             lsitVertices[unVisted]->visited = true;
//             q.push(unVisted);
//         }
//     }

//     //遍历结束，清除访问标记
//     for (int i = 0; i < cntVertices; i++) {
//         lsitVertices[i]->visited = false;
//     }
// }