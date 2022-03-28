#include "order.h"


void InitList(list *L)//初始化操作，建立一个空的线性表L
{
    L->data_length = 0;
}

int ListEmpty(list L)//判断线性表是否为空表，若线性表为空，则返回true,否则返回false
{
    if(L.data_length == 0)
        return true;
    return false;
}

void ClearList(list *L)//将线性表清空
{
    int i;
    for(i = 0; i < L->data_length; i++)
    {
        L->List[i] = NULL;
    }
}

int etElem(list L, int i, int *e)//将线性表L中第i个位置元素值返回给e
{
    *e =  L.List[i-1];
    return *e;
}

int LocateElem(list L, int e)//在线性表L中查找与给定值e相等的元素，如果查找成功，返回该元素在表中序号表示成功；否则返回0表示失败
{
    int i;
    for(i = 0; i < L.data_length; i++)
    {
        if(L.List[i] == e)
        return true;
    }
    return false;
}

void ListInsert(list *L, int i, int e)//在线性表L中第i个位置插入元素e
{
    int n = L->data_length;
    for(i > 0 || i <= (L->data_length +1); n >= i;n--)
    {
        L->List[n+1] = L->List[n];
    }
    L->List[n] = e;
    L->data_length++;
}

int ListDelete(list *L,int i,int *e)//删除线性表中第i个位置元素，并用e返回其值
{
    int n = i-1;
    *e = L->List[n];
    for(i > 0 || i <= L->data_length; n > L->data_length; i++)
    {
        L->List[n] == L->List[n+1];
    }
    L->data_length--;
    return *e;
}

int ListLength(list L)//返回线性表的元素个数
{
    return L.data_length;
}