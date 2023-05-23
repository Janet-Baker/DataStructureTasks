//难度：3
//要求：在有向图的邻接表存储结构上实现：输出某顶点出发的所有长度等于k的简单路径

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define STACK_INIT_SIZE 100
typedef int Status;

#define MAX_VERTEX_NUM 20
typedef enum {
    DG, DN, AG, AN
} GraphKind;//有向图、有向网、无向图、无向网
typedef struct ArcNode {
    int adjvex;                    //该弧头的位置
    struct ArcNode *nextarc;   //下一条出弧（弧尾相同的下一条弧）
    int info;                //附加信息
} ArcNode;    //弧结点

typedef int VertexType;
typedef struct VNode {
    VertexType data;               //顶点信息
    ArcNode *firstarc;               //第一条出弧
} VNode, AdjList[MAX_VERTEX_NUM];   //邻接表头指针向量

typedef struct {
    AdjList vertices;              //邻接表头指针向量
    int vexnum, arcnum;              //顶点数目和弧的数目
    GraphKind kind;                  //图的种类
} ALGraph;

//返回顶点u在图中的位置,未找到返回-1
int LocateVex(ALGraph G, VertexType u) {
    int i;
    for (i = 0; i < G.vexnum; i++)
        if (G.vertices[i].data == u) return i;
    return -1;
}

//创建有向图
void CreateDG(ALGraph &G) {
    int i, j, k, info;
    VertexType v1, v2;
    ArcNode *p;

    //printf("\n下面分步输入创建有向图的信息：");
    G.kind = DG;
    //printf("\n1.请输入图的顶点个数：");
    scanf("%d", &G.vexnum);
    //printf("\n2.请输入图的弧的个数：");
    scanf("%d", &G.arcnum);
    //printf("\n3.请连续输入%d个顶点（字符型）：",G.vexnum);
    //scanf("%c",&c);	//滤掉换行字符
    for (k = 0; k < G.vexnum; k++)    //邻接表头指针向量初始化
    {
        scanf("%d", &G.vertices[k].data);
        G.vertices[k].firstarc = NULL;
    }

    for (k = 0; k < G.arcnum; k++)        //建立弧结点<v,w>
    {
        //printf("\n建立弧%d,请输入弧的信息,格式为v w info：",k+1);
        //scanf("%c",&c);	//滤掉换行字符
        scanf("%d %d %d", &v1, &v2, &info);
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);    //确定v1,v2在图中的位置
        if (i == -1 || j == -1) {
            printf("\n输入弧信息非法，程序退出！");
            break;
        }
        p = (ArcNode *) malloc(sizeof(ArcNode));
        //这里插入你的生成节点代码（邻接表插入弧结点）
        p->adjvex = j;            //弧头
        p->nextarc = G.vertices[i].firstarc;  //出弧
        G.vertices[i].firstarc = p;  //头插入法
        //代码插入结束
    }
}

//按邻接表的形式输出无向图
void PrintAG(ALGraph G) {
    ArcNode *p;
    printf("\n无向图G的邻接表形式：");
    for (int i = 0; i < G.vexnum; i++) {
        printf("\n %d", G.vertices[i].data);
        if (G.vertices[i].firstarc) {
            printf("-->");
            for (p = G.vertices[i].firstarc; p; p = p->nextarc) {
                printf("%d", G.vertices[p->adjvex].data);
                if (p->nextarc) printf("-->");
            }
        }
    }
    printf("\n");
}

//返回v（顶点位置）的第一个邻接顶点的位置，若无返回-1
int FirstAdjVex(ALGraph G, int v) {
    ArcNode *p;
    p = G.vertices[v].firstarc;
    if (p) return p->adjvex;
    else return -1;
}

//返回v相对于w（顶点位置）的下一个邻接顶点的位置，若无返回-1
int NextAdjVex(ALGraph G, int v, int w) {
    ArcNode *p;
    for (p = G.vertices[v].firstarc; p->nextarc; p = p->nextarc)
        if (p->adjvex == w) return p->nextarc->adjvex;

    return -1;
}

VertexType Path[MAX_VERTEX_NUM];
int p;
int visited[MAX_VERTEX_NUM];

//level表明当前递归调用的层次，初值为1，也即v出发的路径长度
//此算法找到全部v出发长度为k的的路径
void DFS(ALGraph G, int v, int k, int level) {
//这里插入你的代码
    visited[v] = 1;
    if (level == k) {
        printf("%d", Path[0]);
        for (int i = 1; i < p; i++) printf("->%d", Path[i]);
        printf("\n");
    }
    for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)) {
        if (!visited[w]) {
            Path[p++] = G.vertices[w].data;
            DFS(G, w, k, level + 1);
            visited[w] = 0;
            p--;
        }
    }
}

//打印vi出发的所有长度为k的简单路径
Status PathDFS(ALGraph G, VertexType v, int k) {
    int i;
    for (i = 0; i < G.vexnum; i++) visited[i] = 0;    //初始化顶点访问标志
    p = 0;
    i = LocateVex(G, v);    //确定vi在图中的位置
    if (i == -1) {
        printf("\n输入顶点信息非法，程序退出！");
        return FALSE;
    }

    Path[p++] = G.vertices[i].data;
    DFS(G, i, k, 1);    //从i出发深度优先搜索
    return TRUE;
}

int main() {
    int k;
    VertexType v;

    ALGraph G;
    CreateDG(G);
    //PrintAG(G);

    while (1) {    //printf("\n求v出发的所有长度为k的简单路径,请输入v k：");
        //scanf("%c",&v);//过滤换行符
        scanf("%d %d", &v, &k);
        PathDFS(G, v, k);

    } //while
    printf("\n");
    return 1;
}
