#include "contact.h"
//1.0
//简易通讯录

//2.0
//1、增加了动态内存/销毁动态内存
//2、增加了同名检测机制
//3、修改了初始化设置

//3.0
//增加了导入/导出文件操作
//修改check_position函数，使其能定位第一个元素


void menu()
{
    printf("*****************************************************\n");
    printf("***  0、退出  1、添加  2、删除  3、修改  4、查找  ***\n");
    printf("***  5、打印  6、导入  7、导出（保存） 8、初始化  ***\n");
    printf("*****************************************************\n");
}

int main()
{
    int input=0;
    loca p={(0)};
    init_contact(&p);
    do
    {
        menu();
        printf("请进行操作：");
        scanf("%d",&input);



        switch(input)
        {
            case exit_:
                destory_contact(&p);
                printf("\n退出程序，感谢使用！\n");
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
            case import:
                import_contact(&p);
                break;
            case export_:
                export_contact(&p);
                break;
            case init:
                init_contact(&p);
                printf("\n初始化成功\n\n");
                break;
            default:
                printf("错误输入，请重新输入！\n\n");
                break;
        }

    }while(input);
    return 0;
}
