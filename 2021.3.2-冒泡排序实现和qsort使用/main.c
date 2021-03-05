#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//冒泡排序实现
//159643287
//156432879
//154326789
//143256789
//132456789
//123456789

//void bubble_sort(int arr[],int sz)
//{
//    int i=0;
//    for(i=0; i<sz-1; i++)
//    {
//        int j=0;
//        for(j=0; j<sz-1-i; j++)
//        {
//            if(arr[j]>arr[j+1])
//            {
//                int t=arr[j];
//                arr[j]=arr[j+1];
//                arr[j+1]=t;
//            }
//        }
//    }
//
//}
//
//int main()
//{
//    int i=0;
//    int arr[]= {2,4,1,3,6,8,7,9,5,10,0};
//    int sz=sizeof(arr)/sizeof(arr[0]);
//    bubble_sort(arr,sz);
//    for(i=0; i<sz; i++)
//    {
//        printf("%d ",arr[i]);
//    }
//    return 0;
//}

void bubble_sort(void* arr,int sz,int width,int(*cmp)(const void*,const void*));

int int_arr_sort(const void* e1,const void*e2)
{
    return *(int*)e1-*(int*)e2;
}

void int_arr_print()
{
    int i=0;
    int arr[]= {2,4,1,3,6,8,7,9,5,10,0};
    int sz=sizeof(arr)/sizeof(arr[0]);
//    qsort(arr,sz,sizeof(arr[0]),int_arr_sort);
    bubble_sort(arr,sz,sizeof(arr[0]),int_arr_sort);
    for(i=0; i<sz; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n\n");
}

int double_arr_sort(const void* e1,const void*e2)
{
    if(*(double*)e1<*(double*)e2)
        return -1;
    else if(*(double*)e1==*(double*)e2)
        return 0;
    else
        return 1;
//    return (int)(*(double*)e1-*(double*)e2);//强制类型转换会造成精度丢失,相距较近的数会出现无法排序情况。
}

void double_arr_print()
{
    int i=0;
    double arr[]= {2.4874,4.0,4.245,6.5,2.4745,1.9,12.65,3.652,8.52};
//    double arr[]={3.0,1.0,7.0,4.0,2.0};
    int sz=sizeof(arr)/sizeof(arr[0]);
//    qsort(arr,sz,sizeof(arr[0]),double_arr_sort);
    bubble_sort(arr,sz,sizeof(arr[0]),double_arr_sort);
    for(i=0; i<sz; i++)
    {
        printf("%lf ",arr[i]);
    }
    printf("\n\n");
}

typedef struct
{
    char name[20];
    int age;
}stu;

int struct_name_sort(const void* e1,const void*e2)
{
    return strcmp(((stu*)e1)->name,((stu*)e2)->name);
}

int struct_age_sort(const void* e1,const void*e2)
{
    return ((stu*)e1)->age - ((stu*)e2)->age;
}

void struct_name_print()
{
    int i=0;
    stu s[]={{"张三",20},{"李四",27},{"老黑",31},{"胖子",23}};
    int sz=sizeof(s)/sizeof(s[0]);
//    qsort(s,sz,sizeof(s[0]),struct_name_sort);
    bubble_sort(s,sz,sizeof(s[0]),struct_name_sort);
    printf("按名字排序：\n");
    for(i=0; i<sz; i++)
    {
        printf("%s\t%d",s[i].name,s[i].age);
        printf("\n");
    }
    printf("\n");
}

void struct_age_print()
{
    int i=0;
    stu s[]={{"张三",20},{"李四",27},{"老黑",31},{"胖子",23}};
    int sz=sizeof(s)/sizeof(s[0]);
//    qsort(s,sz,sizeof(s[0]),struct_age_sort);
    bubble_sort(s,sz,sizeof(s[0]),struct_age_sort);
    printf("按年龄排序：\n");
    for(i=0; i<sz; i++)
    {
        printf("%s\t%d",s[i].name,s[i].age);
        printf("\n");
    }
    printf("\n");
}

//int main()
//{
//    int_arr_print();
//    double_arr_print();
//    struct_name_print();
//    struct_age_print();
//    return 0;
//}



//用冒泡排序模拟实现qsort

void swap(char* em1,char* em2,int w)
{
    int i=0;
    for(i=0;i<w;i++)
    {
        char t=*em1;
        *em1=*em2;
        *em2=t;
        em1++;
        em2++;
    }
}

void bubble_sort(void* arr,int sz,int width,int(*cmp)(const void*,const void*))
{
    int i=0;
    for(i=0; i<sz-1; i++)
    {
        int j=0;
        for(j=0; j<sz-1-i; j++)
        {
            if(cmp((char*)arr+j*width,(char*)arr+(j+1)*width)>0)//返回值大于0，进行元素的交换
            {
                swap((char*)arr+j*width,(char*)arr+(j+1)*width,width);
            }
        }
    }

}

int main()
{
    int_arr_print();
    double_arr_print();
    struct_name_print();
    struct_age_print();
    return 0;
}
