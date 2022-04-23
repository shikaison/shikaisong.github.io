#ifndef __MAIN_H__
#define __MAIN_H__
#include "order.h"
#include "chain.h"
#include <stdint.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include "stack.h"
#include "graph.h"
#include "tree.h"

/**
 * @brief 图任务
 */
void Graph(void);

/**
 * @brief 栈任务(二叉树的遍历非递归)
 *
 */
void Stack(void);

/**
 * @brief 最小生成树,Prim算法
 *
 */
void free_min_Prim(void);

/**
 * @brief 最小生成树，Kruskal算法
 *
 */
void free_min_Kruskal(void);

/**
 * @brief 测试函数
 *
 */
void debug(void);
#endif
