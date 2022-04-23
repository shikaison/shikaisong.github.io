#include "main.h"

//todo 图的基本设计
//todo 最小生成树（两种算法）
//todo 最短路径（迷宫）
//todo 栈（二叉树的遍历非递归）

int data[MAXVEX][MAXVEX]={
        {0,5,INF,7,INF,INF},
        {INF,0,4,INF,INF,INF},
        {8,INF,0,INF,INF,9},
        {INF,INF,5,0,INF,6},
        {INF,INF,INF,5,0,INF},
        {3,INF,INF,INF,1,0}};

/**
 * @brief 主函数入口
 * 
 * @return 
 */
int main(void)
{

//    Stack();
//    Graph();
//    free_min_Prim();
//    free_min_Kruskal();
    return 0;
}


void Graph(void)
{
    AdjGraph *aGraph;
    MatGraph mGraph;
    CreateGraphList(aGraph,data,10,9);
    printf("邻接表");
    DispGraphList(aGraph);

}

void Stack(void)
{
    SqStack *Stack;
    float a;
    InitStack(Stack);
    Push(Stack,1.0);
    Pop(Stack,a);
    printf("%f",a);
}

void free_min_prim(void)
{
    MatGraph g;
    int n=6,e=10;
    CreateGraph(g,data,n,e);
    printf("图g的邻接矩阵:\n");
    DispGraph(g);
    printf("生成的最小树为:\n");
    Prim(g,0);
}

void free_min_Kruskal(void)
{
    MatGraph g;
    int n=6,e=10;
    CreateGraph(g,data,n,e);
    printf("图g的邻接矩阵:\n");
    DispGraph(g);
    printf("生成的最小树为:\n");
    Kruskal(g);
}

void debug(void)
{


}