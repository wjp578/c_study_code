#include "contact.h"

void init_contact(loca* ps)
{
    if(ps->size!=0)
    {
        destory_contact(ps);
        ps->size=0;
        init_contact(ps);
    }
    else
    {
        ps->pp=(data*)malloc(START_CAPACITY*sizeof(data));
        if(ps->pp==NULL)
        {
            return;
        }
        else
        {
            ps->size=0;
            ps->capacity=START_CAPACITY;
        }
    }


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

void destory_contact(loca* ps)
{
    free(ps);
    ps=NULL;
}

void add_contact(loca* ps)
{
        check_capacity(ps);


        printf("\n请输入姓名：");
        scanf("%s",ps->pp[ps->size].name);



        //检测是否重名
        if(check_positioning(ps,ps->pp[ps->size].name)!=-1)
        {
            printf("已存在该联系人\n\n");
            return;
        }

        printf("请输入电话：");
        scanf("%s",ps->pp[ps->size].tel);
        printf("请输入年龄：");
        scanf("%d",&(ps->pp[ps->size].age));
        printf("请输入性别：");
        scanf("%s",ps->pp[ps->size].sex);

        printf("添加成功！\n");
        printf("\n");

        ps->size++;
}

void dele_contact(loca* ps)
{
        int s=0;
        char name_d[MAX_NAME];

        printf("请输入要删除联系人的姓名:");
                scanf("%s",name_d);

        int i=check_positioning(ps,name_d);

        if(-1==i)
        {
            printf("无此人信息\n\n");
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

    if(-1==i)
    {
        printf("无此人信息\n\n");
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

    if(-1==i)
    {
        printf("无此人信息\n\n");
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

void check_capacity(loca* ps)
{
    if(ps->capacity==ps->size)
    {
        data* ptr=(data*)realloc(ps->pp,(ps->capacity+ADD_CAPACITY)*sizeof(data));
        if(ptr==NULL)
        {
//            printf("增容失败\n");//检查增容效果
        }
        else
        {
            ps->pp=ptr;
            ps->capacity+=ADD_CAPACITY;
//            printf("增容成功\n");//检查增容效果
        }
    }
}

int check_positioning(const loca* ps,char name_check[MAX_NAME])
{

    int i=0;
    for(i=0;i<ps->size;i++)
    {
        if(strcmp(ps->pp[i].name,name_check)==0)
        {
            return i;
        }
    }
    return -1;
}

void export_contact(loca* ps)
{
    FILE* tem=fopen("contact.data","wb");
    if(tem==NULL)
    {
        printf("export::%s",strerror(errno));
        return;
    }
    else
    {
        int i=0;
        while(i<ps->size)
        {
            fwrite(&(ps->pp[i]),sizeof(data),1,tem);
            i++;
        }
        printf("\n导出通讯录成功\n\n");
        }
    fclose(tem);
    tem=NULL;
}

void import_contact(loca* ps)
{
    data tem={{0}};
    FILE* read=fopen("contact.data","rb");
    if(read==NULL)
    {
        printf("import::%s",strerror(errno));
        return;
    }
    else
    {
        while(fread(&tem,sizeof(data),1,read))
        {
            check_capacity(ps);
            ps->pp[ps->size]=tem;
            ps->size++;
        }
        printf("\n导入通讯录成功\n\n");
        }
    fclose(read);
    read=NULL;
}
