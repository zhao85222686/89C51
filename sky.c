#include <reg52.h>

sbit S2 = P3^0;
sbit S3 = P3^1;
sbit S4 = P3^2;
sbit S5 = P3^3;

sbit  LED1 = P1^0;
sbit  LED2 = P1^1;
sbit  LED3 = P1^2;
sbit  LED4 = P1^3;

void  main()
{
	while (1)
	{
	 	if(S2==0)
		LED1=0;
		else
		LED1=1;

	 	if(S3==0)
		LED2=0;
		else
		LED2=1;

	 	if(S4==0)
		LED3=0;
		else
		LED3=1;

	 	if(S5==0)
		LED4=0;
		else
		LED4=1;
	}	
}
