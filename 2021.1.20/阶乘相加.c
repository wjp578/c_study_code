//����1��+2��+3��4��+����n��
#include<stdio.h>

int main()
{
    int a ,x ,y , m=1, n=0;
    printf("���������֣�");
    scanf("%d",&a);
    for(x=1;x<=a;x++)
        {
            for(y=1;y<=x;y++)
                {
                    m = m * y;
                }
            n = m + n;
            m = 1;

        }
    printf("�׳˽��Ϊ��%d", n);
    return 0;
}
//1-1;2-2;3-6;4-24;5-120.
