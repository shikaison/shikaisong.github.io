//
// Created by shikaisong on 2022/4/18.
//


#include "graph.h"



void CreateGraph(MatGraph &g,int A[][MAXVEX],int n,int e)
{
     int i,j;
     g.n=n; g.e=e;
     for (i=0;i<n;i++)
         for (j=0;j<n;j++)
             g.edges[i][j]=A[i][j];
}

void DispGraph(MatGraph g)
{
    int i,j;
    for (i=0;i<g.n;i++)
    {  for (j=0;j<g.n;j++)
            if (g.edges[i][j]<INF)
                printf("%4d",g.edges[i][j]);
            else
                printf("%4s","∞");
        printf("\n");
    }
}

int Degree1(MatGraph g,int v)
{
    int i,d=0;
    if (v<0 || v>=g.n)
        return -1;		 //顶点编号错误返回-1
    for (i=0;i<g.n;i++)
        if (g.edges[v][i]>0 && g.edges[v][i]<INF)
            d++;		//统计第v行既不为0也不为∞的边数即度
    return d;
}

int Degree2(MatGraph g,int v)	 //求有向图中顶点的度
{
    int i,d1=0,d2=0,d;
    if (v<0 || v>=g.n)
        return -1;	//顶点编号错误返回-1
    for (i=0;i<g.n;i++)
        if (g.edges[v][i]>0 && g.edges[v][i]<INF)
            d1++;		//统计第v行既不为0也不为∞的边数即出度
    for (i=0;i<g.n;i++)
        if (g.edges[i][v]>0 && g.edges[i][v]<INF)
            d2++;		//统计第v列既不为0也不为∞的边数即入度
    d=d1+d2;
    return d;
}

void CreateGraphList(AdjGraph *&G,int A[][MAXVEX],int n,int e)
{
    int i,j;
    ArcNode *p;
    G=(AdjGraph *)malloc(sizeof(AdjGraph));
    for (i=0;i<n;i++)	//邻接表中所有头结点的指针域置空
        G->adjlist[i].firstarc=NULL;

    for (i=0;i<n;i++)	//检查A中每个元素
        for (j=n-1;j>=0;j--)
            if (A[i][j]>0 && A[i][j]<INF)	      //存在一条边
             {
                p=(ArcNode *)malloc(sizeof(ArcNode));  //创建结点p
                p->adjvex=j;
                p->weight=A[i][j];
                p->nextarc=G->adjlist[i].firstarc;  //头插法插入p
                G->adjlist[i].firstarc=p;
             }
    G->n=n; G->e=e;
}

void DestroyGraph(AdjGraph *G)
{
    int i;
    ArcNode *pre,*p;
    for (i=0;i<G->n;i++)		//遍历所有的头结点
    {
        pre=G->adjlist[i].firstarc;
        if (pre!=NULL)
        {
            p=pre->nextarc;
            while (p!=NULL)  //释放adjlist[i]的所有边结点
            {
                free(pre);
                pre=p;
                p=p->nextarc;
            }
            free(pre);
        }
    }
    free(G);		   //释放G所指的头结点数组的内存空间
}

void DispGraphList(AdjGraph *&G)
{
    ArcNode *p;
    int i;
    for (i=0;i<G->n;i++)		//遍历所有的头结点
    {
        printf("  [%2d]",i);
        p=G->adjlist[i].firstarc;	//p指向第一个相邻点
        if (p!=NULL)
            printf(" →");
        while (p!=NULL)
        {  printf(" %d(%d)",p->adjvex,p->weight);
            p=p->nextarc;		//p移向下一个相邻点
        }
        printf("\n");
    }
}



