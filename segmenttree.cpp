/*arr                    0..................n-1
  segtree 1..........n-1 n..................2n-1
  To make the layer diagram, first fill the array and traversing from left to right,make the layers.
*/
#include <bits/stdc++.h>
using namespace std;
void build(int *arr,int *segtree,int n)
{
	//copy the array elements to segment tree from 2n-1 to nd.
	for(int i=n-1;i>=0;i--)
		segtree[n+i]=arr[i];
	//compute the minimum of two childs and and copy them into parent from n-1 to 1,0 is unused here.
	for(int i=n-1;i>=1;i--)
		segtree[i]=min(segtree[2*i],segtree[2*i+1]);
	
}
void update(int *segtree,int pos,int value,int n)
{
	//positioning pos in segtree and change it
	pos+=n;segtree[pos]=value;
	//change accordingly in parenst too.
	while(pos>1)
	{
		pos/=2;
		segtree[pos]=min(segtree[pos*2],segtree[pos*2+1]);
	}
}
//ranges are inclusive-inclusive [l,r]
int query(int *segtree,int l,int r,int n)
{
	//positioning ranges in the segtree
	l+=n,r+=n;	
	int mini=INT_MAX;
	while(l<=r)
	{
		//if l is not `even i.e. 2*i`,it can't be layered up,so we take the minimum and increment it 
		//so it can be layered up
		if(l%2!=0)
		{
			mini=min(mini,segtree[l]);
			l+=1;
		}
		//if r is not `odd i.e. 2*i+1`,it can't be layered up,so we take the minimum and decrement it 
		//so it can be layered up
		if(r%2==0)
		{
			mini=min(mini,segtree[r]);
			r-=1;
		}
		l/=2,r/=2;
	}
	return mini;
}
int main()
{
	int arr[]={9,4,3,6,7,11,8},segtree[2*7];
	build(arr,segtree,7);
	for(int i=1;i<=13;i++)
		printf("%d ",segtree[i]);
	printf("\n");
	update(segtree,5,2,7);
	for(int i=1;i<=13;i++)
		printf("%d ",segtree[i]);
	printf("\n");
	update(segtree,5,2,7);
	while(true)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query(segtree,l,r,7));
	}
}