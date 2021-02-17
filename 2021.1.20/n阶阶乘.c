#include<stdio.h>

int main()
{
    int a ,i ,m=1;
    printf("请输入数字：");
    scanf("%d",&a);
    for(i=1;i<=a;i++)
            m = m * i;
    printf("阶乘结果为：%d", m);
    return 0;
}
