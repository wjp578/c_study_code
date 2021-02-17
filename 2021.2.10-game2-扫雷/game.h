#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HANG 9
#define  LIE 9
#define HANG_S HANG+2
#define LIE_S LIE+2
#define mine_count 10

void initboard(char board[HANG_S][LIE_S],int hang_s,int lie_s,char set);
void display(char board[HANG_S][LIE_S],int hang,int lie);
void setmine(char board[HANG_S][LIE_S],int hang,int lie);
void findmine(char mine[HANG_S][LIE_S],char show[HANG_S][LIE_S],int hang,int lie);
