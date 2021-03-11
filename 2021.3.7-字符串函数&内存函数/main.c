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

//模拟strstr --- 查找字符串
char* my_strstr_1(char* str,char* find)
{
    char* p1=str;
    char* p2=find;

    while(*str)
    {
        while((*p1==*p2)&&(*p2!='\0'))
        {
            p1++;
            p2++;
        }
        if(*p2!='\0')
        {
            str++;
            p1=str;
            p2=find;
        }
        else if(*p2=='\0')
        {
            return str;
        }
    }

    if(*p1=='\0')
    {
        return "未找到字符串";
    }
    return 0;
}

//模拟memcpy
void* my_memcpy(const void* src,void* des,int size)
{

    while(size--)
    {
        *(char*)des=*(char*)src;
        ++src;//++(char*)src;
        ++des;//++(char*)des;
    }
    void* print=des;
    return print;
}

//模拟memmove
void* my_memmove(const void* str1,const void* str2,int size)
{
    while(size--)
    {
        if(str1<str2)
        {
            *((char*)str2+size)=*((char*)str1+size);
        }
        if(str1>str2)
        {
            *((char*)str2++)=*((char*)str1++);
        }
    }
    return 0;
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

//    char ch0[10]="abc\0xxxx";
//    char ch1[10]="abc";
//    char ch2[]="def";
//    char ch3[10]="abc";
//    char ch4[]="zzzzzz";
//    char ch5[]="***";
//    char ch6[]="zzzyyy";

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
//    printf("%s\n",my_strncpy(ch4,ch3,6));
//    printf("%s\n",my_strncpy(ch1,ch4,2));   //2--abzzzz;3--abczzz

//    printf("%s\n",my_strncat(ch0,ch2,5));
//    printf("%d\n",my_strlen_1(ch1));

//     printf("%d\n",my_strncmp(ch4,ch3,6));

//      p54 -- 13:20


//    char str[]="abbbcdef";
//    char ch[]="bbc";
//    printf("%s\n",my_strstr_1(str,ch));

//    char ch[]="348.6555@daye&679bai@qq.com";
//    char seq[]=".@&";
//    char buf[1024]="0";
//    strcpy(buf,ch);
//    char* ret = NULL;
//    printf("%s\n",buf);//原字符串
//    for(ret=strtok(ch,seq);ret!=NULL;ret=strtok(NULL,seq))
//    {
//        printf("%s ",ret);//分割后字符串
//    }
//    printf("\n");
//    printf("%s\n",ch);//分割处理后的原字符串

//    int arr1[]={1,2,3,4,5,6,7,8,9,10};
//    int sz=sizeof(arr1)/sizeof(arr1[0]);
//    int i=0;
////    int arr2[]={0};
////
////    my_memcpy(arr1,arr2,sizeof(arr1));
//    my_memmove(arr1+2,arr1,20);
//    for(i=0;i<sz;i++)
//    {
//        printf("%d ",arr1[i]);
////        printf("%d ",arr2[i]);
    }
//
//    typedef struct student
//    {
//        char name[20];
//        int no;
//    }stu;
//    stu s1[]={{"zhangsan",19},{"wangwu",21}};
//    stu s2[3]={0};
//    my_memcpy(s1,s2,sizeof(s1));

    return 0;
}


