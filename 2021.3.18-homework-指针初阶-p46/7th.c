//打印 0~x 水仙花数

#include "homework.h"

//计算n次方
int my_pow(int a,int n)
{
    int b=a;
    while(--n)
    {
        a=a*b;
    }
    return a;
}

//计算位数
int Digits(int digits)
{
    int i=0;
    while(digits)
    {
        digits/=10;
        i++;
    }
    return i;
}

void DaffodilNumber()
{
    int num=0;
    printf("请输入int数值:");
    scanf("%d",&num);

    int i=0;
    for(i=0;i<=num;i++)
    {
        int j=0;
        int x=i;
        int da=0;
        for(j=0;j<Digits(i);j++)
        {
            //n位数n次方之和
            int remainder=x%10;
            x=x/10;
            da+=my_pow(remainder,Digits(i));
        }
        if(i==da&&i/10!=0)//判断水仙花数
        {
            printf("%d ",da);
        }
    }

}
