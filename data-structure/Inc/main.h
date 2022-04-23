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
 * @brief ͼ����
 */
void Graph(void);

/**
 * @brief ջ����(�������ı����ǵݹ�)
 *
 */
void Stack(void);

/**
 * @brief ��С������,Prim�㷨
 *
 */
void free_min_Prim(void);

/**
 * @brief ��С��������Kruskal�㷨
 *
 */
void free_min_Kruskal(void);

/**
 * @brief ���Ժ���
 *
 */
void debug(void);
#endif
