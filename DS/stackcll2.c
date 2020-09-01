//Stack using Circular Linked List
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
typedef struct Stack{
	node *tos;
}Stack;
void push(Stack *s,int x)
{
	node *p=(node *)malloc(sizeof(node));
	p->data=x;
	p->next=NULL;
	if(s->tos==NULL)
	{
		p->next=p;
		s->tos=p;
		return;
	}
	p->next=s->tos->next;
	s->tos->next=p;
}
int pop(Stack *s)
{
	if(s->tos==NULL)
	{
		printf("Stack Underflow\n");
		exit(0);
	}
	node *ptr=s->tos->next;
	int x=ptr->data;
	if(s->tos==ptr)
		s->tos=NULL;
	else
		s->tos->next=ptr->next;
	free(ptr);
	return x;
}
int main()
{
	Stack s1;
	s1.tos=NULL;
	int n;
	char c;
	printf("Enter the elements to be pushed\nEnter -1 to suit\n");
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
			break;
		push(&s1,n);
	}
	printf("Enter p to pop q to suit\n");
	while(1)
	{
		scanf(" %c",&c);
		switch(c)
		{
			case 'p':
				{
				int s=pop(&s1);
				printf("popped element is %d\n",s);
				break;
				}
			case 'q':
				exit(0);
		}
	}
	return 0;
}
/*output:
Enter the elements to be pushed
Enter -1 to quit
12
34
54
66
76
-1
Enter d to pop q to quit
d
popped element is 76
d
popped element is 66
d
popped element is 54
d
popped element is 34
d
popped element is 12
d
Stack Underflow
*/
