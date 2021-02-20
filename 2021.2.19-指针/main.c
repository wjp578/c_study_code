#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//    const char* p="abcdef";//常量字符串 ，不能更改，段错误，segmetation fault
//    //*p='w';
//    //printf("%c\n",*p);
//    printf("%s",p);
//    return 0;
//}

int main()
//验证：
//每个数组储存地址不同（即使内容相同），开辟不同空间----------------------------    数组
//若内容相同（指针地址相同）开辟一个空间，同时指向该空间首元素地址-------------    指针
{
    char arr1[]="abcdef";
    char arr2[]="abcdef";
    char* p1="abcdef";
    char* p2="abcdef";
    //if(arr1==arr2)
    if(p1==p2)
    {
        printf("same");
    }
    else
        printf("not same");
    return 0;
}
