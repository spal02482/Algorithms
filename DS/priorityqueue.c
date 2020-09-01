//Priority Queue (Sorted linked list in ascending order)
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
typedef struct pq{
	node *front;
}pq;
void enqueue(pq *pq,int x)
{
	node *p=(node *)malloc(sizeof(node));
	p->data=x;
	p->next=NULL;
	if(pq->front==NULL)
	{
		pq->front=p;
		return;
	}
	node *q=pq->front;
	node *prev=NULL;
	while(q!=NULL)
	{
		if(x<q->data)
		{
			if(q==pq->front)
			{
				p->next=pq->front;
				pq->front=p;
			}
			else
			{
				p->next=q;
				prev->next=p;
			}
			break;
		}
		else
		{
			prev=q;
			q=q->next;
		}
	}
	if(q==NULL)
	{
		prev->next=p;
	}
}
int dequeue(pq *pq)
{
	if(pq->front==NULL)
	{
		printf("Queue Underflow\n");
		exit(0);
	}
	node *q=pq->front;
	int x=pq->front->data;
	pq->front=pq->front->next;
	free(q);
	return x;
}
int main()
{
	pq pq1;
	pq1.front=NULL;
	int a;
	char c;
	printf("Enter the Elements to enqueue\nPress -1 to quit\n");
	while(1)
	{
		scanf("%d",&a);
		if(a==-1)
			break;
		enqueue(&pq1,a);
	}
	while(1)
	{
		printf("Enter d to dequeue and q to quit\n");
		scanf(" %c",&c);
		switch(c)
		{
			case 'd':
				{
					a=dequeue(&pq1);
					printf("Dequeued element is %d\n",a);
					break;
				}
			case 'q':
				break;
		}
	}
	return 0;
}
/*
output:
Enter the Elements to enqueue
Press -1 to quit
18
19
17
11
-1
Enter d to dequeue and q to quit
d
Dequeued element is 11
Enter d to dequeue and q to quit
d
Dequeued element is 17
Enter d to dequeue and q to quit
d
Dequeued element is 18
Enter d to dequeue and q to quit
d
Dequeued element is 19
Enter d to dequeue and q to quit
d
Queue Underflow
*/


