#include"game.h"

void initboard(char board[HANG_S][LIE_S],int hang_s,int lie_s,char set)
    {
        int i,j;
        for(i=0;i<hang_s;i++)
            for(j=0;j<lie_s;j++)
                board[i][j]=set;
    }

void display(char board[HANG_S][LIE_S],int hang,int lie)
    {
        int i,j;
        for(j=0;j<=lie;j++)
                {
                    printf("%d ",j);
                }
        printf("\n");
        for(i=1;i<=hang;i++)
        {
            printf("%d ",i);
            for(j=1;j<=lie;j++)
                {
                    printf("%c ",board[i][j]);
                }
            printf("\n");
        }

    }

void setmine(char board[HANG_S][LIE_S],int hang,int lie)
    {
        int count=mine_count;

        while(count)
        {
            int x=rand()%hang+1;
            int y=rand()%lie+1;
            if(board[x][y]=='0')
            {
                board[x][y]='1';
                count--;
            }
        }


    }

int countmine(char mine[HANG_S][LIE_S],int x,int y)
    {
        return
        mine[x-1][y-1]+
        mine[x-1][y]+
        mine[x-1][y+1]+
        mine[x][y-1]+
        mine[x][y+1]+
        mine[x+1][y-1]+
        mine[x+1][y]+
        mine[x+1][y+1]-
        8*'0';
    }

void findmine(char mine[HANG_S][LIE_S],char show[HANG_S][LIE_S],int hang,int lie)
    {
        int x,y;
        int count;
        int win=0;
        while(win<hang*lie-mine_count)
        {
            printf("请输入坐标：");
            scanf("%d%d",&x,&y);
            if(x>=1&&x<=hang&&y>=1&&y<=lie)//输入合法，进入排雷
        {
            if(mine[x][y]=='0')//未踩雷，统计周围雷个数
                {
                    count=countmine(mine,x,y);
                    show[x][y]='0'+count;
                    display(show,HANG,LIE);
                    win++;
                }
            else//踩雷，游戏结束
                {
                    printf("很遗憾，扫雷失败！\n\n");
                    display(mine,HANG,LIE);
                    break;
                }
        }
        else
            printf("非法输入，请重新输入\n\n");
        }
        if(win==hang*lie-mine_count)
            {
                printf("恭喜你，扫雷成功！\n\n全棋盘:\n");
                display(mine,hang,lie);
                printf("\n\n\n");
            }
    }





