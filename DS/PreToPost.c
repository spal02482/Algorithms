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
	char pre[SIZE],copy1[SIZE],copy2[SIZE];
	char str[SIZE];
	char op[2];
	int i,j,len;
	printf("Enter the prefix String\n");
	scanf("%s",pre);
	len=strlen(pre);
	for(i=len;i>=0;i--)
	{
		if(pre[i]=='+'||pre[i]=='-'||pre[i]=='*'||pre[i]=='/'||pre[i]=='^')
		{
			pop(copy1);
			pop(copy2);
			op[0]=pre[i];
			op[1]='\0';
			strcpy(str,copy1);
			strcat(str,copy2);
			strcat(str,op);
			push(str);
		}
		else
		{
			op[0]=pre[i];
			op[1]='\0';
			push(op);
		}
	}
	printf("Postix form is");
	for(j=0;j<=tos;j++)
	{
		printf("%s",stack[j]);
	}
}


