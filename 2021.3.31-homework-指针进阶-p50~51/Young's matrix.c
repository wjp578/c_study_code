#include "pointer.h"

//杨氏矩阵
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);



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
    printf("输入矩阵size：");
    scanf("%d",&sz);
    printf("输入矩阵init value：");
    scanf("%d",&iv);
    printf("输入要查找的元素：");
    scanf("%d",&k);

    //生成矩阵
    int** m=creat_matrix(sz,iv);
//    int **m=creat_matrix(4,4);

    int is=FindNum(m,sz,k,&x,&y);

    //打印矩阵
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
        printf("该元素在矩阵中坐标为：x=%d y=%d\n",x+1,y+1);
    }
    else
    {
        printf("该元素不存在\n");
    }

    free(m);
    m=NULL;

}
