#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a>b?a:b
int lcs_length(int *s,int *p,int m,int n)
{
	int i,j;
	int dp[m+1][n+1];
	dp[0][0]=0;
	for(i=1;i<=m;i++)
		dp[i][0]=0;
	for(i=0;i<=n;i++)
		dp[0][i]=0;
	/*Determining the Length of LCS*/	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			/* if the matching character wouldn't have been in the 
			 * subsequence , then whatever the maximum length of 
			 * existing subsequence was , we add +1 into that */ 
			if(s[i]==p[j])
			{
				dp[i][j] = dp[i-1][j-1]+1;
			}
			/* if characters aren't matching then we have to
			 * exclude one of them , we take the maximum of their 
			 * previous values...
			 * Eg. if we exclude s[i] then dp[i-1][j]
			 *     and if we exclude p[j] then dp[i][j-1] */
			else
			{
				 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}


		}
	}

	/*Printing the LCS*/
	int lcs[dp[m][n]+1];
	i=m,j=n;
	int index=dp[m][n];
	while(i>=1 && j>=1)
	{
		if(s[i]==p[j])
		{
			lcs[index]=s[i];
			i--;
			j--;
			index--;
		}
		else if(dp[i-1][j] > dp[i][j-1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	printf("LCS:");
	for(i=1;i<=dp[m][n];i++)
	{
		printf("%d ",lcs[i]);
	}
	printf("\n");

	return dp[m][n];

}
int main()
{
	int s[20],p[20],m,n,i;
	printf("Enter the length of two strings:");
	scanf("%d%d",&m,&n);
	printf("Enter first string:");
	for(i=1;i<=m;i++)
		scanf("%d",&s[i]);
	printf("Enter second string:");
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	int subs = lcs_length(s,p,m,n);
	printf("Length:%d\n",subs);
	return 0;
}
/**********************************************Example****************************************
Enter the length of two strings:7 8
Enter first string:1 3 2 9 5 4 0
Enter second string:0 1 2 4 9 2 5 0  
LCS:1 2 9 5 0 
Length:5

Enter the length of two strings:3 9
Enter first string:1 5 8
Enter second string:5 6 2 4 1 9 5 2 3
LCS:1 5 
Length:2
********************************************************************************************/

