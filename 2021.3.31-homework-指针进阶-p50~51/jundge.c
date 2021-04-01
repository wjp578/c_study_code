#include "pointer.h"

//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 =AABCD和s2 = BCDAA，返回1
//给定s1=abcd和s2=ACBD，返回0.

int jundge(char* s1,char* s2)
{
    int len=strlen(s1);

    int i=0;
    for(;i<len;i++)
    {
        Left_k(s1,len,1);
        if(strcmp(s1,s2)==0)
        {
            return 1;
        }
    }
    return 0;
}

void test2()
{
    char s1[]="abcd";
    char s2[]="ACBD";
//    printf("%d",strcmp(s1,s2));

    if(jundge(s1,s2)) printf("yes\n");
    else printf("no\n");
}
