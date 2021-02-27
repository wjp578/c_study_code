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
//    int (*p)(int,int)=add;
//    printf("%d",(*p)(a,b));
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
