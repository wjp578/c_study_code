#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char stuno[10];
    char name[20];
    int age;
    int math;
    int english;
	int physics;
	double sum;
}Student;
Student stu[99];



int shuru(Student stud[],int n)/*������������¼*/
{
	int i=0;
	char sign,x[10];
	double s=0.0;
	sign='y';
    while(sign!='n'&&sign!='N')
    {
        printf("����ѧ��ѧ��:");
        scanf("%s",&stu[n+i].stuno);
        printf("����ѧ������:");
        scanf("%s",&stu[n+i].name);
        printf("����ѧ������:");
        scanf("%d",&stu[n+i].age);
        printf("����ѧ������ѧ��Ӣ��������:");
        scanf("%d%d%d",&stu[n+i].math,&stu[n+i].english,&stu[n+i].physics);
        s=stu[n+i].math+stu[n+i].english+stu[n+i].physics;
        stu[n+i].sum=s;
        gets(x);   /*������������*/
        printf("�Ƿ��������?(Y/N):\n");
        scanf("%c",&sign);
        i++;
    }
return(n+i);
}


void xianshi(Student stud[],int n) /*��ʾ���м�¼*/
{
  int i ;
  printf("-----------------------------------------------------------------\n"); /*��ʽͷ*/
  printf("ѧ��    ����       ����       ��ѧ      Ӣ��     ����     �ܳɼ� \n");
  printf("-----------------------------------------------------------------\n");
  for(i=0;i<n;i++)
  {
    printf("%-10s%-10s%-10d%-10d%-10d%-10d%-10.2lf\n",stu[i].stuno,stu[i].name,stu[i].age,stu[i].math,stu[i].english,stu[i].physics,stu[i].sum);
  }
}


void xiugai(Student stud[],int n)/*�޸�*/
{
 int i=0,choice=1;
 char x[10];
    while(choice!=0)
    {
        printf("��������Ҫ�޸ĵ�ѧ����ѧ��:\n");
        scanf("%s",x);
		for(i=0;;i++)
		{
			if(strcmp(stu[i].stuno,x)==0)  break;

		}
        printf("��ѡ����Ҫ�޸ĵ����ݣ�\n");
        printf(" ---------------------- \n");
		printf("| ����              �밴 1 |\n");
		printf("| ����              �밴 2 |\n");
		printf("| ��ѧ              �밴 3 |\n");
		printf("| Ӣ��              �밴 4 |\n");
     	printf("| ����              �밴 5 |\n");
		printf("| �˳�              �밴 0|\n");
        printf("+----------------------+\n");
        printf("����������ѡ��");
        scanf("%d", &choice);
        switch(choice)
        {
            case 0:break;
            case 1:
                printf("�������µ�������");
                scanf("%s", stu[i].name);
                break;
            case 2:
                printf("�������µ����䣺");
               scanf("%d", &stu[i].age);
                break;
			case 3:
                printf("�������µ���ѧ������");
               scanf("%d",&stu[i].math);
                break;
			case 4:
                printf("�������µ�Ӣ�������");
               scanf("%d", &stu[i].english);
                break;
            case 5:
                printf("�������µ����������");
               scanf("%d", &stu[i].physics);
                break;
            default:
                printf("\n��Чѡ��!");
                break;
		} break;

       }

	return;
}
int shanchu(Student stud[],int n) /*���������ң�ɾ��һ����¼*/
{
    char s[20];
    int i;
    int j;
    i=0;
    printf("����Ҫɾ����¼������:");
    scanf("%s",s);
    while(strcmp(stu[i].name,s)!=0&&i<n)
    {
        i++;
    }
    if(i==n)
    {
        printf("not find!\n");
        return(n);
    }
    for(j=i;j<n-1;j++) /*ɾ������*/
    {
        strcpy(stu[j].stuno,stu[j+1].stuno);
        strcpy(stu[j].name,stu[j+1].name);
        stu[j].age=stu[j+1].age;
        stu[j].math=stu[j+1].math;
        stu[j].english=stu[j+1].english;
        stu[j].physics=stu[j+1].physics;
        stu[j].sum=stu[j+1].sum;
    }
    printf("Delete Successed!\n");
    return(n-1);
}


