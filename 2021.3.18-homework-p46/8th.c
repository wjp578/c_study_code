//打印菱形

#include "homework.h"

void PrintTheDiamond()
{
    int n=0;
    printf("请输入打印宽度（中间行长度）：");
    scanf("%d",&n);

	int a,b,c;
	for(a=1;a<=n;a++)
	{
	    int x=abs(a-(n/2+1));
	    int y=n-2*abs(a-(n/2+1));

		for(b=1;b<=abs(a-(n/2+1));b++)
		{
			printf(" ");
		}
		for (c=1;c<=n-2*abs(a-(n/2+1));c++)
		{
			printf("*");
		}
		printf("\n");
	}
}
