#include <stdio.h>
#include <math.h>
#include <string.h>


typedef struct//���ڣ��� �� ��
{
	int year;
	int month;
	int day;
}Date;


typedef struct//����
{
	/*��Ҫ�����*/
	Date time;//����ʱ��
	double interest;//������Ϣ
	int circle;//��������
	double money;//������

	/*������Ϣ��� */
	Date endTime;//�������
	int returnCircle;//�ѻ�����
	double rPrincipal;//ÿ�»����
	double rInterest;//ÿ�»�����Ϣ

	double rMoney;//ÿ�»�������  =�����ӻ�����Ϣ
	double residueMoney;//��������

}Loan;

typedef struct//����
{
	Date time;//����ʱ��
	double rPrincipal;//�����
	double rInterest; //������Ϣ

	double residueMoney;//��������
}Payment;


typedef struct//�û�
{
	char name[100];//����
	char account[100];//�˺�

}People;


People people;//����һ��������
Loan loan;//����һ������

Payment payRecord[100];//�����¼
int recordNum=0;

Payment needPay[100];//������
int needNum=0;


//������Ϣ¼��
void getPeople()
{
	strcpy(people.name,"������");
	strcpy(people.account,"123456789");

	return ;
}

//������Ϣ¼��
void getLoan()
{
	Date d;
	double monthInterest;
	printf("������������ڣ�����:�� �� �� ���룬�м��ÿո�����\n");
	scanf("%d %d %d",&d.year,&d.month,&d.day);
	loan.time=d;
	printf("���������������:\n");
	scanf(" %lf",&loan.interest);
	printf("�������������:\n");
	scanf(" %d",&loan.circle);
	printf("�����������:\n");
	scanf(" %lf",&loan.money);


	//��ʼ����������
	loan.returnCircle=0;

	//����������
	d.month+=loan.circle;
	while(d.month>12)
	{
		d.year++;
		d.month-=12;
	}
	loan.endTime=d;

	monthInterest=loan.interest/12/100;
	loan.rMoney=loan.money*monthInterest*pow(1+monthInterest,loan.circle)/(pow(1+monthInterest,loan.circle)-1);//�ȶϢ���㹫ʽ

	//loan.rPrincipal=loan.money/loan.circle;//ÿ��Ӧ������=�ܽ����/����
	//loan.rInterest=loan.money*(loan.interest/100/12);//ÿ��Ӧ����Ϣ=�ܽ����*(����Ϣ/12);

	loan.residueMoney=loan.money;//�ʼ   ʣ����=�����
	return ;
}


