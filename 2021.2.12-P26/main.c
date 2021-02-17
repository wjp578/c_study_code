#include <stdio.h>
#include <stdlib.h>


////6、打印乘法口诀表，x*x，x由用户输入
//int main()
//{
//    int i=0,j=0,x=0;
//    printf("请输入乘法表大小：");
//    scanf("%d",&x);
//    for(i=1;i<=x;i++)
//    {
//        for(j=1;j<=i;j++)
//        {
//            printf("%dx%d=%d\t",i,j,i*j);
//        }
//        printf("\n");
//    }
//    return 0;
//}

////7、用递归地方式打印一个数的每一位
//void print_number(int n)
//{
//    if(n>9)
//        print_number(n/10);
//    printf("%d ",n%10);
//}

////8、实现递归阶乘

//int factorial(int n)
//    {
//        int i=0;
//        if(n==1)
//            return 1;
//        else
//        {
//            return factorial(n-1)*n;
//        }
//    }


////9、递归模拟strlen
//int fa_strlen(char* ch)
//    {
//        if(*ch=='\0')
//            return 0;
//        else
//            return 1+fa_strlen(ch+1);
//    }

////9、非递归模拟strlen
//int my_strlen(char* ch)
//    {
//        int count=0;
//        while(*ch!='\0')
//            {
//                count++;
//                ch++;
//            }
//            return count;
//    }

////10、非递归实现字符串逆序
//void reverse_string(char* arr)// arr[]也行
//    {
//        int l=0;
//        int r=my_strlen(arr)-1;
//        while(l<r)
//        {
//            int tmp=arr[l];
//            arr[l]=arr[r];
//            arr[r]=tmp;
//            l++;
//            r--;
//        }
//    }

////10、递归实现字符串逆置
//void reverse_string(char* arr)
//    {
//        int left=0;
//        int right=my_strlen(arr)-1;
//        if(my_strlen(arr+1)>1)
//        {
//            int temp=arr[left];
//            arr[left]=arr[right];
//            arr[right]='\0';
//            reverse_string(arr+1);
//            arr[right]=temp;
//        }
//
//    }


////11、递归实现--计算一个数的每位之和并打印
//int DigitSum(int n)
//{
//    if(n>9)
//    {
//        printf("%d",n%10);
//        printf("+");
//        return DigitSum(n/10)+n%10;
//    }
//    else
//        {
//            printf("%d",n);
//            printf("=");
//            return n;
//        }
//}

////11、递归实现n的k次方
//double pow(double n,double k)
//    {
//        if(k>0)
//            return pow(n,k-1)*n;
//        else if(k==0)
//            return 1.0;
//        else
//            return 1.0/pow(n,-k);
//    }

////12、斐波那契数列实现（递归）
//int Fibonacci(int n)
//    {
//        if(n==1||n==2)
//            return 1;
//        else
//            return Fibonacci(n-1)+Fibonacci(n-2);
//    }

//12、斐波那契数列实现（递归）
int Fibonacci(int n)
    {
        int tmp1=1;
        int tmp2=1;
        int tmp=1;
        int i=0;
        while(n-->2)
        {
            tmp=tmp1+tmp2;
            tmp1=tmp2;
            tmp2=tmp;
        }
        return tmp;
    }

int main()
    {
//        char ch[]="hello world";
        int input=0;
        printf("请输入一个数字：");
        scanf("%d",&input);

//        double n=0;
//        double k=0;
//        printf("请输入n=");
//        scanf("%lf",&n);
//        printf("请输入k=");
//        scanf("%lf",&k);

//        print_number(input);//7--递归打印数

//        printf("%d",factorial(input));//8--递归阶乘

//        printf("%d",fa_strlen(ch));//9--递归模拟strlen



//        01:11:36
//        2021.2.13



//        printf("%d",my_strlen(ch));//9--非递归模拟strlen

//        reverse_string(ch);//10--非递归实现逆置
//        reverse_string(ch);//10--递归实现逆置
//        printf("%s",ch);

//        printf("%d",DigitSum(input));

//        double ret=pow(n,k);
//        printf("n^k=%lf",ret);//11--递归实现n的k次方

        printf("该数为：%d",Fibonacci(input));//12--递归/非递归实现斐波那契数列

        return 0;
    }
