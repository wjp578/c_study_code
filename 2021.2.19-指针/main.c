#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//    const char* p="abcdef";//�����ַ��� �����ܸ��ģ��δ���segmetation fault
//    //*p='w';
//    //printf("%c\n",*p);
//    printf("%s",p);
//    return 0;
//}

int main()
//��֤��
//ÿ�����鴢���ַ��ͬ����ʹ������ͬ�������ٲ�ͬ�ռ�----------------------------    ����
//��������ͬ��ָ���ַ��ͬ������һ���ռ䣬ͬʱָ��ÿռ���Ԫ�ص�ַ-------------    ָ��
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