//��ӡͷ����Ϣ ���� �������ڵ�
void printMessage()
{
	Date time;
	printf("������%s\t",people.name);
	printf("�����%.2lf\t",loan.money);
	printf("�������ʣ�%.2lf\n",loan.interest);

	time=loan.time;
	printf("������ʼ�գ�%d-%d-%d\t",time.year,time.month,time.day);
	time=loan.endTime;
	printf("������գ�%d-%d-%d\n",time.year,time.month,time.day);
	return;
}
/*
void updateNeedPay()//���´�����Ϣ
{
	int i,j,n;//iѭ������  nʣ�໹������
	Payment payment;//�������
	double dayInterest,money;

	needNum=0;
	//δ������
	n=loan.circle-loan.returnCircle;
	//���㵱ǰ����
	payment.time=loan.time;
	payment.time.month+=loan.returnCircle;
	while(payment.time.month>12)
	{
		payment.time.year++;
		payment.time.month-=12;
	}
	//����ÿ����Ϣ����
	payment.rPrincipal=loan.money/loan.circle;//ÿ�λ����=�����/�������

	//printMessage();
	for(i=0;i<n;i++)
	{
		//����ÿ����Ϣ
		money=loan.money*(n-i)/loan.circle;//money ��Ч������ϢǮ��
		payment.rInterest=0;//������Ϣ

		for(j=0;j<30;j++)//30�������Ϣ�ۼ� �õ�������Ϣ
		{
			dayInterest=money*loan.interest/360/100;//ÿ����ЧǮ��*������
			money+=dayInterest;//
			payment.rInterest+=dayInterest;//
			//printf("%.2lf %.2lf %.2lf ",loan.interest/360/100,dayInterest,rInterest);
		}

		//�����ʣ��
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


//�ȶϢ  ÿ�»�����һ�� �������Ϣ���̶�
void updateNeedPay()//���´�����Ϣ
{
	int i,j,n;//iѭ������  nʣ�໹������
	Payment payment;//��ʱ�������

	needNum=0;//�����������ʼ��
	//δ������
	n=loan.circle-loan.returnCircle;
	//���㵱ǰ����
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
		//����ÿ����Ϣ
		payment.rInterest=payment.residueMoney*(loan.interest/12/100); //ʣ�౾�� *������

		//����ÿ�ڱ���
		payment.rPrincipal=loan.rMoney-payment.rInterest;//ÿ�ڱ���=ÿ�»����-��Ϣ

		//�����ʣ��
		payment.residueMoney=payment.residueMoney-payment.rPrincipal;//���±���

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

void recordPayment()//�ѻ����¼��ѯ
{
	int i;
	printf("----������ϸ ��ѯ----\n");
	printMessage();
	for(i=0;i<recordNum;i++)
	{
		printf("���ڣ�%d-%d\t",payRecord[i].time.year,payRecord[i].time.month);
		printf("�������%.2lf\t",payRecord[i].rPrincipal);
		printf("��Ϣ�����%.2lf\t",payRecord[i].rInterest);
		printf("�������%.2lf\n",payRecord[i].residueMoney);
	}
	return;
}


void queryLoan()//����ƻ���ѯ
{
	int i;
	printf("----����ƻ� ��ѯ----\n");
	printMessage();
	for(i=0;i<needNum;i++)
	{
		printf("�����˺ţ�%s\t",people.account);
		printf("�����£�%d-%d\t",needPay[i].time.year,needPay[i].time.month);
		printf("Ӧ������%.2lf\t",needPay[i].rPrincipal);
		printf("Ӧ����Ϣ��%.2lf\n",needPay[i].rInterest);
	}

	return;
}

void prePayMoney()//��ǰ����
{
	int order;


	printf("������%s\t",people.name);
	printf("�����˺ţ�%s\t",people.account);
	printf("������%.2lf\n",loan.residueMoney);
	printf("���ʽ�����ȶϢ��\n");


	printf("ѡ����ǰ���ʽ��\n");
	printf("1.���̴�������\n");
	printf("2.�����»����\n");
	scanf("%d",&order);
	if(order==1)
	{
		int n;
		double monthInterest;
		printf("����Ҫ���̵�������\n");
		scanf("%d",&n);
		printf("���λ���ϼƣ�%.2lf\n",loan.rMoney*n);

		//���±���
		loan.residueMoney=loan.residueMoney-(loan.rMoney)*n;
		loan.circle=loan.circle-n;

		//���¼���
		monthInterest=loan.interest/12/100;
		loan.rMoney=loan.residueMoney *monthInterest*pow(1+monthInterest,loan.circle)/(pow(1+monthInterest,loan.circle)-1);//�ȶϢ���㹫ʽ
	}
	else if(order==2)
	{
		double r;
		double monthInterest;
		printf("��������»���\n");
		scanf("%lf",&r);
		printf("���λ���ϼƣ�%.2lf\n",r*loan.circle);

		loan.residueMoney=loan.residueMoney-r*loan.circle;//����ʣ�����
		monthInterest=loan.interest/12/100;
		loan.rMoney=loan.residueMoney *monthInterest*pow(1+monthInterest,loan.circle)/(pow(1+monthInterest,loan.circle)-1);//�ȶϢ���㹫ʽ

	}
	printf("�����:\n");
	printf("ʣ�������%.2lf\t",loan.residueMoney);
	printf("ʣ�����������%d\t",loan.circle);
	printf("ʣ�����ÿ�»����%.2lf\n",loan.rMoney);
	return;
}

void payMoney()//����
{
	payRecord[recordNum++]=needPay[0];
	loan.returnCircle++;
	printf("----�������----\n");
	printf("%d-%d ����ɹ�\n",needPay[0].time.year,needPay[0].time.month);
	return;
}

int main()//������
{
	int order;
	getPeople();
	getLoan();
	//printMessage();
	//printf("������Ϣ������:%d-%d-%d ������:%.2lf ����:%d ���:%d\n",loan.time.year,loan.time.month,loan.time.day,loan.interest,loan.circle,loan.money);

	while(1)
	{
		//system("CLS");
		printf("\n#################\n");
		printf("������ָ��:\t\n");
		printf("1.���»���\t\t\n");
		printf("2.�ѻ����ѯ\t\n");
		printf("3.����ƻ���ѯ\t\n");
		printf("4.��ǰ����\t\n");
		printf("0.�˳�ϵͳ\t\n");
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
			printf("����ָ�������������롣");
		}
		updateNeedPay();
	}

	//queryLoan();
	return 0;
}
