#include "chain.h"
/**********************单链表******************/
/**
 * @brief 创建单链表的表头
 * 
 * @param L 结构体指针，指向单链表中头结点
 */
void chianInit(chain_nood *&L)
{
    L=(chain_nood *)malloc(sizeof(chain_nood)); 
    L->next=NULL;
}

/**
 * @brief 判断单链表是否为空
 * 
 * @param L 结构体指针，指向单链表中头结点
 * @return int 为空返回0，不为空返回1
 */
int chainEmpty(chain_nood *L)
{
    if(L->next == NULL)
        return 0;
    else return 1;
}

/**
 * @brief 清除单链表，并释放空间
 * 
 * @param L 结构体指针，指向单链表中头结点
 */
void chainClear(chain_nood *&L)
{
    chain_nood *p,*pre=L;
    p=L->next;
    while(p!=NULL)
    {
        free(pre);
        pre=p;
        p=p->next; 
    }
    free(pre);
}

/**
 * @brief 计算单链表的长度
 * 
 * @param L 结构体指针，指向单链表中头结点
 * @return int 返回单链表的长度
 */
int chainLength(chain_nood *L)
{
    int length;
    chain_nood *p,*pre=L;
    p=L->next;
    while(p!=NULL)
    {
        length++;
        pre=p;
        p=p->next;
    }
    return length;
}

/**
 * @brief 逐一扫描单链表L的每个数据结点，并显示各结点的data域值
 * 
 * @param L 结构体指针，指向单链表中头结点
 */
void chainPrintf(chain_nood *L)
{
    while(L->next != NULL)
    {
        peintf("%f",L->data);
    }
}

/**
 * @brief 在单链表L中从头开始找到第i个结点，若存在第i个数据结点，则将其data域值赋给变量e
 * 
 * @param L 结构体指针，指向单链表中头结点
 * @param i 表示查找的结点的逻辑位置
 * @param e 接受查找到的值域
 * @return true 查找成功
 * @return flase 查找失败
 */
bool chainGet(chain_nood *L,int i, float &e)
{
    int n;
    while(n>i && L->next != NULL)
    {
        n++;
        L=L->next;
    }
    if(L->next != NULL)
        return flase;
    else
    {
         e=L->data;
        return true;
    }
}

/**
 * @brief 在单链表L中从头开始找第一个值域与e相等的结点
 * 
 * @param L 结构体指针，指向单链表中头结点
 * @param e 将查找的值
 * @return int 若找到e，则返回1，否则返回0
 */
int chainLocate(chain_nood *L,float e)
{
    while (L->data != e && L->next != NUll)
    {
        L=L->next;
    }
    if(L->data == e)
        return 1;
    else
        return 0;
}

/**
 * @brief 在第i个结点插入结点
 * 
 * @param L 结构体指针，指向单链表中头结点
 * @param i 结点的逻辑位置
 * @param e 即将插入的值
 * @return true 插入成功
 * @return false 插入失败
 */
bool chaininsert(chain_nood *&L,int i, float e)
{
    chain_nood *p;
    p=(chain_nood *)malloc(sizeof(chain_nood)); 
    p->data=e;
    int n=1;
    for(i > 0; n < i-1 && L->next != NULL; n++)
    {
        L=L->next;
    }
    if(n<i-1)
        return false;
    else if(L->next == NULL)
        {
            L->next=p;
            p->next=NULL;
            return true;
        }
    else
        {
            p->next=L->next;
            L->next=p;
            retrun true;
        }
}

/**
 * @brief 删除第i个结点，并释放其空间
 * 
 * @param L 结构体指针，指向单链表中头结点
 * @param i 结点的逻辑位置
 * @return true 删除成功
 * @return false 删除失败
 */
bool chainDeleta(chain_nood *&L, int i)
{
    chain_nood *p;
    int n=1;
     for(i > 0; n < i-1 && L->next != NULL; n++)
    {
        L=L->next;
    }
    if(n<i-1)           //如果第i-1个结点不存在
        return false;
    else
    {
        if(L->next == NULL)//如果第i个结点不存在
            return false;
        p=L->next->next;
        free(L->next);
        L->next=p;
        return true;
    }
}

/**
 * @brief 头插法建立单链表
 * 
 * @param L 结构体指针，指向单链表中头结点
 * @param s 保存每个结点值域的数组
 * @param n 数组长度，同时为结点长度
 */
void chainCreateHead(chain_nood *&L, float s[], int n)
{
    chain_nood *p;
    int i;
    for(i=0;i<n;i++)
    {
        p=(chain_nood *)malloc(sizeof(chain_nood));
        p->data=s[i];
        p->next=L->next;
        L->next=p;
    }
}

