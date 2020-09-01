#include<stdio.h>
#include<stdlib.h>
void insertionsort(int *a,int n)
{
	int j;
	for(int i=1;i<n;i++)
	{
		j=i-1;
		int temp=a[i];
		while(j>=0)
		{
			if(temp>=a[j])
				break;
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
		for(int k=0;k<n;k++)
		{
			printf("%d ",a[k]);
		}
		printf("Pass:%d ",i);
		printf("\n");
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
	insertionsort(arr,n);
	printf("After Sorting the Elements are:\n");
	for(int i=0;i<n;i++)
		printf("%d\n",arr[i]);
	return 0;
}
