#include <stdio.h>
#include <stdlib.h>

//代码采用函数指针 和 函数指针实现

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
    printf("0、exit\n");
    printf("1、 add\n");
    printf("2、 sub\n");
    printf("3、 mul\n");
    printf("4、 div\n");
}

//int main()
//{
//    int input=0;
//    do
//    {
//        void(*pm)()=menu;//函数指针写法，复习
//        (*pm)();
//        printf("请选择算法：");
//        scanf("%d",&input);
//        double(*parr[])(double, double)={0,add,sub,mul,my_div};//函数指针数组----转移表
//
//
//        if(input==0)
//        {
//            printf("退出程序\n");
//        }
//        else if(input>=1&&input<=4)
//        {
//            double a=0,b=0;
//            printf("请输入操作数：");
//            scanf("%lf%lf",&a,&b);
//            printf("结果为 %lf\n\n",parr[input](a,b));
//        }
//        else
//        {
//            printf("违法输入，请重新输入！！！\n\n");
//        }
//    }while(input);
//    return 0;
//}

void calc(double(*p)(double,double))
{
    double a=0,b=0;
    printf("请输入操作数：");
    scanf("%lf%lf",&a,&b);
    printf("结果为 %lf\n\n",p(a,b));
}

int main()
{
    int input=0;
    do
    {
        void(*pm)();
        pm=menu;
        (*pm)();
        printf("请选择算法：");
        scanf("%d",&input);
        switch(input)
        {
            case 0:printf("退出程序");break;
            case 1:calc(add);break;
            case 2:calc(sub);break;
            case 3:calc(mul);break;
            case 4:calc(my_div);break;
            default:printf("非法输入，请重新输入！！！");break;
        }

    }while(input);
    return 0;
}
