#include <stdio.h>
#include <stdlib.h>

//����һ���������飬���һ�²���

//1��ʵ�ֺ���init()��ʼ������Ϊȫ0
//2��ʵ��print()��ӡ�����ÿ��Ԫ��
//3��ʵ��reverse()�����������Ԫ�ص�����

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
    int sz=sizeof(arr)/sizeof(arr[0]);//����Ԫ�ظ���
//    print(arr,sz);
//    init(arr,sz);
//    print(arr,sz);
    reverse(arr,sz);
    print(arr,sz);
return 0;
}
