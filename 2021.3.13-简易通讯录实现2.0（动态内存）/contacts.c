#include "contact.h"

void check_capacity(loca* ps)
{
    if(ps->capacity==ps->size)
    {
        data* ptr=(data*)realloc(ps->pp,(ps->capacity+ADD_CAPACITY)*sizeof(data));
        if(ptr==NULL)
        {
            printf("����ʧ��\n");//�������Ч��
        }
        else
        {
            ps->pp=ptr;
            ps->capacity+=ADD_CAPACITY;
            printf("���ݳɹ�\n");//�������Ч��
        }
    }
}

void destory_contact(loca* ps)
{
    free(ps);
    ps=NULL;
}

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
        printf("\nͨѶ¼Ϊ�գ��������ϵ��\n\n");
    else
    {
        int i=1;
        printf("\n%s\t%s\t%-13s\t%s\t%s\n","���","����","�绰","����","�Ա�");
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
        check_capacity(ps);


        printf("\n������������");
        scanf("%s",ps->pp[ps->size].name);

        //����Ƿ�����
        if(check_positioning(ps,ps->pp[ps->size].name)!=0)
        {
            printf("�Ѵ��ڸ���ϵ��\n\n");
            return;
        }

        printf("������绰��");
        scanf("%s",ps->pp[ps->size].tel);
        printf("���������䣺");
        scanf("%d",&(ps->pp[ps->size].age));
        printf("�������Ա�");
        scanf("%s",ps->pp[ps->size].sex);

        printf("��ӳɹ���\n");
        printf("\n");

        ps->size++;
}

void dele_contact(loca* ps)
{
        int s=0;
        char name_d[MAX_NAME];

        printf("������Ҫɾ����ϵ�˵�����:");
                scanf("%s",name_d);

        int i=check_positioning(ps,name_d);

        if(0==i)
        {
            printf("�޴�����Ϣ\n\n");
            return;
        }
        else
        {
            int is=0;
            printf("ȷ��ɾ������ϵ���𣿣�ȷ��--1��ȡ��--2��\n");
            printf("�����룺");
            scanf("%d",&is);
            switch(is)
            {
                case 1:
                    for(s=i;s<ps->size;s++)
                    {
                            ps->pp[s]=ps->pp[s+1];
                    }
                    ps->size--;
                    printf("ɾ���ɹ���\n\n");
                    break;
                case 2:
                    break;
                default:
                    printf("�������\n");
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

    printf("������Ҫ�޸���ϵ�˵�����:");//(�ԡ�0Ϊ��β��)
    scanf("%s",name_m);

    int i=check_positioning(ps,name_m);

    if(0==i)
    {
        printf("�޴�����Ϣ\n\n");
        return;
    }
    else
    {
        int m=0;
        int n=0;
        do
        {
            int num=0;
            printf("��ѡ��Ҫ�޸ĵ���Ŀ(1��������2���绰��3�����䣻4���Ա�):");
            scanf("%d",&m);
            switch(m)
            {
                case 1:
                    printf("�������޸�Ϊ��");
                    scanf("%s",newname);
                    for(num=0;num<MAX_NAME;num++)
                    {
                        ps->pp[i].name[num]=newname[num];
                    }
                    printf("�޸ĳɹ�\n");
                    printf("��ѡ���Ƿ�����޸ģ�1���ǣ�0���񣩣�");
                    scanf("%d",&n);
                    break;

                case 2:
                    printf("�绰���޸�Ϊ��");
                    scanf("%s",newtel);
                    for(num=0;num<MAX_TEL;num++)
                    {
                        ps->pp[i].tel[num]=newtel[num];
                    }
                    printf("�޸ĳɹ�\n");
                    printf("��ѡ���Ƿ�����޸ģ�1���ǣ�0���񣩣�");
                    scanf("%d",&n);
                    break;

                case 3:
                    printf("���佫�޸�Ϊ��");
                    scanf("%d",&newage);
                    ps->pp[i].age=newage;
                    printf("�޸ĳɹ�\n");
                    printf("��ѡ���Ƿ�����޸ģ�1���ǣ�0���񣩣�");
                    scanf("%d",&n);
                    break;

                case 4:
                    printf("�Ա��޸�Ϊ��");
                    scanf("%s",newsex);
                    for(num=0;num<MAX_SEX;num++)
                    {
                        ps->pp[i].sex[num]=newsex[num];
                    }
                    printf("�޸ĳɹ�\n");
                    printf("��ѡ���Ƿ�����޸ģ�1���ǣ�0���񣩣�");
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
    printf("������Ҫ������ϵ�˵�����:");//(�ԡ�0Ϊ��β��)
    scanf("%s",name_s);

    int i=check_positioning(ps,name_s);

    if(0==i)
    {
        printf("�޴�����Ϣ\n\n");
        return;
    }
    else
    {
        printf("������%s\t�绰��%-13s\t���䣺%d\t�Ա�%s\n",
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
            return 0;//����0��ƥ��ʧ�ܣ��˳��ϼ�����
        }

    return i;//���ط�0��ƥ��ɹ��������±�i

//�޸�

//        int i=0;
//
//        while(i<ps->size)
//        {
//            if(0==strcmp(ps->pp[i].name,name_check))
//            {
//                return i;//����i,ƥ��ɹ��������±�
//            }
//            i++;
//        }
//        return -1;//����-1��ƥ��ʧ��
}
