#include<stdio.h>
#include<stdio.h>
#define max(a,b) a>b?a:b
int knapsack(int w[10],int v[10],int N,int W)
{
	int dp[N+1][W+1],i,j;
	dp[0][0]=0;
	for(i=1;i<=W;i++)
		dp[0][i]=0;
	for(i=1;i<=N;i++)
		dp[i][0]=0;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=W;j++)
		{
			if(w[i]>j)
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				dp[i][j]=max(v[i]+dp[i-1][j-w[i]],dp[i-1][j]);
			}
		}
	}
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=W;j++)
			printf("%3d  ",dp[i][j]);
		printf("\n");
	}
	return dp[N][W];

}
int main()
{
	int i,j,w[10],v[10],W,N;
	printf("Enter Knapsack Capacity:");
	scanf("%d",&W);
	printf("Enter Number of Objects:");
	scanf("%d",&N);
	printf("Enter Weights:");
	for(i=1;i<=N;i++)
		scanf("%d",&w[i]);
	printf("Enter Values:");
	for(i=1;i<=N;i++)
		scanf("%d",&v[i]);
	int max_profit=knapsack(w,v,N,W);
	printf("max_profit=%d\n",max_profit);
	return 0;
}
/*********************Examples******************************
Enter Knapsack Capacity:7
Enter Number of Objects:4
Enter Weights:1 3 4 5
Enter Values:1 4 5 7
0  0  0  0  0  0  0  0  
0  1  1  1  1  1  1  1  
0  1  1  4  5  5  5  5  
0  1  1  4  5  6  6  9  
0  1  1  4  5  7  8  9  
max_profit=9

Enter Knapsack Capacity:10
Enter Number of Objects:5
Enter Weights:2 3 3 4 6
Enter Values:1 2 5 9 4
0    0    0    0    0    0    0    0    0    0    0  
0    0    1    1    1    1    1    1    1    1    1  
0    0    1    2    2    3    3    3    3    3    3  
0    0    1    5    5    6    7    7    8    8    8  
0    0    1    5    9    9   10   14   14   15   16  
0    0    1    5    9    9   10   14   14   15   16  
max_profit=16
************************************************************/

