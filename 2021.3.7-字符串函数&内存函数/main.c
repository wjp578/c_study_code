#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//模拟strlen

//1---计数器
//2---递归
//3---指针-指针

int my_strlen_1(const char* str)
{
    assert(str!=NULL);
    int count=0;
    while(*str++)
    {
        count++;
    }
    return count;
}

int my_strlen_2(const char* str)
{
    assert(str!=NULL);
    if(*str=='\0')
    {
        return 0;
    }
    else
    {
        str++;
        return my_strlen_2(str)+1;
    }
}

int my_strlen_3(char* str)
{
    assert(str!=NULL);
    char* start=str;
    while(*str)
    {
        str++;
    }
    return str-start;
}


//模拟strcpy

char* my_strcpy(const char* sor,char* des)
{
    char* print=des;
    while((*des++=*sor++))
    {
        ;
    }
    return print;
}


//模拟strcat
char* my_strcat(char* sor,const char* additional)
{
    char* print=sor;
    while(*sor)
    {
        sor++;
    }
    while((*sor++ = *additional++));
    return print;
}

int main()
{
//    char arr[]="abcdefg";
////    char arr[]={'a','b','c','d','e',0};
//    printf("%d\n",my_strlen_3(arr));

//    if(strlen("abc")-strlen("abcdef")<0)
//    {
//        printf("signed");
//    }
//    else
//    {
//        printf("unsigned");
//    }

//    char a1[]="abcde";
////    printf("%s\n",a1);
//    char a2[]="************";
//    if(my_strlen_1(a1)-my_strlen_1(a2)<=0)
//    {
//        printf("%s",my_strcpy(a1,a2));
//    }
//    else
//    {
//        printf("无法拷贝");
//    }

    char ch1[10]="abc";
    char ch2[]="def";
    printf("%s",my_strcat(ch1,ch2));
    return 0;
}


