#include "contact.h"

void menu()
{
    printf("***********************************************************************\n");
    printf("***  0、退出  1、添加  2、删除  3、修改  4、查找  5、打印  6、重置  ***\n");
    printf("***********************************************************************\n");
}

int main()
{
    int input=0;
    loca p;
    init_contact(&p);
    do
    {
        menu();
        printf("请进行操作：");
        scanf("%d",&input);



        switch(input)
        {
            case exit_:
                printf("退出程序，感谢使用！\n");
                break;
            case add:
                add_contact(&p);
                break;
            case dele:
                dele_contact(&p);
                break;
            case modify:
                modify_contact(&p);
                break;
            case search:
                search_contact(&p);
                break;
            case show:
                show_contact(&p);
                break;
            case init:
                init_contact(&p);
                printf("初始化成功\n\n");
                break;
            default:
                printf("错误输入，请重新输入！\n\n");
                break;
        }

    }while(input);
    return 0;
}
