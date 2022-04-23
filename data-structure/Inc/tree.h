//
// Created by shikaisong on 2022/4/22.
//

#ifndef DATA_STRUCTURE_TREE_H
#define DATA_STRUCTURE_TREE_H
#include "main.h"

#define MAXSIZE 100

typedef struct
{
    int u;//边的起点
    int v;//边的终点
    int w;//边的权值
}Edge;

/**
 * @brief 非递归深度优先遍历算法
 *
 * @param G 邻接表
 * @param v 顶点
 */
void DFS(AdjGraph *G,int v);

/**
 * @brief 非递归广度优先遍历算法
 *
 * @param G 邻接表
 * @param v 顶点
 */
void BFS(AdjGraph *G,int v);


/**
 * @brief 普里姆算法，生成最小树
 *
 * @param g 图的邻接矩阵
 * @param v 出发顶点
 */
void  Prim(MatGraph g,int v);

/**
 * @brief 采用直接插入排序方法对E按w排序
 *
 * @param E 数组
 * @param n
 */
void InsertSort(Edge E[],int n);

/**
 * @brief 克鲁思卡尔算法，生成最小树
 *
 * @param g
 */
void Kruskal(MatGraph g);

#endif //DATA_STRUCTURE_TREE_H
