#include "head.h"

//������Ǵ�С
#define LEN 15

void YHtriangle()
{
    //��ʼ��
    int yh[LEN][LEN]={{0}};

    //�������ߡ�1��
    int i=0;
    for(i=0;i<LEN;i++)
    {
        yh[i][0]=1;
        yh[i][i]=1;
    }

    //�����м�
    int a,b;
    for(a=2;a<LEN;a++)
    {
        for(b=1;b<a;b++)
        {
            yh[a][b]=yh[a-1][b-1]+yh[a-1][b];
        }
    }


    //��ӡ
    int x=0,y=0;
    for(x=0;x<LEN;x++)
    {
        for(y=0;y<x+1;y++)
        {
//            for
            printf("%-5d ",yh[x][y]);
        }
        printf("\n");
    }
}
