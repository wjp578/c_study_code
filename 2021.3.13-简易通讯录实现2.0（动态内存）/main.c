#include "contact.h"

//1�������˶�̬�ڴ�/���ٶ�̬�ڴ�
//2��������ͬ��������
//3���޸��˳�ʼ������

void menu()
{
    printf("*************************************************************************\n");
    printf("***  0���˳�  1�����  2��ɾ��  3���޸�  4������  5����ӡ  6����ʼ��  ***\n");
    printf("*************************************************************************\n");
}

int main()
{
    int input=0;
    loca p={(0)};
    init_contact(&p);
    do
    {
        menu();
        printf("����в�����");
        scanf("%d",&input);



        switch(input)
        {
            case exit_:
                destory_contact(&p);
                printf("�˳����򣬸�лʹ�ã�\n");
                break;
            case add:
                add_contact(&p);
                break;
            case dele:
                dele_contact(&p);
                break;
            case modify:
                modify_contact(&p);
                break;
            case search:
                search_contact(&p);
                break;
            case show:
                show_contact(&p);
                break;
            case init:
                init_contact(&p);
                printf("��ʼ���ɹ�\n\n");
                break;
            default:
                printf("�������룬���������룡\n\n");
                break;
        }

    }while(input);
    return 0;
}
