//求Sn=a+aa+aaa+aaaa+aaaaa的前5项和

#include "homework.h"

void CalculateTheSum()
{
    int num=0;
    printf("请输入int数值(0~9):");
    scanf("%d",&num);
    int a[5]={num};
    int i=0;
    int sum=0;
    for(i=0;i<5;i++)
    {
        if(i<4)
        {
            *(a+i+1)=(*(a+i)*10)+(*a);
        }
        sum+=*(a+i);
    }
    printf("Sn=%d",sum);

}
