#include"game.h"

void initboard(char board[HANG][LIE],int hang,int lie)
    {
        int i,j;
        for(i=0;i<hang;i++)
            for(j=0;j<lie;j++)
                board[i][j]=' ';
    }

void displayboard(char board[HANG][LIE],int hang,int lie)
    {
        int i,j;

        for(i=0;i<hang;i++)
            {
                //��ӡ�ַ���
                for(j=0;j<lie;j++)
                    {
                        printf(" %c ",board[i][j]);
                        if(j<lie-1)
                            printf("|");
                    }
                printf("\n");
                //��ӡ�ָ���
                if(i<hang-1)
                for(j=0;j<lie;j++)
                    {
                        printf("---");
                        if(j<lie-1)
                            printf("|");

                    }
                    printf("\n");
            }
    }

void player(char board[HANG][LIE],int hang,int lie)
    {
        int x,y;
        while(1)
        {
            printf("��������������=>");
            scanf("%d%d",&x,&y);
            printf("��ң�\n");
            if(x>=1&&x<=hang&&y>=1&&y<=lie)
            {
                if(board[x-1][y-1]==' ')
                    {
                        board[x-1][y-1]='*';
                        break;
                    }

                else
                    printf("��λ����������\n");
            }
            else
                printf("�Ƿ�����\n");
        }
    }

void computer(char board[HANG][LIE],int hang,int lie)
    {
        int x,y;
        printf("���ԣ�\n");
        while(1)
        {
            x=rand()%hang;
            y=rand()%lie;
            if(board[x][y]==' ')
            {
                board[x][y]='#';
                break;
            }
        }
    }

int fall(char board[HANG][LIE],int hang,int lie)
    {
        int i,j;
        for(i=0;i<hang;i++)
            for(j=0;j<lie;j++)
                {
                    if(board[i][j]==' ')
                        return 0;
                }
        return 1;
    }

//���Ӯ--*
//����Ӯ--#
//ƽ��----D
//����----C

char state(char board[HANG][LIE],int hang,int lie)
    {
        int i;

        for(i=0;i<hang;i++)
        {
            if(board[i][0]==board[i][1]&&board[i][0]==board[i][2]&&board[i][0]!=' ')
                return board[i][0];
        }

        for(i=0;i<lie;i++)
        {
            if(board[0][i]==board[1][i]&&board[0][i]==board[2][i]&&board[0][i]!=' ')
                return board[0][i];
        }

        if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]&&board[0][0]!=' ')
            return board[0][0];
        else if(board[0][2]==board[1][1]&&board[0][2]==board[2][0]&&board[0][2]!=' ')
            return board[0][2];

        if(1==fall(board,HANG,LIE))
            {
                return 'D';
            }

        return 'C';
    }
