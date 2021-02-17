#include"game.h"

void menu()
    {
            printf("********扫雷********\n");
            printf("****1、 游戏开始****\n");
            printf("****0、 退出游戏****\n");
            printf("********************\n");

    }

void game()
    {
        char mine[HANG_S][LIE_S]={{0}};
        char show[HANG_S][LIE_S]={{0}};
        initboard(mine,HANG_S,LIE_S,'0');
        initboard(show,HANG_S,LIE_S,'*');
        display(show,HANG,LIE);
        setmine(mine,HANG,LIE);
        //display(mine,HANG,LIE);
        findmine(mine,show,HANG,LIE);
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
//    char a = 0x66;
//    short b = 0x6600;
//    int c=0xb60000;
//    if(a==0x66)
//    printf("a");
//
//    if(b==0x6600)
//    printf("b");
//
//    if(c==0x00b60000)
//    printf("c");
    return 0;
}
