#include <stdio.h>
#include <string.h>
int main()
{
    char ch1[3]="abc";//������ΪԪ�ظ���
    char ch2[]={'a','b','c','0','a','b','c',0};
    printf("%d\n",strlen(ch1));
    printf("%d\n",strlen(ch2));
    printf("%c\n",ch1[2]);//������ΪԪ���±�
    printf("%c\n",ch2[4]);
    return 0;
    }
