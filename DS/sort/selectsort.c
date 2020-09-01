#include<stdio.h>
void selectsort(int *a,int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		if(min!=i)
		{
			int temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
}
int main()
{
	int n,arr[30];
	printf("Enter number of elments\n");
	scanf("%d",&n);
	printf("Enter Elements:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	selectsort(arr,n);
	printf("After Sorting the Elements are:\n");
	for(int i=0;i<n;i++)
		printf("%d\n",arr[i]);
	return 0;
}