/**
 * @brief 尾插法建立单链表
 * 
 * @param L 结构体指针，指向单链表中头结点
 * @param s 保存每个结点值域的数组
 * @param n 数组长度，同时为结点长度
 */
void chainCreateTail(chain_nood *&L, float s[], int n)
{
    chain_nood *p,*r;
    int i;
    r->next=L;
    for(i=0;i<n;i++)
    {
        
        p=(chain_nood *)malloc(sizeof(chain_nood));
        p->data=s[i];
        if(i==0)
            L->next=p;
        r->next=p;
        r=p;
    }
    r->next=NULL;
}


/*******************************双链表**************************/


/**
 * @brief 创建一个空的双链表
 * 
 * @param L 
 */
void chain_two(chain_nood_two *&L)
{
    L=(chain_nood_two *)malloc(sizeof(chain_nood_two));
    L->next=NULL;
    L->before=NULL;
}

/**
 * @brief 头接法创建双链表
 * 
 * @param L 结构体指针，指向双链表中头结点
 * @param a 储存结点内容的数组
 * @param n 结点个数
 */
void CreateListF(chain_nood_two *&L,float a[],int n)
{   chain_nood_twoeListF *s; 
    int i;
    L=(chain_nood_two *)malloc(sizeof(chain_nood_two)); //创建头结点
    L->before=L->next=NULL;	//前后指针域置为NULL
    for (i=0;i<n;i++)		//循环建立数据结点
    {	s=(chain_nood_two *)malloc(sizeof(chain_nood_two));
        s->data=a[i];		//创建数据结点s
	    s->next=L->next;		//将s插入到头结点之后
	    if (L->next!=NULL)   	//若L存在数据结点，修改前驱指针
  	        L->next->before=s;
        L->next=s;
        s->before=L;
   }
} 

/**
 * @brief 尾接法创建双链表
 * 
 * @param L 结构体指针，指向双链表中头结点
 * @param a 储存结点内容的数组
 * @param n 结点个数
 */
void CreateListR(chain_nood_two *&L,float a[],int n)
{   chain_nood_two *s,*r;
    int i;
    L=(chain_nood_two *)malloc(sizeof(chain_nood_two));    //创建头结点
    r=L;					//r始终指向尾结点，开始时指向头结点
    for (i=0;i<n;i++)			//循环建立数据结点
    {   s=(chain_nood_two *)malloc(sizeof(chain_nood_two));
        s->data=a[i];			//创建数据结点s
        r->next=s;
        s->before=r;		//将s插入r之后
        r=s;				//r指向尾结点
    }
    r->next=NULL;				//尾结点next域置为NULL
}

/**
 * @brief 向双链表中的指定位置插入结点
 * 
 * @param L 结构体指针，指向双链表中头结点
 * @param i 插入的位置
 * @param e 插入的元素
 * @return true 插入成功
 * @return false 插入失败
 */
bool ListInsert(chain_nood_two *&L,int i,float e)
{   int j=0;
    chain_nood_two *p=L,*s;	      	//p指向头结点，j设置为0
    if(i<1)
        return false;
    while (j<i-1 && p!=NULL)	//查找第i-1个结点
    {   j++;
        p=p->next;
    }      
    if (p==NULL)			//未找到第i-1个结点，返回false
        return false;
    else				//找到第i-1个结点p，在其后插入新结点s
    {
	    s=(chain_nood_two *)malloc(sizeof(chain_nood_two));
	    s->data=e;		//创建新结点s
	    s->next=p->next;		//在p之后插入s结点
	    if (p->next!=NULL)	//若存在后继结点，修改其前驱指针
   	        p->next->before=s;
	    s->before=p;
	    p->next=s;
	    return true;
   }
}

/**
 * @brief 删除双链表中的指定结点
 * 
 * @param L 结构体指针，指向双链表中头结点
 * @param i 删除结点的位置
 * @param e 接受删除结点的内容
 * @return true 删除失败
 * @return false 删除成功
 */
bool ListDelete(chain_nood_two *&L,int i,float &e)
{   int j=0; 
    chain_nood_two *p=L,*q; 		//p指向头结点，j设置为0
    if(i<1)
        return false;
    while (j<i-1 && p!=NULL)	  	//查找第i-1个结点
    {   j++;
        p=p->next;
    }
    if (p==NULL)			//未找到第i-1个结点
	    return false;
    else			   	//找到第i-1个结点p
    {	q=p->next;		//q指向第i个结点
	if (q==NULL)	   	//当不存在第i个结点时返回false
	    return false;
	e=q->data;
	p->next=q->next;		//从双单链表中删除q结点
	if (q->next!=NULL)    	//若q结点存在后继结点
        q->next->prior=p;	//修改q结点后继结点的前驱指针
	free(q);		   	//释放q结点
	return true;
    }
}
