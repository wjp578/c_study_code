#include "pointer.h"

//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 =AABCD��s2 = BCDAA������1
//����s1=abcd��s2=ACBD������0.

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
