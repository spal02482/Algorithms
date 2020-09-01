#include<stdio.h>
#include<stdlib.h>
#define SIZE 30
typedef struct queue{
	int list[SIZE];
	int front,rear;
}queue;
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
int main()
{
	queue q1;
	q1.front=q1.rear=-1;
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
2
3
4
5
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
Dequeued element is 5
d
Dequeued element is -1
q
*/
