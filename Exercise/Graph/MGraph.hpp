#include <iostream>
using namespace std;
#define MAXV 4

typedef struct {
    int numVertices, numEdges;		//顶点数，有向边数
    char VerticesList[MAXV];		//顶点表
    int Edge[MAXV][MAXV];			//邻接矩阵（边表）
}MGraph;

void addEdges(MGraph ** G, int start, int end);
void addVertices(MGraph ** G, char x);
void createGraph(MGraph * G);
void displayGraph(MGraph * G);
int printVertices(MGraph G);
