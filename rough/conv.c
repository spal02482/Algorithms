#include<stdio.h>
int bin2dec(int);
int dec2bin(int);
int oct2dec(int);
int dec2oct(int);
int main()
{
char w='y';
int b,c,d,e,f;
while(w!='n')
{
	while(1)
	{
	printf("\n\nWELCOME TO CONVERSION SYSTEM\n\n");
	printf("Enter your first number system\n");
	printf("1.Binary\n2.Decimal\n3.Octal\n");
	scanf("%d",&b);
	printf("Enter your second number system\n");
	printf("1.Binary\n2.Decimal\n3.Octal\n");
	scanf("%d",&c);
	if(b==c)	
	{
	printf("CONVERSION NOT POSIIBLE DUE TO\n SAME NUMBER SYSTEM\n");
	break;
	}
	printf("ENTER THE NUMBER YOU WANT TO CONVERT\n");
	scanf("%d",&d);
	if(b==1&&c==2)
	{
		e=bin2dec(d);
		if(e==986)
		break;
		printf("THE CONVERTED VALUE IS %d\n",e);
		break;
	}
	else if (b==1&&c==3)
	{
		e=bin2dec(d);
		if(e==986)
		break;
		f=dec2oct(e);
		printf("THE CONVERTED VALUE IS %d\n",f);
		break;
	}
	else if(b==2&&c==1)
	{
		e=dec2bin(d);
		printf("THE CONVERTED VALUE IS %d\n",e);
		break;
	}
	else if(b==2&&c==3)
	{
		e=dec2oct(d);
		printf("THE CONVERTED VALUE IS %d\n",e);
		break;
	}
	else if(b==3&&c==1)
	{
		e=oct2dec(d);
		if(e==986)
		break;
		f=dec2bin(e);
		printf("THE CONVERTED VALUE IS %d\n",f);
		break;
	}
	else if(b==3&&c==2)
	{
		e=oct2dec(d);
		if(e==986)
		break;
		printf("THE CONVERTED VALUE IS %d\n",e);
		break;
	}
	}
printf("DO YOU WANT TO CONTINUE(y/n)\n");
scanf(" %c",&w);
}
return 0;
}
int bin2dec(int a)
{
	int i=1,sum=0,b;
	while(a!=0)
	{
		b=a%10;
		if(b!=0&&b!=1)
		{
		printf("Not A Binary Number\n");
		return 986;
		}
		a=a/10;
		sum=sum+i*b;
		i=i*2;
	}
	return sum;
}

int dec2bin(int a)
{
	int i=1,sum=0,b;
	while(a!=0)
	{
		b=a%2;
		a=a/2;
		sum=sum+i*b;
		i=i*10;
	}
	return sum;
}
int dec2oct(int a)
{
	int i=1,sum=0,b;
	while(a!=0)
	{
		b=a%8;
		a=a/8;
		sum=sum+i*b;
		i=i*10;
	}
	return sum;
}
int oct2dec(int a)
{
	int i=1,sum=0,b;
	while(a!=0)
	{
		b=a%10;
		if(b==8||b==9)
		{
		printf("Not An Octal Number\n");
		return 986;
		}
		a=a/10;
		sum=sum+i*b;
		i=i*8;
	}
	return sum;
}
