#include "head.h"

//1Ԫ1ƿ��ˮ��������ƿ=1ƿ��ˮ����xԪ�����ԺͶ���ƿ��ˮ

void DrinkingSoda()
{
    int money=0;
    printf("��������:");
    scanf("%d",&money);
    int empty=money;
    int total=money;
    while(empty>1)
    {
        total+=empty/2;
        empty=empty/2+empty%2;
    }
    printf("���ܹ�����%dƿ",total);
}
