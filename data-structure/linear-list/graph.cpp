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
                printf("%4s","��");
        printf("\n");
    }
}

int Degree1(MatGraph g,int v)
{
    int i,d=0;
    if (v<0 || v>=g.n)
        return -1;		 //�����Ŵ��󷵻�-1
    for (i=0;i<g.n;i++)
        if (g.edges[v][i]>0 && g.edges[v][i]<INF)
            d++;		//ͳ�Ƶ�v�мȲ�Ϊ0Ҳ��Ϊ�޵ı�������
    return d;
}

int Degree2(MatGraph g,int v)	 //������ͼ�ж���Ķ�
{
    int i,d1=0,d2=0,d;
    if (v<0 || v>=g.n)
        return -1;	//�����Ŵ��󷵻�-1
    for (i=0;i<g.n;i++)
        if (g.edges[v][i]>0 && g.edges[v][i]<INF)
            d1++;		//ͳ�Ƶ�v�мȲ�Ϊ0Ҳ��Ϊ�޵ı���������
    for (i=0;i<g.n;i++)
        if (g.edges[i][v]>0 && g.edges[i][v]<INF)
            d2++;		//ͳ�Ƶ�v�мȲ�Ϊ0Ҳ��Ϊ�޵ı��������
    d=d1+d2;
    return d;
}

void CreateGraphList(AdjGraph *&G,int A[][MAXVEX],int n,int e)
{
    int i,j;
    ArcNode *p;
    G=(AdjGraph *)malloc(sizeof(AdjGraph));
    for (i=0;i<n;i++)	//�ڽӱ�������ͷ����ָ�����ÿ�
        G->adjlist[i].firstarc=NULL;

    for (i=0;i<n;i++)	//���A��ÿ��Ԫ��
        for (j=n-1;j>=0;j--)
            if (A[i][j]>0 && A[i][j]<INF)	      //����һ����
             {
                p=(ArcNode *)malloc(sizeof(ArcNode));  //�������p
                p->adjvex=j;
                p->weight=A[i][j];
                p->nextarc=G->adjlist[i].firstarc;  //ͷ�巨����p
                G->adjlist[i].firstarc=p;
             }
    G->n=n; G->e=e;
}

void DestroyGraph(AdjGraph *G)
{
    int i;
    ArcNode *pre,*p;
    for (i=0;i<G->n;i++)		//�������е�ͷ���
    {
        pre=G->adjlist[i].firstarc;
        if (pre!=NULL)
        {
            p=pre->nextarc;
            while (p!=NULL)  //�ͷ�adjlist[i]�����б߽��
            {
                free(pre);
                pre=p;
                p=p->nextarc;
            }
            free(pre);
        }
    }
    free(G);		   //�ͷ�G��ָ��ͷ���������ڴ�ռ�
}

void DispGraphList(AdjGraph *&G)
{
    ArcNode *p;
    int i;
    for (i=0;i<G->n;i++)		//�������е�ͷ���
    {
        printf("  [%2d]",i);
        p=G->adjlist[i].firstarc;	//pָ���һ�����ڵ�
        if (p!=NULL)
            printf(" ��");
        while (p!=NULL)
        {  printf(" %d(%d)",p->adjvex,p->weight);
            p=p->nextarc;		//p������һ�����ڵ�
        }
        printf("\n");
    }
}



