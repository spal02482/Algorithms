#include<stdio.h>
#include<stdlib.h>
typedef struct Pair
{
	int key;
	int value;
}pair;
int main()
{
	pair i[5];
	int j,arr[25],count=0,k=0,x;
	printf("Enter Elments ?:");
	for(j=0;j<25;j++)
	{
		
		if(count==5)
			count=0;
		scanf("%d",&arr[j]);
		if(count==0)
		{
			i[k].key=j;
			i[k].value=arr[j];
			k++;
		}
		count++;
	}
	for(j=0;j<5;j++)
	{
		printf("pair.key %d pair.value %d\n",i[j].key,i[j].value);
	}
	
	printf("Enter the Element to be searched\n");
	scanf("%d",&x);
	int flag=0;
	//this is actually a bottom approach(preferred in index sequential search)
	for(j=4;j>=0;j--)
	{
		if(i[j].value==x)
		{
			printf("Element found at position %d \n",i[j].key);
			flag=1;
			break;
		}
		else if(i[j].value < x)
		{
			for(k=1;k<=4;k++)
			{
				if(arr[i[j].key+k]==x)
				{
					printf("Element found at position %d \n",i[j].key+k);
					flag=1;
					break;
				}
				
			}
		}
	}
	if(flag!=1)
		printf("Element not found\n");
}
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
	
