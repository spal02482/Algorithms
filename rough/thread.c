#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
void *counter1(void *var)
{
	for(int i=0;i<7;i++)
	{
		printf("Thread 1: %d\n",i);
	//	sleep(500);
	}
	sleep(100);
	return NULL;
}
void *counter2(void *var)
{
	for(int i=0;i<7;i++)
	{
		printf("Thread 2: %d\n",i);
	//	sleep(500);
	}
	sleep(100);
	return NULL;
}
int main()
{
	pthread_t id1,id2;
	pthread_create(&id1,NULL,counter1,NULL);
	pthread_create(&id2,NULL,counter2,NULL);
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	pthread_exit(NULL);
	return 0;


}

