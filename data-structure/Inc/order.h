/*包含了线性表中顺序表相关函数*/
#ifndef __ORDER_H__
#define __ORDER_H__
#include "main.h"
/*include strat*/


/*include end */
/*defien start*/
#define MAX_data 1000
#define false    0
#define true     1
#define _CRT_SECURE_NO_DEPRECATE
#define _SCL_SECURE_NO_DEPRECATE

/*define end*/

typedef struct 
{
    /* data */
    int List[MAX_data];
    int data_length;
}list;

/**@brief       初始化操作，建立一个空的线性表L.
  *@param   L   一个@list类型的结构体
  * 
  */
void InitList(list *L);

/**@brief       判断线性表是否为空表，若线性表为空，则返回true,否则返回false.
  *@param    L  一个@list 类型的结构体
  * 
  */
int ListEmpty(list L);

/**@brief       将线性表清空.
  *@param    L  一个@list 类型的结构体
  * 
  */
void ClearList(list *L);

/**@brief       将线性表L中第i个位置元素值返回给e.
  *@param    L  一个@list 类型的结构体.
  *@param    i  返回元素的逻辑位置.
  *@param    e  接受返回值的变量.
  */
int etElem(list L, int i, int *e);

/**@brief       在线性表L中查找与给定值e相等的元素，如果查找成功，返回该元素在表中序号表示成功；否则返回0表示失败.
  *@param    L  一个@list 类型的结构体
  * 
  */
int LocateElem(list L, int e);

/**@brief       在线性表L中第i个位置插入元素e.
  *@param    L  一个@list 类型的结构体.
  *@param    i  查找元素的逻辑位置.
  *@param    e  要插入的元素。
  */
void ListInsert(list *L, int i, int e);

/**@brief       删除线性表中第i个位置元素，并用e返回其值.
  *@param    L  一个@list 类型的结构体.
  *@param    i  删除元素的逻辑位置.
  *@param    e  要删除的元素。
  */
int ListDelete(list *L,int i,int *e);

/**@brief       返回线性表的元素个数.
  *@param    L  一个@list 类型的结构体
  * 
  */
int ListLength(list L);

#endif
