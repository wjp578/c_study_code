//��ӡ 0~x ˮ�ɻ���

#include "homework.h"

//����n�η�
int my_pow(int a,int n)
{
    int b=a;
    while(--n)
    {
        a=a*b;
    }
    return a;
}

//����λ��
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
    printf("������int��ֵ:");
    scanf("%d",&num);

    int i=0;
    for(i=0;i<=num;i++)
    {
        int j=0;
        int x=i;
        int da=0;
        for(j=0;j<Digits(i);j++)
        {
            //nλ��n�η�֮��
            int remainder=x%10;
            x=x/10;
            da+=my_pow(remainder,Digits(i));
        }
        if(i==da&&i/10!=0)//�ж�ˮ�ɻ���
        {
            printf("%d ",da);
        }
    }

}
