#include<stdio.h>
#include<stdlib.h>
#define SIZE 15
typedef struct stack
{
	int list[SIZE];
	int top;
}stack;
typedef struct queue{
	int list[SIZE];
	int front,rear;
}queue;
void push(struct stack *p,int w)
{
	if(p->top==SIZE-1)
	{
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
		return -1;
	}
	 int x=p->list[p->top--];
}
void enqueue(queue *q,int x)
{
	if(q->rear==SIZE-1)
	{
		return;
	}
	q->list[++q->rear]=x;
	return;
}
int dequeue(queue *q)
{
	if(q->front==q->rear)
	{
		return -1;
	}
	int  x=q->list[++q->front];
	return x;

}
void display(queue *q)
{
	int a;
	for(a=q->front+1;a<=q->rear;a++)
		printf("%d\n",q->list[a]);
}
int main()
{
	stack s1;
	queue q1;
	s1.top=-1;
	q1.front=q1.rear=-1;
	int a,x,c;
	printf("Enter Elements to Enqueue\nPress -1 to quit\n");
	scanf("%d",&a);
	while(a!=-1)
	{
		enqueue(&q1,a);
		scanf("%d",&a);
	}
	printf("Reversed Queue is :\n");
	while((x=dequeue(&q1))!=-1)
	{
		push(&s1,x);
	}
	q1.front=q1.rear=-1;
	while((c=pop(&s1))!=-1)
	{	
		enqueue(&q1,c);		
}
	display(&q1);

}
/*
Enter Elements to Enqueue
Press -1 to quit
1
2
3
4
5
-1
Reversed Queue is :
5
4
3
2
1
*/
