#include "head.h"

//设计一个函数，能把整形数组中奇数置于前面，偶数置于后面

void ElementDisplacement(int* cur,int sz)
{
    int *left=cur;
    int *right=cur+sz-1;

//方法一：

//    while(left<right)
//    {
//        //左指针为奇数
//        if(*left%2==1)
//        {
//            left++;
//        }
//
//        //左指针为偶数
//        else
//        {
//
//            //左指针偶数时，右指针为奇数
//            if(*right%2==1)
//            {
//                int temp;
//                temp=*left;
//                *left=*right;
//                *right=temp;
//                left++;
//                right--;
//            }
//
//            //左指针偶数时，右指针为偶数
//            else
//            {
//                cur=right;
//                while(*cur%2==0&&cur>left)
//                {
//                    cur--;
//                }
//                int temp;
//                temp=*left;
//                *left=*cur;
//                *cur=temp;
//                left++;
//                right--;
//            }
//        }
//    }




//方法二：

    while(left<right)
    {
        while(left<right&&*left%2==1)
        {
            left++;
        }
        while(left<right&&*right%2==0)
        {
            right--;
        }
        if(left<right)
        {
            int temp;
            temp=*left;
            *left=*right;
            *right=temp;
            left++;
            right--;
        }
    }



}

void ElementDisplacement_test()
{
//    int arr1[]={1,1824,214,24,325,26,4,51,31,35,13,5,246,34,63};
    int arr2[]={1,2,3,4,5,6,7,8,9,0,11};
//    int sz1=sizeof(arr1)/sizeof(arr1[0]);
    int sz2=sizeof(arr2)/sizeof(arr2[0]);
    ElementDisplacement(arr2,sz2);

    //打印
    int i=0;
    for(i=0;i<sz2;i++)
    {
        printf("%d ",arr2[i]);
    }

}
