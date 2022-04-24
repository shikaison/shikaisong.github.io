//
// Created by shikaisong on 2022/4/22.
//

#ifndef DATA_STRUCTURE_TREE_H
#define DATA_STRUCTURE_TREE_H
#include "main.h"
#include "stack"
#include <stdint.h>
#define MAXSIZE 100
typedef char ElemType1;

typedef struct
{
    int u;//边的起点
    int v;//边的终点
    int w;//边的权值
}Edge;

typedef struct node
{
    ElemType1 data;
    struct node *lchild;
    struct node *rchild;
}BTNode; // 二叉链类型

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

/**
 * @brief 先序非递归遍历算法（栈）
 *
 * @param b 二叉链
 */
void PreOrder(BTNode *b);

/**
 * @brief 中序非递归遍历算法（栈）
 *
 * @param b
 */
void InOrder(BTNode *b);


/**
 * @brief 后序非递归遍历算法（栈）
 *
 * @param b
 */
void PostOrder(BTNode *b);

/**
 * @brief 创建二叉树
 *
 * @param b 二叉链
 * @param str 结点值
 */
void CreateBTree(BTNode *&b,char *str);

/**
 * @brief 销毁二叉树
 *
 * @param b 二叉链
 */
void DestroyBTree(BTNode *&b);

/**
 * @brief 查找值为x的结点
 *
 * @param b 二叉链
 * @param x 查找值
 * @return 返回结点
 */
BTNode *FindNode(BTNode *b,ElemType1 x);

/**
 * @brief 返回p结点的左孩子指针
 *
 * @param p 二叉链
 * @return p结点的左孩子指针
 */
BTNode *LchildNode(BTNode *p);

/**
 * @brief 返回p结点的右孩子指针
 *
 * @param p 二叉链
 * @return p结点的右孩子指针
 */
BTNode *RchildNode(BTNode *p);

/**
 * @brief 求二叉树的高度
 *
 * @param b 二叉链
 * @return 二叉树的高度
 */
int BTHeight(BTNode *b);

/**
 * @brief 输出二叉树
 *
 * @param b 二叉链
 */
void DispBTree(BTNode *b);

#endif //DATA_STRUCTURE_TREE_H
