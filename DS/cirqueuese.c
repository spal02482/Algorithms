//circular queue with array implemetation and sacrificing element
#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
typedef struct queue{
	int list[SIZE];
	int front,rear;
}queue;
void enqueue(queue *q,int x)
{
	if(q->front==(q->rear+1)%SIZE)
	{
		printf("Queue Overflow\n");
		exit(0);
	}
	q->rear=(q->rear+1)%SIZE;
	q->list[q->rear]=x;
}
int dequeue(queue *q)
{
	if(q->front==q->rear)
	{
		printf("Queue Underflow\n");
		exit(0);
	}
	q->front=(q->front+1)%SIZE;
	int p=q->list[q->front];
	return p;
}
int main()
{
	queue q1;
	q1.front=q1.rear=SIZE-1;
	int n;
	char c;
	printf("Enter the elements to be enqueued(<19)\nEnter -1 to quit\n");
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
				break;
		}
	}
	return 0;
}
/*output:
Enter the elements to be enqueued
Enter -1 to quit
1
2
3
4
-1
Enter d to dequeue q to quit
d
Dequeued element is 1
d
Dequeued element is 2
d
Dequeued element is 3
d
Dequeued element is 4
d
Queue Underflow
*/



