#include"game.h"

void menu()
    {
            printf("*******������*******\n");
            printf("****1�� ��Ϸ��ʼ****\n");
            printf("****0�� �˳���Ϸ****\n");
            printf("********************\n");

    }

void game()
    {
        char jdg;
        char board[HANG][LIE]={{0}};

        initboard(board,HANG,LIE);
        displayboard(board,HANG,LIE);

        while(1)
        {
            player(board,HANG,LIE);
            displayboard(board,HANG,LIE);
            jdg=state(board,HANG,LIE);
                if(jdg!='C')
                    {
                        break;
                    }
            computer(board,HANG,LIE);
            displayboard(board,HANG,LIE);
            jdg=state(board,HANG,LIE);
                if(jdg!='C')
                    {
                        break;
                    }

        }

        if(jdg=='*')
            printf("��ϲ�㣬��һ�ʤ\n\n");
        else if(jdg=='#')
            printf("���ź������Ի�ʤ\n\n");
        else if(jdg=='D')
            printf("����ƽ��\n\n");
    }

void test()
    {
        srand((unsigned int)time(NULL));
        int input;
        do{
                menu();
                printf("������=>");
                scanf("%d",&input);
                switch(input)
                    {
                        case 1 : printf("��Ϸ������ʼ\n\n");game();break;
                        case 0 : printf("�˳���Ϸ\n\n");break;
                        default : printf("�������\t������ѡ��\n\n");break;
                    }

        }

        while(input);
    }


int main()
    {

        test();



        return 0;
    }
