#include<stdio.h>
#include<limits.h>
#define true 1
#define false 0
/**Functions***
show_path()
dijkstra()
select_min()
input_graph()
print_distance_array()
**********/
int show_path(int i,int pred[10],int v)
{
	printf("%d<--",i);
	while(pred[i]!=v)
	{
		printf("%d<--",pred[i]);
		i=pred[i];
	}
	printf("%d",v);
}
void print_distance_array(int dist[10],int n)
{
	for(int i=1;i<=n;i++)
		printf("%d ",dist[i]);
	printf("\n");
}
void input_graph(int g[10][10],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
	}
}
int select_min(int dist[10],int s[10],int n)
{
	int i,min=INT_MAX,index;
	for(i=1;i<=n;i++)
	{
		if(min > dist[i] && s[i]!=true)
		{
			min=dist[i];
			index=i;
		}
	}
	return index;
}
void dijikstra(int v,int g[10][10],int dist[10],int pred[10],int n)
{
	int i,j,s[10],u,w;
	for(i=1;i<=n;i++)
	{
		pred[i]=-1;
	}
	pred[v]=v;
	for(i=1;i<=n;i++)
	{
		s[i]=false;
		dist[i]=g[v][i];
		if(g[v][i]!=999)
		{
			pred[i]=v;
		}
	}
	dist[v]=0;
	s[v]=true;
	for(int i=1;i<=n;i++)
		printf("%d ",dist[i]);
	printf("\n");
	for(i=2;i<=n;i++)
	{
		u=select_min(dist,s,n);
		s[u]=true;
		for(w=1;w<=n;w++)
		{
			if(g[u][w]!=0 && g[u][w]!=999 && dist[w]!=true)
			{
				if(dist[w] > dist[u] + g[u][w])
				{
					dist[w] = dist[u] + g[u][w];
					pred[w]=u;
				}
			}
		}
	}

}
int main()
{
	int graph[10][10],dist[10]={0},pred[10],n,v;
	printf("Enter the Number of Vertices: \n");
	scanf("%d",&n);
	printf("Enter the weights of edges(999 if Edge doesn't exist): \n");
	input_graph(graph,n);
	printf("Enter the Source Vertex: \n");
	scanf("%d",&v);
	printf("Before Dijikstra Distance array \n");
	dijikstra(v,graph,dist,pred,n);
	printf("After Dijikstra Distance array \n");
	print_distance_array(dist,n);
	printf("Paths are: \n");
	for(int i=1;i<=n;i++)
	{
		show_path(i,pred,v);
		printf("\n");
	}
	printf("\n");
	return 0;
}
/*******************Example*********************************************
Enter the Number of Vertices: 
5
Enter the weights of edges(999 if Edge doesn't exist): 
0 50 45 10 999
999 0 10 15 999
999 999 0 999 30
20 999 999 0 15
999 20 35 999 0
Enter the Source Vertex: 
1
Before Dijikstra Distance array 
0 50 45 10 999 
After Dijikstra Distance array 
0 45 45 10 25 
Paths are: 
1<--1
2<--5<--4<--1
3<--1
4<--1
5<--4<--1

Enter the Number of Vertices: 
5
Enter the weights of edges(999 if Edge doesn't exist): 
0 10 999 999 5
999 0 1 999 2
999 999 0 4 999
7 999 6 0 999
999 3 9 2 0
Enter the Source Vertex: 
1
Before Dijikstra Distance array 
0 10 999 999 5 
After Dijikstra Distance array 
0 8 9 7 5 
Paths are: 
1<--1
2<--5<--1
3<--2<--5<--1
4<--5<--1
5<--1

***************************************************/

