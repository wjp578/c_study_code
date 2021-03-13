#include "contact.h"

void init_contact(loca* ps)
{
    memset(ps->pp,0,sizeof(ps->pp));
    ps->size=0;
}

void show_contact(const loca* ps)
{
    if(ps->size==0)
        printf("\n通讯录为空，请添加联系人\n\n");
    else
    {
        int i=1;
        printf("\n%s\t%s\t%-13s\t%s\t%s\n","序号","姓名","电话","年龄","性别");
        for(i=0;i<ps->size;i++)
        {
            printf("%d\t%s\t%-13s\t%d\t%s\n",
                   i+1,
                   ps->pp[i].name,
                   ps->pp[i].tel,
                   ps->pp[i].age,
                   ps->pp[i].sex);
        }
        printf("\n");
    }

}

void add_contact(loca* ps)
{
    if(ps->size==MAX)
    {
        printf("\n通讯录已满，无法添加\n\n");
    }
    else
    {
        printf("\n请输入姓名：");
        scanf("%s",ps->pp[ps->size].name);
        printf("请输入电话：");
        scanf("%s",ps->pp[ps->size].tel);
        printf("请输入年龄：");
        scanf("%d",&(ps->pp[ps->size].age));
        printf("请输入性别：");
        scanf("%s",ps->pp[ps->size].sex);

        printf("\n");

        ps->size++;
    }
}

void dele_contact(loca* ps)
{
        int s=0;
        char name_d[MAX_NAME];

        printf("请输入要删除联系人的姓名:");
                scanf("%s",name_d);

        int i=check_positioning(ps,name_d);

        if(0==i)
        {
            return;
        }
        else
        {
            int is=0;
            printf("确认删除此联系人吗？（确认--1；取消--2）\n");
            printf("请输入：");
            scanf("%d",&is);
            switch(is)
            {
                case 1:
                    for(s=i;s<ps->size;s++)
                    {
                            ps->pp[s]=ps->pp[s+1];
                    }
                    ps->size--;
                    printf("删除成功！\n\n");
                    break;
                case 2:
                    break;
                default:
                    printf("输入错误！\n");
            }

        }
}

void modify_contact(loca* ps)
{
    char name_m[MAX_NAME]={(0)};
    char newname[MAX_NAME];
    int newage;
    char newsex[MAX_SEX];
    char newtel[MAX_TEL];

    printf("请输入要修改联系人的姓名:");//(以“0为结尾”)
    scanf("%s",name_m);

    int i=check_positioning(ps,name_m);

    if(0==i)
    {
        return;
    }
    else
    {
        int m=0;
        int n=0;
        do
        {
            int num=0;
            printf("请选择要修改的项目(1、姓名；2、电话；3、年龄；4、性别):");
            scanf("%d",&m);
            switch(m)
            {
                case 1:
                    printf("姓名将修改为：");
                    scanf("%s",newname);
                    for(num=0;num<MAX_NAME;num++)
                    {
                        ps->pp[i].name[num]=newname[num];
                    }
                    printf("修改成功\n");
                    printf("请选择是否继续修改（1、是；0、否）：");
                    scanf("%d",&n);
                    break;

                case 2:
                    printf("电话将修改为：");
                    scanf("%s",newtel);
                    for(num=0;num<MAX_TEL;num++)
                    {
                        ps->pp[i].tel[num]=newtel[num];
                    }
                    printf("修改成功\n");
                    printf("请选择是否继续修改（1、是；0、否）：");
                    scanf("%d",&n);
                    break;

                case 3:
                    printf("年龄将修改为：");
                    scanf("%d",&newage);
                    ps->pp[i].age=newage;
                    printf("修改成功\n");
                    printf("请选择是否继续修改（1、是；0、否）：");
                    scanf("%d",&n);
                    break;

                case 4:
                    printf("性别将修改为：");
                    scanf("%s",newsex);
                    for(num=0;num<MAX_SEX;num++)
                    {
                        ps->pp[i].sex[num]=newsex[num];
                    }
                    printf("修改成功\n");
                    printf("请选择是否继续修改（1、是；0、否）：");
                    scanf("%d",&n);
                    break;
                }
            }while(n);
        }
        printf("\n");
}

void search_contact(const loca* ps)
{
    char name_s[MAX_NAME]={(0)};
    printf("请输入要查找联系人的姓名:");//(以“0为结尾”)
    scanf("%s",name_s);

    int i=check_positioning(ps,name_s);

    if(0==i)
    {
        return;
    }
    else
    {
        printf("姓名：%s\t电话：%-13s\t年龄：%d\t性别：%s\n",
                ps->pp[i].name,
                ps->pp[i].tel,
                ps->pp[i].age,
                ps->pp[i].sex);
    }

    printf("\n");
}

int check_positioning(const loca* ps,char name_check[MAX_NAME])
{
    int i=0;

    while(i<ps->size)
    {
        if(0==strcmp(ps->pp[i].name,name_check))
        {
            break;
        }
        i++;
    }

        if(i==ps->size || i==0)
        {
            printf("无此人信息\n\n");
            return 0;//返回0，匹配失败，退出上级函数
        }

    return i;//返回非0，匹配成功，返回下标i
}
