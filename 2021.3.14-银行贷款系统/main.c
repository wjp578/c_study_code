#include <stdio.h>
#include <math.h>
#include <string.h>


typedef struct//日期：年 月 日
{
	int year;
	int month;
	int day;
}Date;


typedef struct//贷款
{
	/*需要输入的*/
	Date time;//贷款时间
	double interest;//贷款利息
	int circle;//贷款期数
	double money;//贷款金额

	/*根据信息求得 */
	Date endTime;//贷款到期日
	int returnCircle;//已还期数
	double rPrincipal;//每月还款本金
	double rInterest;//每月还款利息

	double rMoney;//每月还款数额  =还款本金加还款利息
	double residueMoney;//贷款本金余额

}Loan;

typedef struct//还款
{
	Date time;//还款时间
	double rPrincipal;//还款本金
	double rInterest; //还款利息

	double residueMoney;//贷款本金余额
}Payment;


typedef struct//用户
{
	char name[100];//姓名
	char account[100];//账号

}People;


People people;//创建一个贷款人
Loan loan;//创建一个贷款

Payment payRecord[100];//还款记录
int recordNum=0;

Payment needPay[100];//待还款
int needNum=0;


//个人信息录入
void getPeople()
{
	strcpy(people.name,"测试人");
	strcpy(people.account,"123456789");

	return ;
}

//贷款信息录入
void getLoan()
{
	Date d;
	double monthInterest;
	printf("请输入贷款日期：（按:年 月 日 输入，中间用空格间隔）\n");
	scanf("%d %d %d",&d.year,&d.month,&d.day);
	loan.time=d;
	printf("请输入贷款年利率:\n");
	scanf(" %lf",&loan.interest);
	printf("请输入贷款期数:\n");
	scanf(" %d",&loan.circle);
	printf("请输入贷款金额:\n");
	scanf(" %lf",&loan.money);


	//初始化还款期数
	loan.returnCircle=0;

	//计算贷款到期日
	d.month+=loan.circle;
	while(d.month>12)
	{
		d.year++;
		d.month-=12;
	}
	loan.endTime=d;

	monthInterest=loan.interest/12/100;
	loan.rMoney=loan.money*monthInterest*pow(1+monthInterest,loan.circle)/(pow(1+monthInterest,loan.circle)-1);//等额本息计算公式

	//loan.rPrincipal=loan.money/loan.circle;//每月应还本金=总借款数/期数
	//loan.rInterest=loan.money*(loan.interest/100/12);//每月应还利息=总借款数*(年利息/12);

	loan.residueMoney=loan.money;//最开始   剩余金额=借款金额
	return ;
}


//打印头部信息 姓名 贷款日期等
void printMessage()
{
	Date time;
	printf("姓名：%s\t",people.name);
	printf("贷款金额：%.2lf\t",loan.money);
	printf("贷款利率：%.2lf\n",loan.interest);

	time=loan.time;
	printf("贷款起始日：%d-%d-%d\t",time.year,time.month,time.day);
	time=loan.endTime;
	printf("贷款到期日：%d-%d-%d\n",time.year,time.month,time.day);
	return;
}
/*
void updateNeedPay()//更新待还信息
{
	int i,j,n;//i循环变量  n剩余还款期数
	Payment payment;//还款变量
	double dayInterest,money;

	needNum=0;
	//未还期数
	n=loan.circle-loan.returnCircle;
	//计算当前日期
	payment.time=loan.time;
	payment.time.month+=loan.returnCircle;
	while(payment.time.month>12)
	{
		payment.time.year++;
		payment.time.month-=12;
	}
	//计算每期利息本金
	payment.rPrincipal=loan.money/loan.circle;//每次还款本金=借款金额/借款期数

	//printMessage();
	for(i=0;i<n;i++)
	{
		//计算每期利息
		money=loan.money*(n-i)/loan.circle;//money 有效计算利息钱数
		payment.rInterest=0;//本期利息

		for(j=0;j<30;j++)//30天的日利息累加 得到本期利息
		{
			dayInterest=money*loan.interest/360/100;//每天有效钱数*日利率
			money+=dayInterest;//
			payment.rInterest+=dayInterest;//
			//printf("%.2lf %.2lf %.2lf ",loan.interest/360/100,dayInterest,rInterest);
		}

		//贷款本金剩余
		payment.residueMoney= loan.money*(n-i-1)/loan.circle;

		needPay[needNum++]=payment;


		payment.time.month++;
		while(payment.time.month>12)
		{
			payment.time.year++;
			payment.time.month-=12;
		}
	}
	return;
}
*/


