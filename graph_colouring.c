#include<stdio.h>
#include<stdbool.h>
int graph[10][10]={0},colored[10]={0},n,m;
char colors[10][10]={"","Red","Green","Blue","Yellow","White","Black"};
void print_sol()
{
	for(int i=1;i<=n;i++)
	{
		printf("%s ",colors[colored[i]]);
	}
}
int is_colorable(int k,int c)
{
	/* if node is k, then check for the colours of 
	 * previous nodes i.e, k-1 nodes.*/
	for(int i=1;i<=k-1;i++)
	{
		if(graph[k][i]==1 && c==colored[i])
			return false;
	}
	return true; 
}
void graph_color(int k)
{
	if(k==n+1)
	{
		print_sol();
		printf("\n");
		return;
	}
	for(int c=1;c<=m;c++)
	{
		if(is_colorable(k,c))
		{
			colored[k]=c;
			graph_color(k+1);
		}
	}
}
int main()
{
	printf("Enter Number of Vertices:");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	printf("Enter Number of Colours:");
	scanf("%d",&m);
	graph_color(1);
}
/*********************Example*******************************************
Enter Number of Vertices:4
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter Number of Colours:3
Red Green Green Red 
Red Green Green Blue 
Red Green Blue Red 
Red Blue Green Red 
Red Blue Blue Red 
Red Blue Blue Green 
Green Red Red Green 
Green Red Red Blue 
Green Red Blue Green 
Green Blue Red Green 
Green Blue Blue Red 
Green Blue Blue Green 
Blue Red Red Green 
Blue Red Red Blue 
Blue Red Green Blue 
Blue Green Red Blue 
Blue Green Green Red 
Blue Green Green Blue 

Enter Number of Vertices:5
0 1 1 0 0
1 0 1 0 0
1 1 0 1 1
0 0 1 0 1
0 0 1 1 0
Enter Number of Colours:3
Red Green Blue Red Green 
Red Green Blue Green Red 
Red Blue Green Red Blue 
Red Blue Green Blue Red 
Green Red Blue Red Green 
Green Red Blue Green Red 
Green Blue Red Green Blue 
Green Blue Red Blue Green 
Blue Red Green Red Blue 
Blue Red Green Blue Red 
Blue Green Red Green Blue 
Blue Green Red Blue Green 
*********************************************************************/