#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mnue()
    {
        printf("----------������-----------\n");
        printf("-------1����Ϸ��ʼ---------\n");
        printf("-------0���˳���Ϸ---------\n");
        printf("---------------------------\n");
    }

void game()
    {
        int rn=rand()%100;
        int x=0;
        int left=0,right=99;
        printf("���������֣�%d~%d����",left,right);
        scanf("%d",&x);
        printf("\n");

        while(1)
        {

            if(x<rn)
            {
                left=x+1;
                printf("С��\n");
                printf("�������������֣�%d~%d��:",left,right);
                scanf("%d",&x);
                printf("\n");
            }
            else if(x>rn)
            {
                right=x-1;
                printf("����\n");
                printf("�������������֣�%d~%d��:",left,right);
                scanf("%d",&x);
                printf("\n");
            }
            else
                {
                    printf("��ϲ��¶���,������Ϊ%d\n\n",x);
                    break;
                }


        }



    }

void test()
    {
        srand((unsigned int)time(NULL));
        int input;
            do
            {

                mnue();
                printf("������:>");
                scanf("%d",&input);
                switch(input)
                    {
                        case 1:game();break;
                        case 0:printf("��Ϸ�˳��ɹ�\n\n");break;
                        default:printf("�Ƿ����룬����������\n\n");break;
                    }
            }
            while(input);

    }

int main()
{
    test();
    return 0;
}
