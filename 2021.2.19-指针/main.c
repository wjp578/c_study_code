#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char* p="abcdef";//常量字符串 ，不能更改，段错误，segmetation fault
    //*p='w';
    //printf("%c\n",*p);
    printf("%s",p);
    return 0;
}
