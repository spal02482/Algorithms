#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 30
struct s
{
	int list[30];
	int top;
};
void push(struct s *p,char w)
{
	if(p->top==SIZE-1)
	{
		printf("Stack Overflow\n");
		exit(1);
	}
	p->top++;
	p->list[p->top]=w;
	return;
	
}
void pop(struct s *p)
{
	p->top--;
}

int main()
{
	struct s z;
	z.top=0;
	int i,a,x,flag=0,p=0,q=0;
	char str[30];
	printf("Enter An Expression\n");
	gets(str);
	x=strlen(str);
	for(i=0;i<x;i++)
	{
		if(str[i]=='(')
			{
				push(&z,str[i]);
				p++;
			}
		else if(str[i]==')')
			{
				pop(&z);
				q++;
			}
			if(q>p)
			flag=1;		
	}
	if(z.top==0&&flag!=1)
		printf("Expression is Correct\n");
	else
		printf("Expression is Incorrect\n");
	return 0;
}




