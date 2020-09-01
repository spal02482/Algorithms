//Doublylinked List and their functions
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *prev;
	int data;
	struct node *next;
}node;
typedef struct dll{
	node *start;
}dll;
void addnode(dll *l)
{
	int data;
	printf("Enter the data for the node");
	scanf("%d",&data);
	node *p=(node *)malloc(sizeof(node));
	p->prev=NULL;
	p->data=data;
	p->next=NULL;
	if(l->start==NULL)
	{
		l->start=p;
		return;
	}
	node *q=l->start;
	while(q->next!=NULL)
		q=q->next;
	p->prev=q;
	q->next=p;
	return;
}
void display(dll *l)
{
	if(l->start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	node *q=l->start;
	while(q!=NULL)
	{
		printf("Data of the node is %d\n",q->data);
		q=q->next;

	}
	return;
}
void addbegin(dll *l)
{
	int data;
	printf("Enter the data for the node");
	scanf("%d",&data);
	node *p=(node *)malloc(sizeof(node));
	p->prev=NULL;
	p->data=data;
	p->next=NULL;
	if(l->start==NULL)
	{
		l->start=p;
		return;
	}
	p->next=l->start;
	l->start=p;
	return;
}
void delete(dll *l)
{
	int n;
	printf("Enter the data to be deleted:");
	scanf("%d",&n);
	node *q=l->start;
	while(q->data!=n)
		q=q->next;
	if(q==NULL)
	{
		printf("Data not found\n");
		return;
	}
	if(q->prev==NULL)
	{
		l->start=q->next;
		q->next->prev=NULL;
		free(q);
		return;
	}
	if(q->next==NULL)
	{
		q->prev->next=NULL;
		free(q);
		return;
	}
	q->prev->next=q->next;
	q->next->prev=q->prev;
	free(q);
	return;
}
int main()
{
	int n,i;
	dll l1;
	l1.start=NULL;
	printf("Enter the no. of elements\n");
	scanf("%d",&n);9
	for(i=0;i<n;i++)
		addnode(&l1);
	display(&l1);
	delete(&l1);
	display(&l1);
	addbegin(&l1);
	display(&l1);
	return 0;
}
/*output:
Enter the no. of elements
4
Enter the data for the node1
Enter the data for the node2
Enter the data for the node3
Enter the data for the node4
Data of the node is 1
Data of the node is 2
Data of the node is 3
Data of the node is 4
Enter the data to be deleted:4
Data of the node is 1
Data of the node is 2
Data of the node is 3
Enter the data for the node5
Data of the node is 5
Data of the node is 1
Data of the node is 2
Data of the node is 3
*/




