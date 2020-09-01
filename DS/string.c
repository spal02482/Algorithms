//String Functions...
#include<stdlib.h>
#define SIZE 30
int stringcompare(char *p,char *q)
{
	while((*(p++)==*(q++))&&((*p)!='\0'));
		return (*(--p)-*(--q));
}
int stringlength(char *p)
{
	int i;
	for(i=0;p[i]!='\0';i++);
	return i;
}
void stringconcatenate(char *p,char *q)
{
	int i,j,k=0;
	for(i=0;p[i]!='\0';i++);
	for(j=i;q[k]!='\0';j++)
		p[j]=q[k++];
	p[j]='\0';
}
void stringreverse(char *p)
{
	int i,n,j;
	char temp;
	for(i=0;p[i]!='\0';i++);
	n=i;
	for(i=0,j=n-1;i<j;i++,j--)
	{
		temp=p[i];
		p[i]=p[j];
		p[j]=temp;
	}
}
void stringcopy(char *p,char *q)
{
	int i;
	for(i=0;p[i]!='\0';i++)
		q[i]=p[i];
	q[i]='\0';
}
int main()
{
	char str1[30],str2[30];
	int s,d;
	printf("Enter string operation:\n1.stringlength\n2.stringcompare\n3.stringcopy\n4.stringreverse\n5.stringconacatenate\n");
	while(1)
	{
	scanf("%d",&d);
	switch(d)
	{
		case 1:
			{
				printf("Enter the string\n");
				scanf("%s",str1);
				s=stringlength(str1);
				printf("length of the string is %d\n",s);
				break;
			}
		case 2:
			{
				printf("Enter two strings\n");
				scanf("%s",str1);
				scanf("%s",str2);
				s=stringcompare(str1,str2);
				if(s==0)
					printf("Strings are same\n");
				else
					printf("Difference between them is %d\n",s);
				break;
			}
		case 3:
			{	
				printf("Enter the string\n");
				scanf("%s",str1);
				stringcopy(str1,str2);
				printf("The copied string is %s\n",str2);
				break;
			}
		case 4:
			{	
				printf("Enter the string\n");
				scanf("%s",str1);
				stringreverse(str1);
				printf("Reversed string is %s\n",str1);
				break;
			}
		case 5:
			{
				printf("Enter two strings\n");
				scanf("%s",str1);
				scanf("%s",str2);
				stringconcatenate(str1,str2);
				printf("Concatenated string is %s\n",str1);
				break;
			}
	}
}
}
/*output:
Enter string operation:
1.stringlength
2.stringcompare
3.stringcopy
4.stringreverse
5.stringconacatenate
1
Enter the string
hello,world
length of the string is 11
2   
Enter two strings
hello
hellw
Difference between them is -8
3
Enter the string
hello
The copied string is hello
4
Enter the string
helloworld
Reversed string is dlrowolleh
5
Enter two strings
hello
world
Concatenated string is helloworld
^C*/

