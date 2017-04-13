#include<stdio.h>
void insertionsort(int *,int,int,int);
void shellsort(int *a,int n)
{
	int incrementsize=n/2;
	for(int pass=1;incrementsize>=1;pass++)
	{
		for(int pass=0;pass<incrementsize;pass++)
		{
			int startindex=pass;
			insertionsort(a,startindex,incrementsize,n);
		}
		incrementsize/=2;

	}
}
void insertionsort(int *a,int startindex,int k,int n)
{
	for(int pass=startindex+k;pass<n;pass+=k)
	{
		int temp=a[pass];
		int j=pass-k;
		while(j>=0)
		{
			if(temp>=a[j])
				break;
			a[j+k]=a[j];
			j-=k;
		}
		a[j+k]=temp;
	}
}
