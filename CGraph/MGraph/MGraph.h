#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 5

typedef char MGDataType;
typedef struct VNode {
    MGDataType data;
    bool visited;
}VNode;
typedef struct MGraph {
    VNode * listV;
    int Edges[MAX][MAX];
}MG;


//建立一个空图，传入参数图的二级指针，把图里的顶点表和边表全部置空
void MGInit(MG ** g);
//把输入的x放在顶点表下标为i的位置上
void MGCreateVertices(MG ** g, MGDataType x);
//根据start和end建立序号start和end之间的路径，如果图为无向图，还要建立end与start之间的路径
void MGCreateEdges(MG ** g, int start, int end);
//使用MGCreateVertices()和MGCreateEdges()创建一个图
void MGCreateGraph(MG ** g);
//打印图的内容
void MGPrint(const MG * g);


//栈的数据结构定义
typedef VNode STDataType;

typedef struct STNode {
    STDataType data;
    struct STNode * next;
}ST;

//初始化栈
void STInit(ST ** top);
//入栈（头插法）
void STPush(ST ** top, STDataType x);
//出栈（头删法）
void STPop(ST ** top);
//判空，为空时返回真
bool STIsEmpty(const ST * top);
//置空
void STMakeEmpty(ST ** top);