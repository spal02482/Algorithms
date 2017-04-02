#include<stdio.h>
int w[20],sol[20],sum,n;
void print_sol()
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",sol[i]);
	}
	printf("\n");
}
int is_promising(int wsf,int tpl,int l)
{
	/*We do not need l < n constraint because wsf > sum is not possible
	 * and when array element ends then tpl = 0 and wsf + tpl >= sum
	 * conditions gets falsified and process terminates on its own.
	 */ 
	if(wsf+w[l+1] <= sum && wsf+tpl >= sum)
		return 0;
	else
		return 1;
}
int sum_of_subset(int wsf,int tpl,int l)
{
	if(wsf == sum)
	{
		print_sol();
	}
	else if(!(is_promising(wsf,tpl,l)))
	{
		sol[l+1]=1;
		sum_of_subset(wsf+w[l+1],tpl-w[l+1],l+1);
		sol[l+1]=0;
		sum_of_subset(wsf,tpl-w[l+1],l+1);
	}

}
int main()
{
	int wsf=0,tpl=0,l=-1;
	printf("Enter number of Weights:");
	scanf("%d",&n);
	printf("Enter Sum:");
	scanf("%d",&sum);
	printf("Enter Weights:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&w[i]);
		tpl+=w[i];
	}
	sum_of_subset(wsf,tpl,l);
}
/******************************Example******************************
 
 Enter number of Weights:5
 Enter Sum:23
 Enter Weights:
 5
 6
 11
 12
 17
 1 1 0 1 0 
 0 1 0 0 1 
 0 0 1 1 0 

 Enter number of Weights:4
 Enter Sum:12
 Enter Weights:
 3
 5
 7
 9
 1 0 0 1 
 0 1 1 0 
 *******************************************************************/
