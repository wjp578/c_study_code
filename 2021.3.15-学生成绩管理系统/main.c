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



int shuru(Student stud[],int n)/*输入若干条记录*/
{
	int i=0;
	char sign,x[10];
	double s=0.0;
	sign='y';
    while(sign!='n'&&sign!='N')
    {
        printf("输入学生学号:");
        scanf("%s",&stu[n+i].stuno);
        printf("输入学生姓名:");
        scanf("%s",&stu[n+i].name);
        printf("输入学生年龄:");
        scanf("%d",&stu[n+i].age);
        printf("输入学生的数学、英语、物理分数:");
        scanf("%d%d%d",&stu[n+i].math,&stu[n+i].english,&stu[n+i].physics);
        s=stu[n+i].math+stu[n+i].english+stu[n+i].physics;
        stu[n+i].sum=s;
        gets(x);   /*清除多余的输入*/
        printf("是否继续输入?(Y/N):\n");
        scanf("%c",&sign);
        i++;
    }
return(n+i);
}


void xianshi(Student stud[],int n) /*显示所有记录*/
{
  int i ;
  printf("-----------------------------------------------------------------\n"); /*格式头*/
  printf("学号    姓名       年龄       数学      英语     物理     总成绩 \n");
  printf("-----------------------------------------------------------------\n");
  for(i=0;i<n;i++)
  {
    printf("%-10s%-10s%-10d%-10d%-10d%-10d%-10.2lf\n",stu[i].stuno,stu[i].name,stu[i].age,stu[i].math,stu[i].english,stu[i].physics,stu[i].sum);
  }
}


void xiugai(Student stud[],int n)/*修改*/
{
 int i=0,choice=1;
 char x[10];
    while(choice!=0)
    {
        printf("请输入您要修改的学生的学号:\n");
        scanf("%s",x);
		for(i=0;;i++)
		{
			if(strcmp(stu[i].stuno,x)==0)  break;

		}
        printf("请选择您要修改的内容：\n");
        printf(" ---------------------- \n");
		printf("| 姓名              请按 1 |\n");
		printf("| 年龄              请按 2 |\n");
		printf("| 数学              请按 3 |\n");
		printf("| 英语              请按 4 |\n");
     	printf("| 物理              请按 5 |\n");
		printf("| 退出              请按 0|\n");
        printf("+----------------------+\n");
        printf("请输入您的选择：");
        scanf("%d", &choice);
        switch(choice)
        {
            case 0:break;
            case 1:
                printf("请输入新的姓名：");
                scanf("%s", stu[i].name);
                break;
            case 2:
                printf("请输入新的年龄：");
               scanf("%d", &stu[i].age);
                break;
			case 3:
                printf("请输入新的数学分数：");
               scanf("%d",&stu[i].math);
                break;
			case 4:
                printf("请输入新的英语分数：");
               scanf("%d", &stu[i].english);
                break;
            case 5:
                printf("请输入新的物理分数：");
               scanf("%d", &stu[i].physics);
                break;
            default:
                printf("\n无效选项!");
                break;
		} break;

       }

	return;
}
int shanchu(Student stud[],int n) /*按姓名查找，删除一条记录*/
{
    char s[20];
    int i;
    int j;
    i=0;
    printf("输入要删除记录的姓名:");
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
    for(j=i;j<n-1;j++) /*删除操作*/
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


void paixu(Student stud[],int n) /*按学号排序*/
{
    int i,j,p,q,r,w;
    double y;
    char x[20],t[10];
    for(i=0;i<n-1;i++) /*冒泡法排序*/
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


int wenjian2(Student stud[],int n) /*从文件中读入数据*/
{
    int i=0,num;
    FILE *fp; /*定义文件指针*/
    char filename[20]; /*定义文件名*/
    printf("\t\t\tInput the filename:");
    scanf("\t\t\t%s",filename); /*输入文件名*/
    if((fp=fopen(filename,"rb"))==NULL) /*打开文件*/
    {
        printf("\t\t\tcann't open the file\n"); /*打开失败信息*/
        printf("\t\t\t");
        system("pause");
        return(n);
    }

    fscanf(fp,"%d",&num); /*读入总记录量*/
    while(i<num) /*循环读入数据*/
    {
        fscanf(fp,"%s%s%d%d%d%d%lf\n",stu[n+i].stuno,stu[n+i].name,&stu[n+i].age,&stu[n+i].math,&stu[n+i].english,&stu[n+i].physics,&stu[n+i].sum);
        i++;
    }
    n+=num;
    fclose(fp); /*关闭文件*/
    printf("\t\t\tSuccessed!\n");
    printf("\t\t\t");
    system("pause");
    return(n);
}



void wenjian1(Student stud[],int n)               /*将所有记录写入文件*/
{
    int i=0;
    FILE *fp;                     /*定义文件指针*/
    char filename[20];                    /*定义文件名*/
    printf("Input the filename:");/*输入文件名*/
    scanf("%s",filename);
    if((fp=fopen(filename,"w"))==NULL)             /*打开文件*/
        {
             printf("cann't open the file\n");
             return;
        }
    fprintf(fp,"%d\n",n);             /*循环写入数据*/
    while(i<n)
        {
            fprintf(fp,"%s%s%d%d%d%d%lf\n",stu[i].stuno,stu[i].name,stu[i].age,stu[i].math,stu[i].english,stu[i].physics,&stu[n+i].sum);
            i++;
        }
       fclose(fp);           /*关闭文件*/
       printf("Successed!\n");          /*返回成功信息*/
}




int menu()          /*菜单函数*/
{
    int c;
    do
    {
        printf("\t\t****学生信息管理系统菜单****\n");
        printf("\t\t  1. 编辑 \n");
        printf("\t\t  2. 显示 \n");
        printf("\t\t  3. 排序\n");
        printf("\t\t  4. 文件 \n");
        printf("\t\t  0. 退出 \n");
        printf("************************************************************\n");
        printf("\t\t\t请选择(0-4):");
        scanf("%d",&c);
    }while(c<0||c>4);
    return(c-0); /*返回选择*/

}


int bianji()
{
     printf("\t\t 1. 录入\n");
     printf("\t\t 2 .修改\n");
     printf("\t\t 3. 删除 \n");
     printf("\t\t 按其它数字键退出 \n");
    int i;
    scanf("%d",&i);
    return i;
}


int wenjian()
{
     printf("\t\t 1. 从文件中读入数据\n");
     printf("\t\t 2 .将所有记录写入文件\n");
     printf("\t\t   按其它数字键退出 \n");

    int i;
    scanf("%d",&i);
    return i;
}



int main()    /*主函数*/
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
                    exit(0);   /*结束程序*/
            }
         }
     }

}

