//ʵ���ַ�������

#include "homework.h"

void StringInversion()
{
//    int i=0;
    printf("�������ַ���(����<100):");
    char ch[100]={0};

//    while((ch[i]=getchar())!='\n')//��ȡ�ַ�����ַ���
//    {
//        i++;
//    }

    scanf("%s",ch);//�����ַ���
//    gets(ch);//ֱ�ӻ�ȡ�ַ���

//    char* p=ch;
//    p[i]='\0';//����ȡ�ַ���õ��ַ����ġ�\n����Ϊ��\0��

//    //���������ַ��������Ƿ���ȷ����
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

    //ʵ���ַ�������
    char* start=ch;
    char* end=ch+strlen(ch)-1;

        //    //����ָ��λ��
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
