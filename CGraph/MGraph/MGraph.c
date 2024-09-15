#include "MGraph.h"
//建立一个空图，传入参数图的二级指针，把图里的顶点表和边表全部置空
void MGInit(MG ** g) {
    *g = (MG *)malloc(sizeof (MG));
    (*g)->listV = (VNode *)malloc(sizeof (VNode) * MAX);
    memset((*g)->Edges, 0, sizeof ((*g)->Edges));
    memset((*g)->listV, 0, sizeof ((*g)->listV) * MAX);
}
int countVertices = 0;
//把输入的x放在顶点表下标为i的位置上
void MGCreateVertices(MG ** g, MGDataType x) {
    (*g)->listV[countVertices].data = x;
    (*g)->listV[countVertices].visited = false;
    countVertices++;
}
//根据start和end建立序号start和end之间的路径，如果图为无向图，还要建立end与start之间的路径
void MGCreateEdges(MG ** g, int start, int end) {
    //建立一个无向图的边
    (*g)->Edges[start][end] = 1;
    (*g)->Edges[end][start] = 1;
}
//使用MGCreateVertices()和MGCreateEdges()创建一个图
void MGCreateGraph(MG ** g) {
    // 建立顶点表
    MGCreateVertices(g, 's');
    MGCreateVertices(g, 'a');
    MGCreateVertices(g, 'b');
    MGCreateVertices(g, 'c');
    MGCreateVertices(g, 'd');
    // 建立边表
    MGCreateEdges(g, 0, 1);
    MGCreateEdges(g, 0, 2);
    MGCreateEdges(g, 0, 3);

    MGCreateEdges(g, 1, 4);
    MGCreateEdges(g, 2, 4);
    MGCreateEdges(g, 3, 4);

}

//打印图的内容
void MGPrint(const MG * g) {
    int i, j;
    printf(" ");
    for (i = 0; i < MAX; i++) {
        printf(" %c", g->listV[i].data);
    }
    printf("\n");
    for (i = 0; i < MAX; i++) {
        printf("%c ", g->listV[i].data);
        for (j = 0; j < MAX; j++) {
            printf("%d ", g->Edges[i][j]);
        }
        printf("\n");
    }
}

bool visited[MAX];
