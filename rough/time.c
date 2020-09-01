#include<stdio.h>
#include<time.h>
int main()
{
	time_t a;
	a=time(0);
	printf("%s",ctime(&a));
	return 0;
}
