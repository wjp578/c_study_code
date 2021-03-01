#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//    const char* p="abcdef";//常量字符串 ，不能更改，段错误，segmetation fault
//    //*p='w';
//    //printf("%c\n",*p);
//    printf("%s",p);
//    return 0;
//}

//int main()
////验证：
////每个数组储存地址不同（即使内容相同），开辟不同空间----------------------------    数组
////若内容相同（指针地址相同）开辟一个空间，同时指向该空间首元素地址-------------    指针
//{
//    char arr1[]="abcdef";
//    char arr2[]="abcdef";
//    char* p1="abcdef";
//    char* p2="abcdef";
//    //if(arr1==arr2)
//    if(p1==p2)
//    {
//        printf("same");
//    }
//    else
//        printf("not same");
//    return 0;
//}


//2021.2.23


//int main()
//{
//    int arr[10]={0,1,2,3,4,5,6,7,8,9};
//    int* p=arr;
//    int i=0;
//    for(i=0;i<10;i++)
//    {
//        printf("%d",p[i]);
////        printf("%d",*(arr+i));
////        printf("%d",*(p+i));
//
//        //arr[i] == *(arr+i) == *(p+i) == p[i]
//    }
//    return 0;
//}

//2021.2.27





//函数指针实例





//int add(int a,int b)
//{
//    int c=a+b;
//    return c;
//}
//
//int main()
//{
//    int a=3;
//    int b=5;
//    int (*p)(int,int)=add;//函数名为该函数地址
//    printf("%d",(*p)(a,b));
//    return 0;
//}

//void print(char* str)
//{
//    printf("%s",str);
//}
//
//int main()
//{
//    void (*pc)(char* )=print;
//    (*pc)("abcdef");
//    return 0;
//}

//两段阴间代码
//(*(void(*)())0)();
//把0强制类型转换为【void(*)()----函数指针】，调用0地址处的该函数

//void(*signal     (int , void(*)(int)   )(int);
//
//==
//
//typedef void(* pfun_t)(int);
//pfun_t signal(int , pfin_t);




//23:45
//2021.2.28

//int add(int a,int b)
//{
//    int c=a+b;
//    return c;
//}
//
//int main()
//{
//    int a=3;
//    int b=5;
//    int (*p)(int,int)=add;
//    printf("%d\t",(**p)(a,b));
//    printf("%d\t",(*p)(a,b));
//    printf("%d\t",(p)(a,b));
//    printf("%d\t",p(a,b));
//    printf("%d\t",add(a,b));
//    //*  对函数指针没有实质影响
//    return 0;
//}





//函数指针数组


int add(int a,int b)
{
    return a+b;
}

int sub(int a,int b)
{
    return a-b;
}

int mul(int a,int b)
{
    return a*b;
}

int my_div(int a,int b)
{
    return a/b;
}

//int main()
//{
//    int a=3;
//    int b=5;
////    int i=-1;
//    int i=0;
//    int(*parr[4])(int,int)={add,sub,mul,my_div};
////    while(i++<3)
////    {
////        printf("%d\n",parr[i](a,b));
////
////    }
//    while(i<4)
//        {
//            printf("%d\n",parr[i](a,b));
//            i++;
//        }
//    return 0;
//}

//int main()
//{
//    int a=3;
//    int b=5;
//    int i=-1;
//    int(*parr[4])(int,int)={add,sub,mul,my_div};
//    while(++i<4)
//    {
//        printf("%d\n",parr[i](a,b));
//
//    }
//    return 0;
//}



//P38---40:55

