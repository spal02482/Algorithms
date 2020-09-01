//Queue implemented using linked list..
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
typedef struct queue{
	struct node *front,*rear;
}queue;
void enqueue(queue *q,int x)
{
	node *p=(node *)malloc(sizeof(node));
	p->data=x;
	p->next=NULL;
	if(q->front==NULL)
	{
		q->front=q->rear=p;
	}
	q->rear->next=p;
	q->rear=p;
}
int dequeue(queue *q)
{ 
	if(q->front==NULL)
	{
		printf("Queue Underflow\n");
		return -1;
	}
	if(q->front==q->rear)
		q->rear=NULL;
	int s=q->front->data;
	node *c=q->front;
	q->front=q->front->next;
	free(c);
	return s;
}
int main()
{
	queue q1;
	q1.front=q1.rear=NULL;
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
/*output:
Enter the elements to be enqueued
Enter -1 to quit
1
12
7
13
98
-1
Enter d to dequeue q to quit
d
Dequeued element is 1
d
Dequeued element is 12
d
Dequeued element is 7
d
Dequeued element is 13
d
Dequeued element is 98
d
Queue Underflow
*/




