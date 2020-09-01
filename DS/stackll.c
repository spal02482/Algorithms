//Stack using Linked List..
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
typedef struct stack{
	struct node *tos;
}stack;
void push(stack *s,int x)
{
	node *p=(node *)malloc(sizeof(node));
	p->data=x;
	p->next=NULL;
	if(s->tos==NULL)
	{
		s->tos=p;
		return;
	}
	else
	{
		p->next=s->tos;
		s->tos=p;
	}
	return;
}
int pop(stack *s)
{
	if(s->tos==NULL)
	{
		printf("Stack Underflow\n");
		exit(0);
	}
	int x=s->tos->data;
	node *q=s->tos;
	s->tos=s->tos->next;
	free(q);
	return x;
}
int main()
{
	stack s1;
	s1.tos=NULL;
	int n,q;
	char c;
	printf("Enter the element for the stack\n");
	printf("Enter -1 to quit\n");
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
		break;
		push(&s1,n);
	}
	while(1)
	{
		printf("Enter p to pop and q to quit\n");
		scanf(" %c",&c);
		switch(c)
		{
			case 'p':
				q=pop(&s1);
				printf("popped element is %d\n",q);
				break;
			case 'q':
				break;
		}
	}
	return 0;
}
/*output:
Enter the element for the stack
Enter -1 to quit
1
2
3
-1
Enter p to pop and q to quit
p
popped element is 3
Enter p to pop and q to quit
p
popped element is 2
Enter p to pop and q to quit
p
popped element is 1
Stack Underflow
*/
