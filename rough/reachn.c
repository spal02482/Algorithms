#include<stdio.h>
#include<stdio.h>
int fact(int x)
{
        if(x==1)
		return 1;
	else if(x>1)
		return x*fact(x-1);
	return 1;
}
int main()
{
	//printf("Enter a Number\n");
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		long long int som=0;
		scanf("%d",&n);
		for(int i=0;i<=n/2;i++)
		{
			som+=fact(n-i)/(fact(i)*fact(n-2*i));
		}
		printf("%lld\n",som);
	}
}
