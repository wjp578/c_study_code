#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char* p="abcdef";//�����ַ��� �����ܸ��ģ��δ���segmetation fault
    //*p='w';
    //printf("%c\n",*p);
    printf("%s",p);
    return 0;
}
