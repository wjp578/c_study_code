#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//    const char* p="abcdef";//�����ַ��� �����ܸ��ģ��δ���segmetation fault
//    //*p='w';
//    //printf("%c\n",*p);
//    printf("%s",p);
//    return 0;
//}

//int main()
////��֤��
////ÿ�����鴢���ַ��ͬ����ʹ������ͬ�������ٲ�ͬ�ռ�----------------------------    ����
////��������ͬ��ָ���ַ��ͬ������һ���ռ䣬ͬʱָ��ÿռ���Ԫ�ص�ַ-------------    ָ��
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





//����ָ��ʵ��





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
//    int (*p)(int,int)=add;//������Ϊ�ú�����ַ
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

//�����������
//(*(void(*)())0)();
//��0ǿ������ת��Ϊ��void(*)()----����ָ�롿������0��ַ���ĸú���

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
//    //*  �Ժ���ָ��û��ʵ��Ӱ��
//    return 0;
//}





//����ָ������


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

