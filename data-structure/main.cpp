#include "main.h"

//todo ͼ�Ļ������
//todo ��С�������������㷨��
//todo ���·�����Թ���
//todo ջ���������ı����ǵݹ飩

int data[MAXVEX][MAXVEX]={
        {0,5,INF,7,INF,INF},
        {INF,0,4,INF,INF,INF},
        {8,INF,0,INF,INF,9},
        {INF,INF,5,0,INF,6},
        {INF,INF,INF,5,0,INF},
        {3,INF,INF,INF,1,0}};

/**
 * @brief ���������
 * 
 * @return 
 */
int main(void)
{

//    Stack();
    Graph();
//    free_min_Prim();
//    free_min_Kruskal();
//    maze();
    return 0;
}


void Graph(void)
{
    AdjGraph *aGraph;
    MatGraph mGraph;
    CreateGraphList(aGraph,data,6,10);
    printf("�ڽӱ�");
    DispGraphList(aGraph);
    DestroyGraph(aGraph);

}

void Stack(void)
{
//    SqStack *Stack;
//    float a;
//    InitStack(Stack);
//    Push(Stack,1.0);
//    Pop(Stack,a);
//    printf("%f",a);
    BTNode *b;
    CreateBTree(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("������b:\n");
    DispBTree(b);
    printf("\n����ǵݹ��������:\n");
    PreOrder(b);
    printf("����ǵݹ��������:\n");
    InOrder(b);
    printf("����ǵݹ��������:\n");
    PostOrder(b);
    DestroyBTree(b);
}

void free_min_Prim(void)
{
    MatGraph g;
    int n=6,e=10;
    CreateGraph(g,data,n,e);
    printf("ͼg���ڽӾ���:\n");
    DispGraph(g);
    printf("���ɵ���С��Ϊ:\n");
    Prim(g,0);
}

void free_min_Kruskal(void)
{
    MatGraph g;
    int n=6,e=10;
    CreateGraph(g,data,n,e);
    printf("ͼg���ڽӾ���:\n");
    DispGraph(g);
    printf("���ɵ���С��Ϊ:\n");
    Kruskal(g);
}

void maze(void)
{
    printf("�Թ�������·������:\n");
    mgpath(1,1,M,N);

}

void debug(void)
{


}