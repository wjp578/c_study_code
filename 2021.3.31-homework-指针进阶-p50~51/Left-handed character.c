#include "pointer.h"

//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

void Left_k(char* s,int len,int k)
{
    int cnt=0;
    for(cnt=0;cnt<k;cnt++)
    {
        char temp=*s;
        int i=0;
        for(i=0;i<len-1;i++)
        {
           *(s+i) =*(s+i+1);
        }
        *(s+i)=temp;
    }
}

void print(char* s,int len)
{
    int i=0;
    for(i=0;i<len;i++)
    {
        printf("%c",*(s+i));
    }
}

void test1()
{
    char string[]="ABCD";
    int len=strlen(string);

    Left_k(string,len,2);
    print(string,len);
}
