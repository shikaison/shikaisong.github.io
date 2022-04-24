//
// Created by shikaisong on 2022/4/24.
//

#ifndef DATA_STRUCTURE_MAZE_H
#define DATA_STRUCTURE_MAZE_H
#include "main.h"

/********************************�Թ�**************************************/

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
 * @brief ���һ��·���������·��
 */
void dispapath(void);

/**
 * @brief �����һ�����·��
 */
void dispminpath(void);

/**
 * @brief ���Թ�·��
 *
 * @param xi ��������
 * @param yi ���������
 * @param xe �յ������
 * @param ye �յ�������
 */
void mgpath(int xi,int yi,int xe,int ye);
#endif //DATA_STRUCTURE_MAZE_H