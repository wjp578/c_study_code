//ʵ�ֹ��ܣ��������֣��ж��Ƿ�Ϊ����������Ϊ�����������������Ϊ���������0��������������
#include<stdio.h>

int main()
{
    int a;
    printf("���������֣�");
    scanf("%d",&a);

        if(0 == a%2)
            printf("������������");
        else
        {
            int i = 1;
            while(i <= a)
                {
                    if(1 == i%2)
                    printf("%d ",i);
                    i += 1;//i=i+1;i++
                    }
        }
        return 0;
}
