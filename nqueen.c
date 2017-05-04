#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int x[17]={0},n;
void print_sol()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i]==j)
				printf(" * ");
			else
				printf(" X ");
		}
		printf("\n");
	}
}
bool can_place(int q,int i)
{
	/* Since we are placing queen q ,we will have to examine at which 
	 * position other queens (q-1 queens) have been placed so that the position of
	 * queen q doesn't conflict.*/
	for(int k=1;k<=q-1;k++)
	{
		/* k : queen k
		 * q : queen q
		 * i : position at which queen q is getting placed
		 * x[k] : position of the queen k
		 */
		if(x[k]==i||abs(x[k]-i)==abs(k-q))
			return false;
		/* if x[k]==i
		 * then position of queen k (x[k]) and position at which queen q is
		 * getting placed (i) will place them in same column.
		 * if abs(x[k]-i)==abs(k-q)
		 * then the difference between the positions of queen k (x[k])
		 * and queen q (i) is same as the difference between the queen them-
		 * selves placing them in the same diagonal.*/
	}
	return true;
}
void nqueen(int q)
{
	int i;
	if(q==n+1)
	{
		print_sol();
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(can_place(q,i))
		{
			x[q]=i;
			nqueen(q+1);
		}
	}
}
int main()
{
	printf("Enter the Number of Queens:");
	scanf("%d",&n);
	nqueen(1);
	return 0;
}
/*************************Example**********************************
Enter the Number of Queens:4
 X  *  X  X 
 X  X  X  * 
 *  X  X  X 
 X  X  *  X 

 X  X  *  X 
 *  X  X  X 
 X  X  X  * 
 X  *  X  X 

Enter the Number of Queens:5
 *  X  X  X  X 
 X  X  *  X  X 
 X  X  X  X  * 
 X  *  X  X  X 
 X  X  X  *  X 

 *  X  X  X  X 
 X  X  X  *  X 
 X  *  X  X  X 
 X  X  X  X  * 
 X  X  *  X  X 

 X  *  X  X  X 
 X  X  X  *  X 
 *  X  X  X  X 
 X  X  *  X  X 
 X  X  X  X  * 

 X  *  X  X  X 
 X  X  X  X  * 
 X  X  *  X  X 
 *  X  X  X  X 
 X  X  X  *  X 

 X  X  *  X  X 
 *  X  X  X  X 
 X  X  X  *  X 
 X  *  X  X  X 
 X  X  X  X  * 

 X  X  *  X  X 
 X  X  X  X  * 
 X  *  X  X  X 
 X  X  X  *  X 
 *  X  X  X  X 

 X  X  X  *  X 
 *  X  X  X  X 
 X  X  *  X  X 
 X  X  X  X  * 
 X  *  X  X  X 

 X  X  X  *  X 
 X  *  X  X  X 
 X  X  X  X  * 
 X  X  *  X  X 
 *  X  X  X  X 

 X  X  X  X  * 
 X  *  X  X  X 
 X  X  X  *  X 
 *  X  X  X  X 
 X  X  *  X  X 

 X  X  X  X  * 
 X  X  *  X  X 
 *  X  X  X  X 
 X  X  X  *  X 
 X  *  X  X  X 

****************************************************/