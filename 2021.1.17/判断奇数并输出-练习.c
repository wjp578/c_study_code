//实现功能：输入数字，判断是否为奇数，若不为奇数，输出……，若为奇数，输出0到该数的奇数。
#include<stdio.h>

int main()
{
    int a;
    printf("请输入数字：");
    scanf("%d",&a);

        if(0 == a%2)
            printf("该数不是奇数");
        else
        {
            int i = 1;
            while(i <= a)
                {
                    if(1 == i%2)
                    printf("%d ",i);
                    i += 1;//i=i+1;i++
                    }
        }
        return 0;
}
