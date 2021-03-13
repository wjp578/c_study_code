#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

//#pragma pack(2)//设置默认对齐数
struct S
{
    char c;//1
    double i;//16
};//16

struct A
{
    double a;//8
    int d;//12
    char w;//13
    char iu;//14
    float u;//20
    char n[20];//20
};//40

struct B
{
    char a;//1
    double d;//16
    char w;//17
    struct A i;//64
    float u;//68
};//72

struct C
{
    int m;//0
    long n;//4
    struct B b;//8
    char v;//80
    char c;//81
    float x;//84
};//88

struct wd//位段
{
    int a:1;
    int b:3;
    char c:1;
}wd;

enum em
{
    r,
    g,
    b
}em;

union un
{
    char a;
    int b;
}un;

int main()
{
//    struct S s={0};
//    struct A a={0};
//    struct B b={0};
//    struct C c={0};
//    enum em a=g;
    printf("%d\n",sizeof(un));
    printf("%d\n",offsetof(struct C,x));
    return 0;
}
