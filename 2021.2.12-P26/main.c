#include <stdio.h>
#include <stdlib.h>


////6����ӡ�˷��ھ���x*x��x���û�����
//int main()
//{
//    int i=0,j=0,x=0;
//    printf("������˷����С��");
//    scanf("%d",&x);
//    for(i=1;i<=x;i++)
//    {
//        for(j=1;j<=i;j++)
//        {
//            printf("%dx%d=%d\t",i,j,i*j);
//        }
//        printf("\n");
//    }
//    return 0;
//}

////7���õݹ�ط�ʽ��ӡһ������ÿһλ
//void print_number(int n)
//{
//    if(n>9)
//        print_number(n/10);
//    printf("%d ",n%10);
//}

////8��ʵ�ֵݹ�׳�

//int factorial(int n)
//    {
//        int i=0;
//        if(n==1)
//            return 1;
//        else
//        {
//            return factorial(n-1)*n;
//        }
//    }


////9���ݹ�ģ��strlen
//int fa_strlen(char* ch)
//    {
//        if(*ch=='\0')
//            return 0;
//        else
//            return 1+fa_strlen(ch+1);
//    }

////9���ǵݹ�ģ��strlen
//int my_strlen(char* ch)
//    {
//        int count=0;
//        while(*ch!='\0')
//            {
//                count++;
//                ch++;
//            }
//            return count;
//    }

////10���ǵݹ�ʵ���ַ�������
//void reverse_string(char* arr)// arr[]Ҳ��
//    {
//        int l=0;
//        int r=my_strlen(arr)-1;
//        while(l<r)
//        {
//            int tmp=arr[l];
//            arr[l]=arr[r];
//            arr[r]=tmp;
//            l++;
//            r--;
//        }
//    }

////10���ݹ�ʵ���ַ�������
//void reverse_string(char* arr)
//    {
//        int left=0;
//        int right=my_strlen(arr)-1;
//        if(my_strlen(arr+1)>1)
//        {
//            int temp=arr[left];
//            arr[left]=arr[right];
//            arr[right]='\0';
//            reverse_string(arr+1);
//            arr[right]=temp;
//        }
//
//    }


////11���ݹ�ʵ��--����һ������ÿλ֮�Ͳ���ӡ
//int DigitSum(int n)
//{
//    if(n>9)
//    {
//        printf("%d",n%10);
//        printf("+");
//        return DigitSum(n/10)+n%10;
//    }
//    else
//        {
//            printf("%d",n);
//            printf("=");
//            return n;
//        }
//}

////11���ݹ�ʵ��n��k�η�
//double pow(double n,double k)
//    {
//        if(k>0)
//            return pow(n,k-1)*n;
//        else if(k==0)
//            return 1.0;
//        else
//            return 1.0/pow(n,-k);
//    }

////12��쳲���������ʵ�֣��ݹ飩
//int Fibonacci(int n)
//    {
//        if(n==1||n==2)
//            return 1;
//        else
//            return Fibonacci(n-1)+Fibonacci(n-2);
//    }

//12��쳲���������ʵ�֣��ݹ飩
int Fibonacci(int n)
    {
        int tmp1=1;
        int tmp2=1;
        int tmp=1;
        int i=0;
        while(n-->2)
        {
            tmp=tmp1+tmp2;
            tmp1=tmp2;
            tmp2=tmp;
        }
        return tmp;
    }

int main()
    {
//        char ch[]="hello world";
        int input=0;
        printf("������һ�����֣�");
        scanf("%d",&input);

//        double n=0;
//        double k=0;
//        printf("������n=");
//        scanf("%lf",&n);
//        printf("������k=");
//        scanf("%lf",&k);

//        print_number(input);//7--�ݹ��ӡ��

//        printf("%d",factorial(input));//8--�ݹ�׳�

//        printf("%d",fa_strlen(ch));//9--�ݹ�ģ��strlen



//        01:11:36
//        2021.2.13



//        printf("%d",my_strlen(ch));//9--�ǵݹ�ģ��strlen

//        reverse_string(ch);//10--�ǵݹ�ʵ������
//        reverse_string(ch);//10--�ݹ�ʵ������
//        printf("%s",ch);

//        printf("%d",DigitSum(input));

//        double ret=pow(n,k);
//        printf("n^k=%lf",ret);//11--�ݹ�ʵ��n��k�η�

        printf("����Ϊ��%d",Fibonacci(input));//12--�ݹ�/�ǵݹ�ʵ��쳲���������

        return 0;
    }
