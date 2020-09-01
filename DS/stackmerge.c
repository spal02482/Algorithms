#include<stdio.h>
#include<stdlib.h>
#define SIZE 7
typedef struct stack{
	int list[SIZE];
	int tos1,tos2;
}stack;
void push(stack *s,int stackno,int x)
{
	if(stackno==1)
	{
		if(s->tos1+1==s->tos2)
		{
			printf("Stack Overflow\n");
			return;
		}
		s->list[++s->tos1]=x;
		return;
	}
	if(stackno==2)
	{
		if(s->tos1+1==s->tos2)
		{
			printf("Stack Overflow\n");
			return;
		}
		s->list[--s->tos2]=x;
		return;		
	}
}
int pop(stack *s,int stackno)
{
	if(stackno==1)
	{
		if(s->tos1==-1)
		{
			printf("Stack Overflow\n");
			return -1;
		}
		return s->list[s->tos1--];
	}
	if(stackno==2)
	{
		if(s->tos2==SIZE)
		{
			printf("Stack Overflow\n");
			return -1;
		}
		return s->list[s->tos2++];
	}
}
int main()
{
	stack s1;
	s1.tos1=-1;
	s1.tos2=SIZE;
	int stackno,a,q,p,c,t,i,o,flag;
	char w;
	while(1)
	{
		flag=0;
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
		scanf("%d",&a);
		if(a==1)
		{
			printf("1.Stack1\t2.stack2\n");
			scanf("%d",&p);
			printf("Enter the Elements.\nEnter -1 to quit.\n");
			while(1)
			{
				scanf("%d",&q);
				if(q==-1)
					break;
				push(&s1,p,q);
			}
		}
		else if(a==2)
		{
			printf("1.stack1\t2.stack2\n");
			scanf("%d",&c);
			printf("Press P to pop & Q to quit\n");
			while(1)
			{
				scanf("%c",&w);
				switch(w)
				{
					case 'p':
						{
							o=pop(&s1,c);
							printf("%d\n",o);
							break;
						}
					case 'q':
						{
							flag=1;
						}
				}
				if(flag==1)
					break;
			}
		}
		else if(a==3)
		{
			printf("1.stack1\t2.stack2\n");
			scanf("%d",&t);
			if(t==1)
			{
				for(i=s1.tos1;i>=0;i--)
					printf("%d\n",s1.list[i]);
			}
			else if(t==2)
			{
				for(i=s1.tos2;i<SIZE;i++)
					printf("%d\n",s1.list[i]);
			}
		}
		if(a==4)
			exit(0);
	}
	return 0;
}

			
		
		
		
















