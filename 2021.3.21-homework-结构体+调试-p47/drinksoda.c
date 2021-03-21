#include "head.h"

//1元1瓶汽水，两个空瓶=1瓶汽水，给x元，可以和多少瓶汽水

void DrinkingSoda()
{
    int money=0;
    printf("你身上有:");
    scanf("%d",&money);
    int empty=money;
    int total=money;
    while(empty>1)
    {
        total+=empty/2;
        empty=empty/2+empty%2;
    }
    printf("你总共喝了%d瓶",total);
}
