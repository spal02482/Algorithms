#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *next;
}node;
typedef struct ll{
	node *start;
}ll;
void appendnode(ll *l)
{
	int n;
	node *q;
	node *p=(node *)malloc(sizeof(node));
	p->next=NULL;
	printf("Enter the data for the node\n");
	scanf("%d",&n);
	p->data=n;
	if(l->start==NULL)
	{
		l->start=p;
		return;
	}	
	q=l->start;		
	while(q->next!=NULL)
		q=q->next;
	q->next=p;
}
int nodecount(ll *l)
{
	int count=0;
	node *q=l->start;
	while(q!=NULL)
	{
		q=q->next;
		count++;
	}
	return count;
}

	
void reverse(ll *l)
{
	if(l->start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	node *current=l->start;
	node *prev=NULL;
	node *nextnode;
	while(current!=NULL)
	{
		nextnode=current->next;
		current->next=prev;
		prev=current;
		current=nextnode;
	}
	l->start=prev;
}
void displaynode(ll l)
{
	node *q;
	if(l.start==NULL)
	{
		printf("List is empty\n");			
	}
	q=l.start;
	while(q!=NULL)
	{
		printf("Data is %d\n",q->data);
		q=q->next;
	}
}
void addbegin(ll *l)
{
	int a;
	node *p=(node *)malloc(sizeof(node));
	printf("Enter your data\n");
	scanf("%d",&a);
	p->data=a;
	p->next=NULL;
	if(l->start==NULL)
	{
		l->start=p;
		return;
	}
	node *w=l->start;
	l->start=p;
	p->next=w;
}
void addaftern(ll *l)
{
	int n,a;
	//int lsize=nodecount(ll l);
	node *p=(node *)malloc(sizeof(node));
	printf("Enter your data\n");
	scanf("%d",&a);
	p->data=a;
	p->next=NULL;
	printf("Enter Position\n");
	scanf("%d",&n);
/*	if(n==1)
		addbegin(ll l);
	else if(n==lsize)
		appendnode(ll l);
	else if(n>lsize)
		printf("Node doesn't exist\n");
	else
	{*/
		node *q=l->start;
		for(int i=1;i<n-1;i++)
			q=q->next;
		node *s=q->next;
		q->next=p;
		p->next=s;
	//}
	return;
}
int main()
{
	int i;
	ll l1;
	l1.start=NULL;
	for(i=0;i<5;i++)
		appendnode(&l1);
	displaynode(l1);
	reverse(&l1);
	displaynode(l1);
	printf("%d\n",nodecount(&l1));
	addbegin(&l1);
	displaynode(l1);
	addaftern(&l1);
	displaynode(l1);
	return 0;
}



