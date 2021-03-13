#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define MAX 1000
#define START_CAPACITY 1//初始容量
#define ADD_CAPACITY 1//满容后每次添加容量


#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TEL 20

typedef struct
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tel[MAX_TEL];
}data;

typedef struct
{
    data* pp;//people
    int size;
    int capacity;
}loca;

enum options
{
     exit_,
     add,
     dele,
     modify,
     search,
     show,
     init
};

void init_contact(loca* ps);
void show_contact(const loca* ps);
void destory_contact(loca* ps);

void add_contact(loca* ps);
void dele_contact(loca* ps);
void modify_contact(loca* ps);
void search_contact(const loca* ps);

int check_positioning(const loca* ps,char name_check[MAX_NAME]);
void cbeck_capacity(loca* ps);
