#include<stdio.h>
#include<stdlib.h>
#define SIZE 30
#include<ctype.h>
typedef struct node{
	struct node *left;
	char data;
	struct node *right;
}node;
typedef struct stack{
	node *list[SIZE];
	int tos;
}stack;
void push(stack *s,node *x)
{
	if(s->tos==SIZE-1)	
	{
		printf("Stack Overflow\n");
		return;
	}
	s->list[++s->tos]=x;
	return;
}
node * pop(stack *s)
{
	if(s->tos==-1)
	{
		printf("Stack Underflow\n");
		exit(0);
	}
	return (s->list[s->tos--]);
}
node* createtree(char *);
void inorderfullpar(node *);
int evaluatetree(node *);
void preorder(node *);
void postorder(node *);
int main()
{
	char postfix[30];
	node *root;
	printf("Enter A postfix expression:");
	scanf("%s",postfix);
	root=createtree(postfix);
	printf("InOrder Expression is:");
	inorderfullpar(root);
	int l=evaluatetree(root);
	printf("\n%d\n",l);
}
node* createtree(char *a)
{
	stack s;
	s.tos=-1;
	node *rop,*lop;
	for(int i=0;a[i]!='\0';i++)
	{
		node *p=(node *)malloc(sizeof(node));
		p->left=NULL;
		p->data=a[i];
		p->right=NULL;
		if(!isalnum(a[i]))
		{
			rop=pop(&s);
			p->right=rop;
			lop=pop(&s);
			p->left=lop;
		}
		push(&s,p);
	}
	return pop(&s);
}
void inorderfullpar(node *r)
{
	if(r!=NULL)
	{
		if(r->left!=NULL&&r->right!=NULL)
			printf("(");
		inorderfullpar(r->left);
		printf("%c",r->data);
		inorderfullpar(r->right);
		if(r->left!=NULL&&r->right!=NULL)
			printf(")");
	}
	return;
}
int evaluatetree(node *r)
{
	int lo,ro;
	if(r->left==NULL&&r->right==NULL)
	{
		return (int)r->data;
	}
	else
	{
		lo=evaluatetree(r->left);
		ro=evaluatetree(r->right);
		printf("%d %d\n",lo,ro);
		switch(r->data)
		{
			
			case '+':
				return lo+ro;
			case '-':
				return lo-ro;
			case '*':
				return lo*ro;
			case '/':
				return lo/ro;
	}
}
}















