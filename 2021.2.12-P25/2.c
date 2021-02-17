#include <stdio.h>
#include <stdlib.h>

//int count_1(int n)
//    {
//        int count=0;
//        while(n)
//        {
//            n=n&(n-1);
//            count++;
//        }
//        return count;
//    }

////题目名称；求二进制中不同位个数
////编程实现：两个int（32位）整数二进制表达有多少个位（bit）不同
//int main()
//    {
//        int a=0,b=0,c=0;
//        int i=0;
//        printf("请输入两个整形数：");
//        scanf("%d%d",&a,&b);
//        c=a^b;
//        i=count_1(c);
////        while(c)
////        {
////            if(c%2==1)
////            {
////                i++;
////            }
////            c/=2;
////        }
//        printf("%d",i);
//        return 0;
//    }


////题目名称：计算二进制数中1的个数
//int main()
//    {
//        int a=0,b=0;
//        printf("请输入整形数：");
//        scanf("%d",&a);
//        b=count_1(a);
////        while(a)
////        {
////            if(a%2==1)
////            {
////                b++;
////            }
////            a/=2;
////        }
//        printf("“1”的个数为：%d",b);
//        return 0;
//    }

//int main()
//    {
//        int m=10;
//        int n=20;
//        printf("%d %d\n",m,n);
//        m=m^n;
//        printf("%d %d\n",m,n);
//        n=m^n;
//        printf("%d %d\n",m,n);
//        m=m^n;
//        printf("%d %d\n",m,n);
//        return 0;
//    }

//00000000 00000000 00000000 00001010----10--m
//00000000 00000000 00000000 00010100----20--n

//00000000 00000000 00000000 00011110----30--m
//00000000 00000000 00000000 00001010----10--n

//00000000 00000000 00000000 00010100----20--m

int main()
    {
        int i=0;
        int arr[]={1,2,3,4,5,6,7,8,9};
        int* p=arr;
        for(i=0;i<9;i++)
            printf("%d ",*(p+i));
        return 0;
    }
