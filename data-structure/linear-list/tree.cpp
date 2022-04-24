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

void PreOrder(BTNode *b)
{
    BTNode *p,*St[MaxSize];
    int top=-1;
    if(b!=NULL)
    {
        top++;
        St[top]=b;
        while(top>-1)
        {
            p=St[top];
            top--;
            printf("%c",p->data);
            if(p->rchild!=NULL)
            {
                top++;
                St[top]=p->rchild;

            }
            if(p->lchild!=NULL)
            {
                top++;
                St[top]=p->rchild;
            }
        }
        printf("\n");
    }

}

void InOrder(BTNode *b)
{
    BTNode *St[MAXSIZE],*p;
    int top=-1;
    if(b!=NULL)
    {
        p=b;
        while(top>-1 || p!= NULL)
        {
            while(p!=NULL)
            {
                top++;
                St[top]=p;
                p=p->lchild;
            }
            if(top>-1)
            {
                p=St[top];
                top--;
                printf("%c",p->data);
                p=p->rchild;
            }
        }
        printf("\n");
    }
}

void PostOrder(BTNode *b)
{
    BTNode *St[MAXSIZE],*p;
    int top=-1;
    bool  flag;
    if(b!=NULL)
    {
        do
        {
            while(b!=NULL)
            {
                top++;
                St[top]=b;
                b=b->lchild;
            }
            p=NULL;
            flag=true;
            while(top!=-1 && flag)
            {
                b=St[top];
                if(b->rchild==p)
                {
                    printf("%c",b->data);
                    top--;
                    p=b;
                }
                else
                {
                    b=b->rchild;
                    flag=false;
                }
            }
        }while(top!=-1);
        printf("\n");
    }
}

void CreateBTree(BTNode *&b,char *str)
{
    BTNode *St[MAXSIZE],*p;
    int top=-1,k,j=0;
    char ch;
    b=NULL;
    ch=str[j];
    while(ch!='\0')
    {
        switch(ch)
        {
            case '(':
                top++;
                St[top]=p;
                k=1;
                break;
            case ')':
                top--;
                break;
            case ',':
                k=2;
                break;
            default:
                p=(BTNode *)malloc(sizeof(BTNode));
                p->data=ch;
                p->lchild=p->rchild=NULL;
                if(b==NULL)
                    b=p;
                else
                {
                    switch(k)
                    {
                        case 1:St[top]->lchild=p;break;
                        case 2:St[top]->rchild=p;break;
                    }
                }
        }
        j++;
        ch=str[j];
    }
}

void DestroyBTree(BTNode *&b)
{
    if (b==NULL)
        return ;
    else
    {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);      //剩下一个结点b，直接释放
    }
}


BTNode *FindNode(BTNode *b,ElemType x)
{
    BTNode *p;

    if (b==NULL)
        return NULL;

    else if (b->data==x)
        return b;

    else
    {
        p=FindNode(b->lchild,x);
        if (p!=NULL)
            return p;
        else
            return FindNode(b->rchild,x);
    }
}

BTNode *LchildNode(BTNode *p)
{
    return p->lchild;
}

BTNode *RchildNode(BTNode *p)
{
    return p->rchild;
}

int BTHeight(BTNode *b)
{
    int lchilddep,rchilddep;
    if (b==NULL)
        return(0); 	//空树的高度为0
    else
    {
        lchilddep=BTHeight(b->lchild);
        //求左子树的高度为lchilddep
        rchilddep=BTHeight(b->rchild);
        //求右子树的高度为rchilddep
        return(lchilddep>rchilddep)? (lchilddep+1):(rchilddep+1);
    }
}

void DispBTree(BTNode *b)
{  if (b!=NULL)
    {
    printf("%c",b->data);
        if (b->lchild!=NULL || b->rchild!=NULL)
        {
            printf("(");
            DispBTree(b->lchild);//递归处理左子树
            if (b->rchild!=NULL)
                printf("，");
            DispBTree(b->rchild);//递归处理右子树
            printf(")");
        }
    }
}

