#include <stdio.h>
#include <stdlib.h>

//int main()//测试代码，数组下标越界
//{
//    int i = 0;
//    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//    for(i=0;i<12;i++)
//    {
//        printf("2333\n");
//        arr[i] = 0;
//    }
//    return 0;
//}

//int main()
//    {
//        int i=0;
//        int arr[]={0};
//        for(i=0;i<10;i++)
//        {
//            arr[i]=i;
//            printf("%d\n",arr[i]);
//        }
//        return 0;
//    }

//void test2()
//    {
//        printf("! ");
//    }
//
//
//void test1()
//    {
//        test2();
//    }
//
//
//void test()
//    {
//        test1();
//    }
//
//int main()
//{
//    test();
//    return 0;
//}






////测试程序--源码
////实现阶乘
//int main()
//    {
//        int i=0;
//        int sum=0;
//        int n=0;
//        int ret=1;
//        scanf("%d",&n);
//        for(i=1;i<=n;i++)
//        {
//            int j=0;
//            for(j=1;j<=i;j++)
//            {
//                ret*=j;
//            }
//            sum+=ret;
//        }
//        printf("%d\n",sum);
//        return 0;
//    }


////修改后源码
//int main()
//    {
//        int i=0;
//        int sum=0;
//        int n=0;
//        int ret=1;
//        scanf("%d",&n);
//        for(i=1;i<=n;i++)
//        {
//            int j=0;
//            ret=1;
//            for(j=1;j<=i;j++)
//            {
//                ret*=j;
//            }
//            sum+=ret;
//        }
//        printf("%d\n",sum);
//        return 0;
//    }






//自己实现strcpy函数
//
//void my_strcpy(char* des,char* sor)//1.0
//    {
//        while(*sor!='\0')
//        {
//            *des=*sor;
//            des++;
//            sor++;
//        }
//        *des=*sor;
//    }





////优化
//void my_strcpy(char* des,char* sor)//1.1
//    {
//        while((*des++ = *sor++))
//        {
//            ;
//        }
//    }

#include <assert.h>

//void my_strcpy(char* des,char* sor)//1.2
//    {
//        assert(des!=NULL);
//        assert(sor!=NULL);
//        while((*des++ = *sor++))
//        {
//            ;
//        }
//    }
//
//void my_strcpy(char* des,const char* sor)//1.3
//    {
//        assert(des!=NULL);
//        assert(sor!=NULL);
//        while((*des++ = *sor++))
//        {
//            ;
//        }
//    }

char* my_strcpy(char* des,const char* sor)//1.4
    {
        char* ret=des;
        assert(des!=NULL);
        assert(sor!=NULL);
        while((*des++ = *sor++))
        {
            ;
        }
        return ret;
    }

int main()
    {
        char ch1[]="##################";
        char ch2[]="hello world";
//        my_strcpy(ch1,ch2);//NULL
//        printf("%s",ch1);//1.0~1.3
        printf("%s",my_strcpy(ch1,ch2));//1.4
        return 0;
    }
