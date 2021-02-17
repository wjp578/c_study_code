#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HANG 3
#define  LIE 3

void test();
void game();
void initboard(char board[HANG][LIE],int hang,int lie);
void displayboard(char board[HANG][LIE],int hang,int lie);
void player(char board[HANG][LIE],int hang,int lie);
void computer(char board[HANG][LIE],int hang,int lie);
char state(char board[HANG][LIE],int hang,int lie);
