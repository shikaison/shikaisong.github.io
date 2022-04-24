//
// Created by shikaisong on 2022/4/24.
//

#ifndef DATA_STRUCTURE_MAZE_H
#define DATA_STRUCTURE_MAZE_H
#include "main.h"

/********************************迷宫**************************************/

#define M 4
#define N 4
#define maxSize 100
struct {
    int i,j;
    int di;
}St[maxSize],Path[maxSize];

extern int Top;
extern int count;
extern int minlen;
extern int mg[M+2][N+2];
/**
 * @brief 输出一条路径并求最短路径
 */
void dispapath(void);

/**
 * @brief 输出第一条最短路径
 */
void dispminpath(void);

/**
 * @brief 求迷宫路径
 *
 * @param xi 起点横坐标
 * @param yi 起点纵坐标
 * @param xe 终点横坐标
 * @param ye 终点纵坐标
 */
void mgpath(int xi,int yi,int xe,int ye);
#endif //DATA_STRUCTURE_MAZE_H