//等额本息  每月还款数一定 本金和利息不固定
void updateNeedPay()//更新待还信息
{
	int i,j,n;//i循环变量  n剩余还款期数
	Payment payment;//临时还款变量

	needNum=0;//待还款数组初始化
	//未还期数
	n=loan.circle-loan.returnCircle;
	//计算当前日期
	payment.time=loan.time;
	payment.time.month+=loan.returnCircle;
	while(payment.time.month>12)
	{
		payment.time.year++;
		payment.time.month-=12;
	}

	payment.residueMoney=loan.residueMoney;
	//printf("%d",payment.residueMoney);
	//printMessage();
	for(i=0;i<n;i++)
	{
		//计算每期利息
		payment.rInterest=payment.residueMoney*(loan.interest/12/100); //剩余本金 *月利率

		//计算每期本金
		payment.rPrincipal=loan.rMoney-payment.rInterest;//每期本金=每月还款额-利息

		//贷款本金剩余
		payment.residueMoney=payment.residueMoney-payment.rPrincipal;//更新本金

		needPay[needNum++]=payment;


		payment.time.month++;
		while(payment.time.month>12)
		{
			payment.time.year++;
			payment.time.month-=12;
		}
	}
	return ;
}

void recordPayment()//已还款记录查询
{
	int i;
	printf("----还款明细 查询----\n");
	printMessage();
	for(i=0;i<recordNum;i++)
	{
		printf("日期：%d-%d\t",payRecord[i].time.year,payRecord[i].time.month);
		printf("本金发生额：%.2lf\t",payRecord[i].rPrincipal);
		printf("利息发生额：%.2lf\t",payRecord[i].rInterest);
		printf("贷款本金余额：%.2lf\n",payRecord[i].residueMoney);
	}
	return;
}


void queryLoan()//还款计划查询
{
	int i;
	printf("----还款计划 查询----\n");
	printMessage();
	for(i=0;i<needNum;i++)
	{
		printf("贷款账号：%s\t",people.account);
		printf("还款月：%d-%d\t",needPay[i].time.year,needPay[i].time.month);
		printf("应还本金：%.2lf\t",needPay[i].rPrincipal);
		printf("应还利息：%.2lf\n",needPay[i].rInterest);
	}

	return;
}

void prePayMoney()//提前还款
{
	int order;


	printf("姓名：%s\t",people.name);
	printf("贷款账号：%s\t",people.account);
	printf("贷款余额：%.2lf\n",loan.residueMoney);
	printf("还款方式：（等额本息）\n");


	printf("选择提前还款方式：\n");
	printf("1.缩短贷款期限\n");
	printf("2.减少月还款额\n");
	scanf("%d",&order);
	if(order==1)
	{
		int n;
		double monthInterest;
		printf("输入要缩短的期数：\n");
		scanf("%d",&n);
		printf("本次还款合计：%.2lf\n",loan.rMoney*n);

		//更新变量
		loan.residueMoney=loan.residueMoney-(loan.rMoney)*n;
		loan.circle=loan.circle-n;

		//重新计算
		monthInterest=loan.interest/12/100;
		loan.rMoney=loan.residueMoney *monthInterest*pow(1+monthInterest,loan.circle)/(pow(1+monthInterest,loan.circle)-1);//等额本息计算公式
	}
	else if(order==2)
	{
		double r;
		double monthInterest;
		printf("输入减少月还款额：\n");
		scanf("%lf",&r);
		printf("本次还款合计：%.2lf\n",r*loan.circle);

		loan.residueMoney=loan.residueMoney-r*loan.circle;//更新剩余贷款
		monthInterest=loan.interest/12/100;
		loan.rMoney=loan.residueMoney *monthInterest*pow(1+monthInterest,loan.circle)/(pow(1+monthInterest,loan.circle)-1);//等额本息计算公式

	}
	printf("还款后:\n");
	printf("剩余贷款余额：%.2lf\t",loan.residueMoney);
	printf("剩余贷款期数：%d\t",loan.circle);
	printf("剩余贷款每月还款金额：%.2lf\n",loan.rMoney);
	return;
}

void payMoney()//还款
{
	payRecord[recordNum++]=needPay[0];
	loan.returnCircle++;
	printf("----还款操作----\n");
	printf("%d-%d 还款成功\n",needPay[0].time.year,needPay[0].time.month);
	return;
}

int main()//主函数
{
	int order;
	getPeople();
	getLoan();
	//printMessage();
	//printf("贷款信息：日期:%d-%d-%d 年利率:%.2lf 期数:%d 金额:%d\n",loan.time.year,loan.time.month,loan.time.day,loan.interest,loan.circle,loan.money);

	while(1)
	{
		//system("CLS");
		printf("\n#################\n");
		printf("请输入指令:\t\n");
		printf("1.按月还款\t\t\n");
		printf("2.已还款查询\t\n");
		printf("3.还款计划查询\t\n");
		printf("4.提前还款\t\n");
		printf("0.退出系统\t\n");
		printf("#################\n");
		scanf("%d",&order);
		printf("\n");
		updateNeedPay();
		if(order==0)
		{
			return 0;
		}
		else if(order==1)
		{
			updateNeedPay();
			payMoney();
			updateNeedPay();
		}
		else if(order==2)
		{
			recordPayment();
		}
		else if(order==3)
		{
			//updateNeedPay();
			queryLoan();
		}
		else if(order==4)
		{
			//updateNeedPay();
			prePayMoney();
			//updateNeedPay();
		}
		else
		{
			printf("输入指令有误，重新输入。");
		}
		updateNeedPay();
	}

	//queryLoan();
	return 0;
}
