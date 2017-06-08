#include <stdio.h>
#include <limits.h>
#define min(a,b) a<b?a:b
void update_value(int *bt,int ni,int low,int high,int pos,int value)
{
	if(low==high)
	{
		bt[ni]=value;
		return;
	}
	int mid=(low+high)/2;
	if(pos<=mid)
		update_value(bt,2*ni+1,low,mid,pos,value);
	else
		update_value(bt,2*ni+2,mid+1,high,pos,value);
	bt[ni]=min(bt[2*ni+1],bt[2*ni+2]);
}
int range_minimum_query(int *bt,int ni,int q_low,int q_high,int low,int high)
{
	if(q_low<=low && high<=q_high) //TOTAL_OVERLAP
		return bt[ni];
	else if(high<q_low || low>q_high) //NO_OVERLAP
		return INT_MAX;
	else //PARTIAL_OVERLAP
	{
		int mid=(low+high)/2,left,right;
		left=range_minimum_query(bt,2*ni+1,q_low,q_high,low,mid);
		right=range_minimum_query(bt,2*ni+2,q_low,q_high,mid+1,high);
		return min(left,right);
	}
}
void construct_segment_tree(int *a,int *bt,int ni,int low,int high)
{
	if(low==high)
	{
		bt[ni]=a[low];
		return;
	}
	int mid=(low+high)/2;
	construct_segment_tree(a,bt,2*ni+1,low,mid);
	construct_segment_tree(a,bt,2*ni+2,mid+1,high);
	bt[ni]=min(bt[2*ni+1],bt[2*ni+2]);
}
int main()
{
	int a[]={3,6,1,2,5,4,9,7,8,11},bt[100]={0};
	construct_segment_tree(a,bt,0,0,9);
	for(int i=0;i<25;i++)
		printf("%d ",bt[i]);
	printf("\n");
	//update_value(bt,0,0,9,6,-1); //comment out to update the value..
	while(1)
	{
		int p,q;
		scanf("%d%d",&p,&q);
		int w=range_minimum_query(bt,0,p,q,0,9);
		printf("%d\n",w);
	}
	return 0;
}
