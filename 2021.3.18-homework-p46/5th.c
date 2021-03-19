//实现字符串逆序

#include "homework.h"

void StringInversion()
{
//    int i=0;
    printf("请输入字符串(长度<100):");
    char ch[100]={0};

//    while((ch[i]=getchar())!='\n')//获取字符组成字符串
//    {
//        i++;
//    }

    scanf("%s",ch);//输入字符串
//    gets(ch);//直接获取字符串

//    char* p=ch;
//    p[i]='\0';//将获取字符获得的字符串的‘\n’换为‘\0’

//    //测试输入字符串长度是否正确计算
//    int j=0;
//    while(1)
//    {
//        if(*p=='\0')
//        {
//            break;
//        }
//        p++;
//        j++;
//    }
//    printf("%d\n",j);

    //实现字符串逆置
    char* start=ch;
    char* end=ch+strlen(ch)-1;

        //    //测试指针位置
//            printf("%d\n",(int)start);
//            printf("%d\n",(int)end);

    while(start < end)
    {
        char temp;
        temp=*start;
        *start=*end;
        *end=temp;
        start++;
        end--;
    }
    printf("%s\n",ch);

    return;
}
