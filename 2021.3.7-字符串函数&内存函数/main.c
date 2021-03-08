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

//模拟strcmp我真皀
//1=2 返回0
//1<2 返回<0
//1>2 返回>0
int my_strcmp(const char* str1,const char* str2)
{
    while(*str1==*str2)
    {
        if(*str1=='\0')
        {
            return 0;
        }
        str1++;
        str2++;
    }
    return *str1-*str2;
}


//模拟strncpy
char* my_strncpy(const char* src,char* des,int num)
{
    char* print=des;
    int i=0;
    for(i=0;i<num;i++)
    {
        if(*src=='\0')
        {
            *des++ = '\0';
        }
        else
        {
            *des++=*src++;
        }

    }
    return print;
}

//模拟strncat

char* my_strncat(char* src,char* add,int num)
{
    char* print=src;
    while(*src!='\0')
    {
        src++;
    }
    while(num&&*add!='\0')
    {
        num--;
        *src=*add;
        src++;
        add++;
    }
    *src='\0';
    return print;
}

//模拟strncmp

int my_strncmp(const char* str1,const char* str2,int num)
{
    while(num&&*str1==*str2)
    {

        str1++;
        str2++;
        num--;
    }
    if(num==0)
    {
        return 0;
    }
    else
    {
        return *str1-*str2;
    }
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
    char ch3[]="abc";
    char ch4[]="zzzzzz";
    char ch5[]="***";
    char ch6[]="zzzyyy";

//    printf("%s",my_strcat(ch1,ch2));

    //strcmp
//    printf("%d\n",my_strcmp(ch1,ch5));
//    if(my_strcmp(ch1,ch5)<0)
//    {
//        printf("%d %d\n",my_strlen_1(ch1),my_strlen_1(ch4));
//    }
//    else if(my_strcmp(ch1,ch5)==0)
//    {
//        printf("%s\n",my_strcpy(ch5,ch3));
//    }
//    else
//    {
//        printf("%s\n",my_strcat(ch1,ch2));
//    }

//    printf("%s\n",my_strcpy(ch1,ch4));    //abc
//    printf("%s\n",my_strncpy(ch1,ch4,2));   //2--abzzzz;3--abczzz

//    printf("%s\n",my_strncat(ch1,ch4,1));
//    printf("%d\n",my_strlen_1(ch1));

//     printf("%d\n",my_strncmp(ch4,ch6,2));

//      p54 -- 13:20

    return 0;
}


