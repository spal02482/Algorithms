//Queue using Circular Linked List
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
typedef struct {
	node *front;
}queue;
void enqueue(queue *q,int a)
{
	node *p=(node *)malloc(sizeof(node));
	p->data=a;
	p->next=NULL;
	if(q->front==NULL)
	{
		q->front=p;
		p->next=p;
		return;
	}
	p->next=q->front->next;
	q->front->next=p;
	q->front=p;
	return;
}
int dequeue(queue *q)
{
	if(q->front==NULL)
	{
		printf("Queue Underflow\n");
		exit(0);
	}
	node *s=q->front->next;
	int x=s->data;
	if(s==q->front)
		q->front=NULL;
	else
		q->front->next=s->next;
	free(s);
	return x;
}

int main()
{
	queue q1;
	q1.front=NULL;
	int n;
	char c;
	printf("Enter the elements to be enqueued\nEnter -1 to quit\n");
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
			break;
		enqueue(&q1,n);
	}
	printf("Enter d to dequeue q to quit\n");
	while(1)
	{
		scanf(" %c",&c);
		switch(c)
		{
			case 'd':
				{
				int s=dequeue(&q1);
				printf("Dequeued element is %d\n",s);
				break;
				}
			case 'q':
				exit(0);
		}
	}
	return 0;
}
