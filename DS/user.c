/*Name:Suraj Pal
  Roll No.:7656
  SE COMPS
*/
//User Database
#include<stdio.h>
#include<stdlib.h>
typedef struct data{
	int user;
	int passwd;
}data;
int main()
{
	data *pt;
	int n,flag=0,i,t=0,a,j,u,q,m=1;
	char w='y';
	printf("How many users do you want\n");
	scanf("%d",&n);
	pt=(data *)malloc(n*sizeof(data));
	for(i=0;i<n;i++)
	{
		printf("Enter username for %d candidate:",i+1);
		scanf("%d",&pt[i].user);
		printf("Enter Pincode:");
		scanf("%d",&pt[i].passwd);
	}
do
{
	flag=0;
	printf("1.Login\n2.Add another user\n");
	scanf("%d",&a);
	if(a==1)
	{
		printf("Enter Username\n");
		scanf("%d",&q);
		for(i=0;i<n+m-1;i++)
		{
			if(q==pt[i].user)
			{
				flag=1;
				j=i;
			}
		}
		if(flag==1)
		{
			printf("Enter Password:");
			scanf("%d",&u);
			if(u==pt[j].passwd)
				printf("Login Successful\n");
			else
				printf("Password incorrect\n");
		}
	}
	if(a==2)
	{
		pt=(data *)realloc(pt,(n+m)*sizeof(data));
		printf("Enter Username:");
		scanf("%d",&pt[n+m-1].user);
		printf("Enter Pincode:");
		scanf("%d",&pt[n+m-1].passwd);
		m++;
		t++;
	}
	printf("\nDo You Want to Continue(y/n): ");
	scanf(" %c",&w);
}while(w!='n');
}
/*output:
How many users do you want
3
Enter username for 1 candidate:1
Enter Pincode:1
Enter username for 2 candidate:2
Enter Pincode:2
Enter username for 3 candidate:3
Enter Pincode:3
1.Login
2.Add another user
1
Enter Username
1
Enter Password:1
Login Successful

Do You Want to Continue(y/n): y
1.Login
2.Add another user
1
Enter Username
2
Enter Password:3
Password incorrect

Do You Want to Continue(y/n): y
1.Login
2.Add another user
2
Enter Username:4
Enter Pincode:4

Do You Want to Continue(y/n): y
1.Login
2.Add another user
1
Enter Username
4
Enter Password:4
Login Successful

Do You Want to Continue(y/n): n
*/

