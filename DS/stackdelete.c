#include<stdio.h>
#include<stdlib.h>
#define SIZE 7
typedef struct stack{
	int list[SIZE];
	int top;
}stack;
void push(struct stack *p,int w)
{
	if(p->top==SIZE-1)
	{
		printf("Stack Overflow\n");
		return;
	}
	p->top++;
	p->list[p->top]=w;
	return;
	
}
int pop(struct stack *p)
{
	if(p->top==-1)
	{
		printf("Stack Underflow\n");
		return;
	}
	return p->list[p->top--];
}
int main()
{
	stack s1,s2;
	s1.top=s2.top=-1;
	int n,q,x,i;
	printf("Enter the element for the stack\n");
	printf("Enter -1 to quit\n");
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
		break;
		push(&s1,n);
	}
	printf("Enter the Element you want to be deleted\n");
	scanf("%d",&q);
	while((x=pop(&s1))!=q)
	{
		push(&s2,x);
	}
	while(s2.top!=-1)
	{
		x=pop(&s2);
		push(&s1,x);
	}
	printf("Elements after deletion are\n");
	for(i=s1.top;i>=0;i--)
		printf("%d\n",s1.list[i]);
	return 0;
}
/*
output:
Enter the element for the stack
Enter -1 to quit
1
2
3
4
5
6
-1
Enter the Element you want to be deleted
4
Elements after deletion are
6
5
3
2
1
*/

	

