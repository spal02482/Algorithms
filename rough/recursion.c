#include<stdio.h>
long unsigned int array[100]={0};
long unsigned int recurse(long unsigned int n)
{
	if(array[n]!=0)
		return array[n];
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else
	{
		array[n]=recurse(n-2)+recurse(n-1);
	}
	return array[n];
}
int main()
{
	long unsigned int n;
	scanf("%lu",&n);
	printf("%lu\n",recurse(n));
}
