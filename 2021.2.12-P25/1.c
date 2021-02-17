#include <stdio.h>
#include <stdlib.h>

//创建一个整形数组，完成一下操作

//1、实现函数init()初始化数组为全0
//2、实现print()打印数组的每个元素
//3、实现reverse()函数完成数组元素的逆置

void print(int arr[],int sz)
    {
        int i=0;
        for(i=0;i<sz;i++)
        {
            printf("%d ",arr[i]);
        }
    }

void init(int arr[],int sz)
    {
        int i=0;
        for(i=0;i<sz;i++)
        {
            arr[i]=0;
        }
    }

void reverse(int arr[],int sz)
    {
        int temp;
        int i;
        for(i=0;i<sz/2;i++)
        {
            temp=arr[i];
            arr[i]=arr[sz-i-1];
            arr[sz-i-1]=temp;
        }
    }

int main()
{
    int arr[]={0,1,2,3,4,5,6,7,8,9,2183,123,123,324,534};
    int sz=sizeof(arr)/sizeof(arr[0]);//计算元素个数
//    print(arr,sz);
//    init(arr,sz);
//    print(arr,sz);
    reverse(arr,sz);
    print(arr,sz);
return 0;
}
