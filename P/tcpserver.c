#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
int main(int argc,char **argv)
{
	char buffer[200];
	int sfd,afd,mesg;
	struct sockaddr_in servaddr,cliaddr;
	socklen_t size = (socklen_t)sizeof(struct sockaddr_in);
	if((sfd=socket(AF_INET,SOCK_STREAM,0))<0){
		perror("socket Error : ");
		exit(1);
	}
	else
		printf("socket created successfully...\n");
	bzero(&servaddr,size);
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(1668);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	if(bind(sfd,(struct sockaddr * )&servaddr,size)<0){
		perror("bind failed : \n");
		exit(2);
	}
	else
		printf("bind successfull...\n");
	if(listen(sfd,2)<0){
		perror("listen error : \n");
		exit(3);
	}
	else
		printf("listen successfull...\n");
	if((afd=accept(sfd,(struct sockaddr *)&servaddr,&size))<0){
		printf("accept error...\n");
		exit(4);
	}
	printf("accept successfull...\n");
	do{
		printf("Enter string : ");
		scanf("%s",buffer);
		if(!strcmp(buffer,"exit")) break;
		send(afd,buffer,100,0);
		mesg = recv(afd,buffer,100,0);
		buffer[mesg]='\0';
		printf("string received is : %s\n",buffer);
	}
	while(1);
	close(sfd);
	close(afd);
	return 0;
}

