#include <stdio.h>

//检测数据在内存中的储存方式（大端/小端）

//1.0
//int main()
//{
//    int a=1;
//    char* p=(char* )&a;
//    if(*p==1)
//        printf("小端存储");
//    else
//        printf("大端存储");
//    return 0;
//}

////优化
////1.1
//int check_sys()
////检测
////小端---1
////大端---0
//{
//    int a=1;
//    char* p=(char* )&a;
//    return *p;
//}

////优化
////1.2
//int check_sys()
//{
//    int a=1;
//    return *(char* )&a;
//}
//
//int main()
//{
//
//    if(check_sys()==1)
//        printf("小端存储");
//    else
//        printf("大端存储");
//    return 0;
//}


//$$$$$$$$$$$$$      ps:char->-128~127     char中             128 = 127 + 1 = -128            &&&$%$%$%$%$%%$%$%$%
//emp1:
int main()
{
    char a=-128;
    //10000000 00000000 00000000 10000000--原码
    //11111111 11111111 11111111 01111111--反码
    //11111111 11111111 11111111 10000000--补码
    //a为char类型，实际储存为 10000000
    char b=128;
    printf("%u\n",a);//打印整数，需整形提升，有符号数，补符号位 11111111 11111111 11111111 10000000
                     //打印无符号整数，该补码亦为原码，直接进制转化并打印
    printf("%u\n",b);
    //%u 无符号十进制整数
    //%d 有符号十进制整数

    return 0;
}
