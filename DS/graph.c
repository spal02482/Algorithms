#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define MAX 10

int adj[MAX][MAX]={0};
int visited [MAX]={0};
int stack[MAX];
int tos=-1,front=-1,rear=-1;
int queue[MAX];

void push(int v)
{
	stack[++tos]=v;
}
int pop()
{
	return stack[tos--];
}
int isEmpty()
{
	if(tos==-1)
		return 1;
	else
		return 0;
}
void enqueue(int a)
{
	queue[++front]=a;
}
int dequeue()
{
	return queue[++rear];
}
void dfs(int v,int n)
{
	int i;
	visited[v]=1;
	printf("%d\t",v);
	for(i=1;i<n;i++)
	{
		if(adj[v][i]==1&&!visited[i])
		{
			dfs(i,n);
		}
	}
}
void non_dfs(int v,int n)
{
	int x,i;
	visited[v]=1;
	push(v);
	while(!isEmpty())
	{
		x=pop();
		printf("%d\t",x);
		for(i=0;i<n;i++)
		{
			if(adj[x][i]==1&&!visited[i])
			{

				push(i);
				visited[i]=1;
			}
		}
	}
}
void non_bfs(int n,int v)
{
	int i,x;
	visited[v]=1;
	enqueue(v);
	while(front!=rear)
	{
		x=dequeue();
		printf("%d\t",x);
		for(i=0;i<n;i++)
		{
			if(adj[x][i]==1&&!visited[i])
			{
				enqueue(i);
				visited[i]=1;
			}
		}
	}
}
void resetvisited(int n)
{
	int i;
	for(i=0;i<=n;i++)
		visited[i]=0;

	
}
void display(int e)
{
	for(int i=1;i<=e;i++)
	{
		for(int j=1;j<=e;j++)
			printf("%d\t",adj[i][j]);
		printf("\n");
	}
}
			
int main()
{
	int v,e,start,dest;

		printf("Enter the vertices and edge");
		scanf("%d%d",&v,&e);
	for(int i=1;i<=e;i++)
	{
		printf("Enter the start node");
		scanf("%d",&start);
		printf("Enter the destinated node");
		scanf("%d",&dest);
		adj[start][dest]=1;
		adj[dest][start]=1;
	}
	non_dfs(2,v);
}


