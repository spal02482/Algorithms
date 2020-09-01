//Stack using Array..
#include<stdio.h>
#include<stdlib.h>
#define SIZE 6
struct s
{
	int list[6];
	int top;
};
void push(struct s *p,int w)
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
int pop(struct s *p)
{
	if(p->top==-1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return p->list[p->top--];
}
int main()
{
	struct s z;
	z.top=-1;
	int i,a,x;
	printf("Enter the 6 elements you want to be Pushed in stack\n");
	for(i=0;i<=5;i++)
	{
		scanf("%d",&a);
		push(&z,a);
	}
	printf("Elements after popping are\n");
	for(i=0;i<=5;i++)
	{
		x=pop(&z);
		printf("%d\n",x);
	}
	return 0;
}
/*output:
Enter the 6 elements you want to be Pushed in stack
1
2
3
67
43
12
Elements after popping are
12
43
67
3
2
1
*/
