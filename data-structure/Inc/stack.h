#ifndef __STACK_H__
#define __STACK_H__
#include <main.h>


#define MaxSize 10000
typedef  char ElemType;

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
void InitStack(SqStack *&s);

/**
 * @brief 清空栈
 *
 * @param s 指向栈的指针
 */
void DestroyStack(SqStack *&s);

/**
 * @brief 判断栈是否为空
 *
 * @param s 指向栈的指针
 * @return true 为空返回真
 * @return false 不空返回假
 */
bool StackEmpty(SqStack *s);

/**
 * @brief 进栈
 *
 * @param s 指向栈的指针
 * @param e 插入值
 * @return true 插入成功
 * @return false 插入失败
 */
bool Push(SqStack *&s, ElemType e);

/**
 * @brief 出栈
 *
 * @param s 指向栈的指针
 * @param e 出栈的值
 * @return true 出栈成功
 * @return false 出栈失败
 */
bool Pop(SqStack *&s, ElemType &e);

/**
 * @brief 取栈顶元素
 *
 * @param s 指向栈的指针
 * @param e 取出的值
 * @return true 取出成功
 * @return false 取出失败
 */
bool GetTop(SqStack *s, ElemType &e);


#endif
