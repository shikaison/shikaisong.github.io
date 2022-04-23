//
// Created by shikaisong on 2022/4/22.
//

#include "tree.h"

void DFS(AdjGraph *G,int v)
{
    int visited[MAXVEX];
    ArcNode *p;
    int St[MAXVEX];
    int top=-1,w,x,i;
    for(i=0;i<G->n;i++)
        visited[i]=0;
    printf("%3d",v);
    visited[v]=1;
    top++;
    St[top]=v;
    while(top>-1)
    {
        x=St[top];
        p=G->adjlist[x].firstarc;
        while(p!=NULL)
        {
            w=p->adjvex;
            if(visited[w]==0)
            {
                printf("%3d",w);
                visited[w]=1;
                top++;
                St[top]=w;
                break;
            }
            p=p->nextarc;
        }
        if(p==NULL)
            top--;
    }
    printf("\n");
}

void BFS(AdjGraph *G,int v)
{
    ArcNode *p;
    int queue[MAXVEX],front=0,rear=0;
    int visited[MAXVEX];
    int w,i;
    for(i=0;i<G->n;i++)
        visited[i]=0;
    printf("%3d",v);
    visited[v]=1;
    rear=(rear+1)%MAXVEX;
    queue[rear]=v;
    while(front!=rear)
    {
        front=(front+1)%MAXVEX;
        w=queue[front];
        p=G->adjlist[w].firstarc;
        while(p!=NULL)
        {
            if(visited[p->adjvex]==0)
            {
                printf("%3d",p->adjvex);
                visited[p->adjvex]=1;
                rear=(rear+1)%MAXVEX;
                queue[rear]=p->adjvex;
            }
            p=p->nextarc;
        }
    }
    printf("\n");
}

void  Prim(MatGraph g,int v)
{
    int lowcost[MAXVEX];
    int min;
    int closest[MAXVEX],i,j,k;
    for (i=0;i<g.n;i++)	//给lowcost[]和closest[]置初值
    {	    lowcost[i]=g.edges[v][i];
        closest[i]=v;
    }
    for (i=1;i<g.n;i++)	  	//输出(n-1)条边
    {
        min=INF;
        for (j=0;j<g.n;j++) 	//在(V-U)中找出离U最近的顶点k
            if (lowcost[j]!=0 && lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;			//k记录最近顶点编号
            }
        printf(" 边(%d，%d)权为:%d\n",closest[k],k,min);
        lowcost[k]=0;		//标记k已经加入U
        for (j=0;j<g.n;j++)  //修改数组lowcost和closest
            if (lowcost[j]!=0 && g.edges[k][j]<lowcost[j])
            {
                lowcost[j]=g.edges[k][j];
                closest[j]=k;
            }
    }
}

void InsertSort(Edge E[],int n)
{
    int i,j;
    Edge temp;
    for(i=1;i<n;i++)
    {
        temp=E[i];
        j=i-1;
        while(j>=0&&temp.w<E[j].w&&temp.w!=0&&temp.w!=INF)
        {
            E[j+1]=E[j];
            j--;
        }
        E[j+1]=temp;
    }
}


void Kruskal(MatGraph g)
{
    int i,j,u1=0,v1=0,sn1=0,sn2=0,k;
    int vset[MAXVEX];
    Edge E[MAXSIZE];
    k=0;
    for(i=0;i<g.n;i++)
        for(j=0;j<=g.e;j++)
        {
            if(g.edges[i][j]!=0 && g.edges[i][j]!=INF)
            {
                E[k].u=i;
                E[k].v=j;
                E[k].w=g.edges[i][j];
                k++;
            }
        }
    InsertSort(E,g.e);//在此函数中出现问题
    for(i=0;i<g.n;i++)
        vset[i]=i;
    k=1;
    j=0;
    while(k<g.n)
    {
        u1=E[j].u;
        v1=E[j].v;
        sn1=vset[u1];
        sn2=vset[v1];
        if(sn1!=sn2)
        {
            printf("(%d,%d)； %d\n",u1,v1,E[j].w);
            k++;
            for(i=0;i<g.n;i++)
                if(vset[i]=sn2)
                    vset[i]=sn1;
        }
        j++;
    }
}