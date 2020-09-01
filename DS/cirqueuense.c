//circular queue with non-sacrificing element with Array implementation
#include<stdio.h>
#include<stdlib.h>
#define size 30
typedef struct queue{
	int list[size];
	int rear,front,count;
}queue;
void enqueue(queue *,int);
int dequeue(queue *);
int main()
{
	queue q;
	q.rear=q.front=q.count=-1;
	int x,n,p;
	char c;
	printf("Enter elements to be enqueued\nPress -1 to quit\n");
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
		break;
		enqueue(&q,n);
	}
printf("Press d to dequeue and q to quit\n");
while(1)
{
	scanf("%c",&c);
	switch(c)
	{
	case 'd':
	{
	p=dequeue(&q);
	printf("Dequeued element is %d\n",p);
	break;
	}
	case 'q':
	break;
	}
}
}
void enqueue(queue *q1,int x)
{
	if(q1->count==size-1)
	{
		printf("Queue Overflow\n");
		exit(0);
	}
	q1->rear=(q1->rear+1)%size;
	q1->count++;
	q1->list[q1->rear]=x;
}
int dequeue(queue *q1)
{
	if(q1->count==-1)
	{
		printf("Queue underflow\n");
		exit(0);
	}
	q1->count--;
	q1->front=(q1->front+1)%size;
	return q1->list[q1->front];
}
	
	
 
		