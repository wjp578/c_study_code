#include <stdio.h>
#include <stdlib.h>

//������ú���ָ�� �� ����ָ��ʵ��

double add(double a,double b)
{
    return a+b;
}

double sub(double a,double b)
{
    return a-b;
}

double mul(double a,double b)
{
    return a*b;
}

double my_div(double a,double b)
{
    return a/b;
}

void menu()
{
    printf("0��exit\n");
    printf("1�� add\n");
    printf("2�� sub\n");
    printf("3�� mul\n");
    printf("4�� div\n");
}

//int main()
//{
//    int input=0;
//    do
//    {
//        void(*pm)()=menu;//����ָ��д������ϰ
//        (*pm)();
//        printf("��ѡ���㷨��");
//        scanf("%d",&input);
//        double(*parr[])(double, double)={0,add,sub,mul,my_div};//����ָ������----ת�Ʊ�
//
//
//        if(input==0)
//        {
//            printf("�˳�����\n");
//        }
//        else if(input>=1&&input<=4)
//        {
//            double a=0,b=0;
//            printf("�������������");
//            scanf("%lf%lf",&a,&b);
//            printf("���Ϊ %lf\n\n",parr[input](a,b));
//        }
//        else
//        {
//            printf("Υ�����룬���������룡����\n\n");
//        }
//    }while(input);
//    return 0;
//}

void calc(double(*p)(double,double))
{
    double a=0,b=0;
    printf("�������������");
    scanf("%lf%lf",&a,&b);
    printf("���Ϊ %lf\n\n",p(a,b));
}

int main()
{
    int input=0;
    do
    {
        void(*pm)();
        pm=menu;
        (*pm)();
        printf("��ѡ���㷨��");
        scanf("%d",&input);
        switch(input)
        {
            case 0:printf("�˳�����");break;
            case 1:calc(add);break;
            case 2:calc(sub);break;
            case 3:calc(mul);break;
            case 4:calc(my_div);break;
            default:printf("�Ƿ����룬���������룡����");break;
        }

    }while(input);
    return 0;
}
