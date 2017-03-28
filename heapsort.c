#include<math.h>
void swap(int *a,int *b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
void max_heapify(int *heap,int i,int n)
{
	int left,right,largest=i;
	left=2*i+1;
	right=2*i+2;
	if(left<n && heap[i]<heap[left])
	{
		largest=left;
	}
	if(right<n && heap[largest]<heap[right])
	{
		largest=right;
	}
	if(largest!=i)
	{	
		swap(&heap[i],&heap[largest]);
		max_heapify(heap,largest,n);
	}

}
void build_max_heap(int *heap,int n)
{
	for(int i=ceil(n/2)-1;i>=0;i--)
	{
		max_heapify(heap,i,n);
	}

}
void heapsort(int *heap,int n)
{
	build_max_heap(heap,n);
	for(int i=n-1;i>=1;i--)
	{
		swap(&heap[0],&heap[i]);
		max_heapify(heap,0,i);
	}
}
/***********Output********************
 * Enter array size:11
 * 5
 * 3
 * 11
 * 9
 * 15
 * 2
 * 8
 * 6
 * 4
 * 7
 * 1
 * After sorting:
 * 1
 * 2
 * 3
 * 4
 * 5
 * 6
 * 7
 * 8
 * 9
 * 11
 * 15
 */
