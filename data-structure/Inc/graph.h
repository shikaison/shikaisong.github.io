//
// Created by shikaisong on 2022/4/18.
//

#ifndef DATA_STRUCTURE_GRAPH_H
#define DATA_STRUCTURE_GRAPH_H

#include <stdio.h>
#include <malloc.h>

#define INF 3270                 //定义正无穷
#define MAXVEX 6                  //图中最大顶点个数

typedef char VertevType[10];        //定义VertevType为字符串类型

typedef struct vertex
{
    int adjvex;                     //顶点编号
    VertevType data;                //顶点的信息
}VType;                             //顶点的类型

typedef struct graph
{
    int n, e;                       //n为实际顶点个数，e为实际边数
    VType vexs[MAXVEX];             //顶点集合
    int edges[MAXVEX][MAXVEX];      //边的集合
}MatGraph;                          //图的邻接矩阵类型

typedef struct edgenode
{
    int adjvex;                     //相邻点序号
    int weight;                     //边的权值
    struct edgenode *nextarc;       //下一条边的顶点
}ArcNode;                           //每个顶点建立的单链表中边的结点的类型

typedef struct vexnode
{
    VertevType data;                //存放一个顶点的信息
    ArcNode *firstarc;              //指向第一条边结点
}VHeadNode;                         //单链表的头结点类型

typedef struct
{
    int n,e;                        //n为实际的顶点数，e为实际边数
    VHeadNode adjlist[MAXVEX];      //单链表头结点数组
}AdjGraph;                          //图的邻接表类型



/**
 * @brief 创建图的邻接矩阵
 *
 * @param g 邻接矩阵
 * @param A 包含结点值的数组
 * @param n 实际顶点个数
 * @param e 实际边数
 */
void CreateGraph(MatGraph &g,int A[MAXVEX][MAXVEX],int n,int e);

/**
 * @brief 输出图
 *
 * @param g 图的邻接矩阵
 */
void DispGraph(MatGraph g);

/**
 * @brief 求无向图中顶点的度
 *
 * @param g 图的邻接矩阵
 * @param v 行数
 * @return 无向图中顶点的度
 */
int Degree1(MatGraph g,int v);

/**
 * @brief 求无向图中顶点的度
 *
 * @param g 图的邻接矩阵
 * @param v 行数
 * @return 无向图中顶点的度
 */
int Degree2(MatGraph g,int v);

/**
 * @brief 创建图的邻接表
 *
 * @param G 图的邻接表
 * @param A 包含结点值的数组
 * @param n 实际的顶点数
 * @param e 实际的边数
 */
void CreateGraphList(AdjGraph *&G,int A[MAXVEX][MAXVEX],int n,int e);

/**
 * @brief 销毁图的邻接表
 *
 * @param G 图的邻接表
 */
void DestroyGraph(AdjGraph *G);

/**
 * @brief 输出图的邻接表
 *
 * @param G 图的邻接表
 */
void DispGraphList(AdjGraph *&G);





#endif //DATA_STRUCTURE_GRAPH_H