void paixu(Student stud[],int n) /*��ѧ������*/
{
    int i,j,p,q,r,w;
    double y;
    char x[20],t[10];
    for(i=0;i<n-1;i++) /*ð�ݷ�����*/
    for(j=0;j<n-1-i;j++)
    {
        if(strcmp(stud[j].stuno,stud[j+1].stuno)>0)
        { strcpy(t,stud[j].stuno);
              strcpy(stud[j].stuno,stud[j+1].stuno);
              strcpy(stud[j+1].stuno,t);
              strcpy(x,stud[j].name);
              strcpy(stud[j].name,stud[j+1].name);
              strcpy(stud[j+1].name,x);
              p=stu[j].age;stu[j].age=stu[j+1].age;stu[j+1].age=p;
              q=stu[j].math;stu[j].math=stu[j+1].math;stu[j+1].math=q;
              r=stu[j].english;stu[j].english=stu[j+1].english;stu[j+1].english=r;
              w=stu[j].physics;stu[j].physics=stu[j+1].physics;stu[j+1].physics=w;
        }
    }

return;
}


int wenjian2(Student stud[],int n) /*���ļ��ж�������*/
{
    int i=0,num;
    FILE *fp; /*�����ļ�ָ��*/
    char filename[20]; /*�����ļ���*/
    printf("\t\t\tInput the filename:");
    scanf("\t\t\t%s",filename); /*�����ļ���*/
    if((fp=fopen(filename,"rb"))==NULL) /*���ļ�*/
    {
        printf("\t\t\tcann't open the file\n"); /*��ʧ����Ϣ*/
        printf("\t\t\t");
        system("pause");
        return(n);
    }

    fscanf(fp,"%d",&num); /*�����ܼ�¼��*/
    while(i<num) /*ѭ����������*/
    {
        fscanf(fp,"%s%s%d%d%d%d%lf\n",stu[n+i].stuno,stu[n+i].name,&stu[n+i].age,&stu[n+i].math,&stu[n+i].english,&stu[n+i].physics,&stu[n+i].sum);
        i++;
    }
    n+=num;
    fclose(fp); /*�ر��ļ�*/
    printf("\t\t\tSuccessed!\n");
    printf("\t\t\t");
    system("pause");
    return(n);
}



void wenjian1(Student stud[],int n)               /*�����м�¼д���ļ�*/
{
    int i=0;
    FILE *fp;                     /*�����ļ�ָ��*/
    char filename[20];                    /*�����ļ���*/
    printf("Input the filename:");/*�����ļ���*/
    scanf("%s",filename);
    if((fp=fopen(filename,"w"))==NULL)             /*���ļ�*/
        {
             printf("cann't open the file\n");
             return;
        }
    fprintf(fp,"%d\n",n);             /*ѭ��д������*/
    while(i<n)
        {
            fprintf(fp,"%s%s%d%d%d%d%lf\n",stu[i].stuno,stu[i].name,stu[i].age,stu[i].math,stu[i].english,stu[i].physics,&stu[n+i].sum);
            i++;
        }
       fclose(fp);           /*�ر��ļ�*/
       printf("Successed!\n");          /*���سɹ���Ϣ*/
}




int menu()          /*�˵�����*/
{
    int c;
    do
    {
        printf("\t\t****ѧ����Ϣ����ϵͳ�˵�****\n");
        printf("\t\t  1. �༭ \n");
        printf("\t\t  2. ��ʾ \n");
        printf("\t\t  3. ����\n");
        printf("\t\t  4. �ļ� \n");
        printf("\t\t  0. �˳� \n");
        printf("************************************************************\n");
        printf("\t\t\t��ѡ��(0-4):");
        scanf("%d",&c);
    }while(c<0||c>4);
    return(c-0); /*����ѡ��*/

}


int bianji()
{
     printf("\t\t 1. ¼��\n");
     printf("\t\t 2 .�޸�\n");
     printf("\t\t 3. ɾ�� \n");
     printf("\t\t ���������ּ��˳� \n");
    int i;
    scanf("%d",&i);
    return i;
}


int wenjian()
{
     printf("\t\t 1. ���ļ��ж�������\n");
     printf("\t\t 2 .�����м�¼д���ļ�\n");
     printf("\t\t   ���������ּ��˳� \n");

    int i;
    scanf("%d",&i);
    return i;
}



int main()    /*������*/
{
    int n=0;
    for(;;)
    {
        for(;;)
        {
            switch(menu())
            {
                case 1:  switch(bianji())
                    {
                        case 1:n=shuru(stu,n);xianshi(stu,n); break;
                        case 2:xiugai(stu ,n);xianshi(stu,n); break;
                        case 3:shanchu(stu ,n);xianshi(stu,n); break;
                    } break;
                case 2:xianshi(stu,n);break;
                case 3:paixu(stu,n);break;
                case 4:
                    switch(wenjian())
                        {
                            case 1:n=wenjian2(stu,n);break;
                            case 2:wenjian1(stu ,n);break;
                        } break;

                case 0:
                    exit(0);   /*��������*/
            }
         }
     }

}

