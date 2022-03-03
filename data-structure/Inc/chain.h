/*包含了线性表中单链表的相关函数*/
#ifndef __CHAIN_H__
#define __CHAIN_H__

typedef struct noods
{
    /* data */
    float data;
    struct noods next;
}chain_nood;


/**
 * @brief 创建单链表的表头
 * 
 * @param L 结构体指针，指向单链表中第一个结点
 */
void chianInit(chain_nood *&L);

/**
 * @brief 判断单链表是否为空
 * 
 * @param L 结构体指针，指向单链表中第一个结点
 * @return int 为空返回0，不为空返回1
 */
int chainEmpty(chain_nood *L);

/**
 * @brief 清除单链表，并释放空间
 * 
 * @param L 结构体指针，指向单链表中第一个结点
 */
void chainClear(chain_nood *&L);

/**
 * @brief 计算单链表的长度
 * 
 * @param L 结构体指针，指向单链表中第一个结点
 * @return int 返回单链表的长度
 */
int chainLength(chain_nood *L);

/**
 * @brief 逐一扫描单链表L的每个数据结点，并显示各结点的data域值
 * 
 * @param L 结构体指针，指向单链表中第一个结点
 */
void chainPrintf(chain_nood *L);

/**
 * @brief 在单链表L中从头开始找到第i个结点，若存在第i个数据结点，则将其data域值赋给变量e
 * 
 * @param L 结构体指针，指向单链表中第一个结点
 * @param i 表示查找的结点的逻辑位置
 * @param e 接受查找到的值域
 * @return float 将查找到的结点的data值域的值返回
 */
float chainGet(chain_nood *L,int i, float &e);

/**
 * @brief 在单链表L中从头开始找第一个值域与e相等的结点
 * 
 * @param L 结构体指针，指向单链表中第一个结点
 * @param e 将查找的值
 * @return int 若找到e，则返回1，否则返回0
 */
int chainLocate(chain_nood *L,float e);

/**
 * @brief 在第i个结点插入结点
 * 
 * @param L 结构体指针，指向单链表中第一个结点
 * @param i 结点的逻辑位置
 * @param e 即将插入的值
 * @return true 插入成功
 * @return false 插入失败
 */
bool chaininsert(chain_nood *&L,int i, float e);

/**
 * @brief 删除第i个结点，并释放其空间
 * 
 * @param L 结构体指针，指向单链表中第一个结点
 * @param i 结点的逻辑位置
 * @return true 删除成功
 * @return false 删除失败
 */
bool chainDeleta(chain_nood *&L, int i);

/**
 * @brief 头插法建立单链表
 * 
 * @param L 结构体指针，指向单链表中第一个结点
 * @param s 保存每个结点值域的数组
 * @param n 数组长度，同时为结点长度
 */
void chainCreateHead(chain_nood *&L, float s[], int n);

/**
 * @brief 尾插法建立单链表
 * 
 * @param L 结构体指针，指向单链表中第一个结点
 * @param s 保存每个结点值域的数组
 * @param n 数组长度，同时为结点长度
 */
void chainCreateTail(chain_nood *&L, float s[], int n);


#endif
