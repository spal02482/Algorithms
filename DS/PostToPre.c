#include<stdio.h>
#include<string.h>
#define SIZE 20
char stack[SIZE][SIZE];
int tos=-1;
void push(char *sub)
{
	if(tos==SIZE)
	{
		printf("Stack is full");
		return;
	}
	tos++;
	strcpy(stack[tos],sub);
	
}
void pop(char *p)
{
	if(tos==-1)
	{
		printf("Stack is empty");
		return;
	}
	strcpy(p,stack[tos]);
	tos--;
}
int main()
{
	char post[SIZE],copy1[SIZE],copy2[SIZE];
	char str[SIZE];
	char op[2];
	int i,j;
	printf("Enter the postfix String\n");
	scanf("%s",post);
	for(i=0;post[i]!='\0';i++)
	{
		if(post[i]=='+'||post[i]=='-'||post[i]=='*'||post[i]=='/'||post[i]=='^')
		{
			pop(copy1);
			pop(copy2);
			op[0]=post[i];
			op[1]='\0';
			strcpy(str,op);
			strcat(str,copy2);
			strcat(str,copy1);
			push(str);
		}
		else
		{
			op[0]=post[i];
			op[1]='\0';
			push(op);
		}
	}
	printf("Prefix form is");
	for(j=0;j<=tos;j++)
	{
		printf("%s",stack[j]);
	}
	printf("\n");
}
	
			

                                                                                                                                                                                                                  
