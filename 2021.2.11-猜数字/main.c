#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mnue()
    {
        printf("----------三子棋-----------\n");
        printf("-------1、游戏开始---------\n");
        printf("-------0、退出游戏---------\n");
        printf("---------------------------\n");
    }

void game()
    {
        int rn=rand()%100;
        int x=0;
        int left=0,right=99;
        printf("请输入数字（%d~%d）：",left,right);
        scanf("%d",&x);
        printf("\n");

        while(1)
        {

            if(x<rn)
            {
                left=x+1;
                printf("小了\n");
                printf("请重新输入数字（%d~%d）:",left,right);
                scanf("%d",&x);
                printf("\n");
            }
            else if(x>rn)
            {
                right=x-1;
                printf("大了\n");
                printf("请重新输入数字（%d~%d）:",left,right);
                scanf("%d",&x);
                printf("\n");
            }
            else
                {
                    printf("恭喜你猜对了,该数字为%d\n\n",x);
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
                printf("请输入:>");
                scanf("%d",&input);
                switch(input)
                    {
                        case 1:game();break;
                        case 0:printf("游戏退出成功\n\n");break;
                        default:printf("非法输入，请重新输入\n\n");break;
                    }
            }
            while(input);

    }

int main()
{
    test();
    return 0;
}
