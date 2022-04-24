//
// Created by shikaisong on 2022/4/24.
//

#include "maze.h"
int Top=-1;
int count=1;
int minlen=maxSize;
int mg[M+2][N+2]= {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 1},
        {1, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1}
};

void dispapath(void)
{
    int k;
    printf("%5d:",count++);
    for(k=0;k<=Top;k++)
        printf("(%d, %d)",St[k].i,St[k].j);
    printf("\n");
    if(Top+1<minlen)
    {
        for(k=0;k<=Top;k++)
            Path[k]=St[k];
        minlen=Top+1;
    }
}

void dispminpath(void)
{
    printf("最短路径如下：\n");
    printf("长度:%d\n",minlen);
    printf("路径:");
    for(int k=0;k<minlen;k++)
        printf("(%d, %d)",St[k].i,St[k].j);
    printf("\n");

}

void mgpath(int xi,int yi,int xe,int ye)
{
    int i,j,i1,j1,di;
    bool find;
    Top++;
    St[Top].i=xi;
    St[Top].j=yi;
    St[Top].di=-1;
    mg[xi][yi]=-1;
    while(Top>-1)
    {
        i=St[Top].i;
        j=St[Top].j;
        di=St[Top].di;
        if(i==xe && j==ye)
        {
            dispapath();
            mg[i][j]=0;
            Top--;
            i=St[Top].i;
            j=St[Top].j;
            di=St[Top].di;
        }
        find=false;
        while(di<4 && !find)
        {
            di++;
            switch(di)
            {
                case 0:
                    i1=i-1;
                    j1=j;
                    break;
                case 1:
                    i1=i;
                    j1=j+1;
                    break;
                case 2:
                    i1=i+1;
                    j1=j;
                    break;
                case 3:
                    i1=i;
                    j1=j-1;
                    break;
            }
            if(mg[i][j]==0)
                find=true;
        }
        if(find)
        {
            St[Top].di=di;
            Top++;
            St[Top].i=i1;
            St[Top].j=j1;
            St[Top].di=-1;
            mg[i1][j1]=-1;
        }
        else
        {
            mg[i][j]=0;
            Top--;
        }
    }
    dispminpath();
}
