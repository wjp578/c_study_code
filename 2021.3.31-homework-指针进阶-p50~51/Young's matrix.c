#include "pointer.h"

//���Ͼ���
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);



int** creat_matrix(int sz,int iv)
{
    int f=0;
    int** m=(int**)malloc(sz*sizeof(int*));
    for(f=0;f<sz;f++)
    {
//        m[f]=(int*)malloc(sz*sizeof(int));
        *(m+f)=(int*)malloc(sz*sizeof(int));
    }


    int i=0;
    for(;i<sz;i++)
    {
        int j=0;
//        iv++;
        for(;j<sz;j++)
        {
//            m[i][j]=iv-1+j;
//            *(*(m+j)+i)=iv-1+j;

            *(*(m+i)+j)=iv;
            iv++;
        }
    }
    return m;
}

//1 2 3
//4 5 6
//7 8 9
int FindNum(int** m,int sz,int k,int* x,int* y)
{
    *x=0;
    *y=sz-1;

    while((*y)>=0&&(*x)<=(sz-1))
    {
        if(k<m[*x][*y])
            (*y)--;
        else if(k>m[*x][*y])
            (*x)++;
        else
            return 1;
    }

    return 0;
}

void test3()
{
    int sz,iv,k,x,y;
    printf("�������size��");
    scanf("%d",&sz);
    printf("�������init value��");
    scanf("%d",&iv);
    printf("����Ҫ���ҵ�Ԫ�أ�");
    scanf("%d",&k);

    //���ɾ���
    int** m=creat_matrix(sz,iv);
//    int **m=creat_matrix(4,4);

    int is=FindNum(m,sz,k,&x,&y);

    //��ӡ����
    int a=0;
    for(;a<sz;a++)
    {
        int b=0;
        for(;b<sz;b++)
        {
//            printf("%-3d",m[a][b]);
            printf("%-5d",*(*(m+a)+b.));
        }
        printf("\n");
    }

    if(is)
    {
        printf("��Ԫ���ھ���������Ϊ��x=%d y=%d\n",x+1,y+1);
    }
    else
    {
        printf("��Ԫ�ز�����\n");
    }

    free(m);
    m=NULL;

}
