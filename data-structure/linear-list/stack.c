#include "stack.h"
/***************用数组实现的顺序栈******************/


typedef struct stack
{
    ElemType data[MaxSize];
    int top;
}SqStack;

/**
 * @brief 建立一个新的空栈
 * 
 * @param S 指向栈的指针
 */
void InitStack(SqStack *&s)
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}

/**
 * @brief 清空栈
 * 
 * @param s 指向栈的指针
 */
void DestoryStack(SqStack &s)
{
    free(s);
}

/**
 * @brief 判断栈是否为空
 * 
 * @param s 指向栈的指针
 * @return true 为空返回真
 * @return false 不空返回假
 */
bool StackEmpty(SqStack *s)
{
    return (s->top=-1);
}

/**
 * @brief 进栈
 * 
 * @param s 指向栈的指针
 * @param e 插入值
 * @return true 插入成功
 * @return false 插入失败
 */
bool Push(SqStack *&s, ElemType e)
{
    if(s->top==MaxSize-1)
        return false;
    s->top++;
    s->data[s->top]=e;
    return true;
}

/**
 * @brief 出栈
 * 
 * @param s 指向栈的指针
 * @param e 出栈的值
 * @return true 出栈成功
 * @return false 出栈失败
 */
bool Pop(SqStack *&s, ElemType &e)
{
    if(s->top==-1)
        return false;
    e=s->data[s->top];
    s->top--;
    return true;
}

/**
 * @brief 取栈顶元素
 * 
 * @param s 指向栈的指针
 * @param e 取出的值 
 * @return true 取出成功
 * @return false 取出失败
 */
bool GetTop(SqStack *s, ElemType &e)
{
    if(s->top==-1)
        return false;
    e=s->data[s->top];
    return true;
}




