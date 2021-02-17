#include"game.h"

void menu()
    {
            printf("*******三子棋*******\n");
            printf("****1、 游戏开始****\n");
            printf("****0、 退出游戏****\n");
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
            printf("恭喜你，玩家获胜\n\n");
        else if(jdg=='#')
            printf("很遗憾，电脑获胜\n\n");
        else if(jdg=='D')
            printf("该轮平局\n\n");
    }

void test()
    {
        srand((unsigned int)time(NULL));
        int input;
        do{
                menu();
                printf("请输入=>");
                scanf("%d",&input);
                switch(input)
                    {
                        case 1 : printf("游戏即将开始\n\n");game();break;
                        case 0 : printf("退出游戏\n\n");break;
                        default : printf("输入错误\t请重新选择\n\n");break;
                    }

        }

        while(input);
    }


int main()
    {

        test();



        return 0;
    }
