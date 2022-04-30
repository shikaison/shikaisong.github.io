//
// Created by shikaisong on 2022/4/18.
//

#ifndef DATA_STRUCTURE_GRAPH_H
#define DATA_STRUCTURE_GRAPH_H

#include <stdio.h>
#include <malloc.h>

#define INF 3270                 //����������
#define MAXVEX 6                  //ͼ����󶥵����

typedef char VertevType[10];        //����VertevTypeΪ�ַ�������

typedef struct vertex
{
    int adjvex;                     //������
    VertevType data;                //�������Ϣ
}VType;                             //���������

typedef struct graph
{
    int n, e;                       //nΪʵ�ʶ��������eΪʵ�ʱ���
    VType vexs[MAXVEX];             //���㼯��
    int edges[MAXVEX][MAXVEX];      //�ߵļ���
}MatGraph;                          //ͼ���ڽӾ�������

typedef struct edgenode
{
    int adjvex;                     //���ڵ����
    int weight;                     //�ߵ�Ȩֵ
    struct edgenode *nextarc;       //��һ���ߵĶ���
}ArcNode;                           //ÿ�����㽨���ĵ������бߵĽ�������

typedef struct vexnode
{
    VertevType data;                //���һ���������Ϣ
    ArcNode *firstarc;              //ָ���һ���߽��
}VHeadNode;                         //�������ͷ�������

typedef struct
{
    int n,e;                        //nΪʵ�ʵĶ�������eΪʵ�ʱ���
    VHeadNode adjlist[MAXVEX];      //������ͷ�������
}AdjGraph;                          //ͼ���ڽӱ�����



/**
 * @brief ����ͼ���ڽӾ���
 *
 * @param g �ڽӾ���
 * @param A �������ֵ������
 * @param n ʵ�ʶ������
 * @param e ʵ�ʱ���
 */
void CreateGraph(MatGraph &g,int A[MAXVEX][MAXVEX],int n,int e);

/**
 * @brief ���ͼ
 *
 * @param g ͼ���ڽӾ���
 */
void DispGraph(MatGraph g);

/**
 * @brief ������ͼ�ж���Ķ�
 *
 * @param g ͼ���ڽӾ���
 * @param v ����
 * @return ����ͼ�ж���Ķ�
 */
int Degree1(MatGraph g,int v);

/**
 * @brief ������ͼ�ж���Ķ�
 *
 * @param g ͼ���ڽӾ���
 * @param v ����
 * @return ����ͼ�ж���Ķ�
 */
int Degree2(MatGraph g,int v);

/**
 * @brief ����ͼ���ڽӱ�
 *
 * @param G ͼ���ڽӱ�
 * @param A �������ֵ������
 * @param n ʵ�ʵĶ�����
 * @param e ʵ�ʵı���
 */
void CreateGraphList(AdjGraph *&G,int A[MAXVEX][MAXVEX],int n,int e);

/**
 * @brief ����ͼ���ڽӱ�
 *
 * @param G ͼ���ڽӱ�
 */
void DestroyGraph(AdjGraph *G);

/**
 * @brief ���ͼ���ڽӱ�
 *
 * @param G ͼ���ڽӱ�
 */
void DispGraphList(AdjGraph *&G);





#endif //DATA_STRUCTURE_GRAPH_H
