/*
 Name:Pal Suraj
 Roll No.:7656
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct Sack
{
	int profit;
	int weight;
	float ratio;
}sack;
void bubblesort(sack *s,int n)
{
	int c,d;
	sack swap;
	for (c = 0 ; c < ( n - 1  ); c++)
	{
		    for (d = 0 ; d < n - c - 1; d++)
		    {
			          if (s[d].ratio < s[d+1].ratio)
				  {
					          swap = s[d];
						  s[d] = s[d+1];
				                  s[d+1] = swap;
								        
				  }
				      
		    }
		      
	}
}
void knapsack(sack *s,int n,int w)
{
	int i=0;
	float count=0.0,total=0.0;
	float *x = (float *)calloc(n,sizeof(float));
	while(i<=n && s[i].weight <= (w-count))
	{
		x[i]=1;
		count+=s[i].weight;
		i++;
	}
	if(i<=n)
	{
		x[i]=(w-count)/(float)s[i].weight;
	}
	i++;
	printf("Proportion = ");
	for(int j=0;j<i;j++)
	{
		printf("%f ",x[j]);
	}
	printf("\n");
	for(int j=0;j<i;j++)
	{
		total+=x[j]*s[j].profit;
	}
	printf("Total = %f\n",total);

}
int main( void )
{
	int n,w;
	printf("Enter the Number of Objects:");
	scanf("%d",&n);
	printf("\nEnter the Knapsack Capacity:");
	scanf("%d",&w);
	sack *s = (sack *)malloc(n*sizeof(sack));
	printf("\nProfit	Weight\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d\t%d",&s[i].profit,&s[i].weight);
		s[i].ratio=(float)s[i].profit/s[i].weight;
	}
	bubblesort(s,n);
	printf("Ratio = ");
	for(int i=0;i<n;i++)
	{
		printf("%f ",s[i].ratio);
	}
	printf("\n");
	knapsack(s,n,w);
}
/**Examples**********************************************************************
Enter the Number of Objects:5  

Enter the Knapsack Capacity:15

Profit	Weight
4	12
2	1
2       2
1	1
10	4
Ratio = 2.500000 2.000000 1.000000 1.000000 0.333333 
Proportion = 1.000000 1.000000 1.000000 1.000000 0.583333 
Total = 17.333334


Enter the Number of Objects:3

Enter the Knapsack Capacity:20

Profit	Weight
25	18
24	15
15	10
Ratio = 1.600000 1.500000 1.388889 
Proportion = 1.000000 0.500000 
Total = 31.500000
***************/
