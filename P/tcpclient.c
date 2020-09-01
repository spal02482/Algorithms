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
	int sfd,mesg;
	char buffer[200];
	socklen_t size = (socklen_t)sizeof(struct sockaddr_in);
	struct sockaddr_in servaddr,cliaddr;
	if((sfd=socket(AF_INET,SOCK_STREAM,0))<0){
		perror("socket error: \n");
		exit(1);
	}
	else
		printf("socket created successfully...\n");
	bzero(&cliaddr,size);
	cliaddr.sin_family=AF_INET;
	cliaddr.sin_port=htons(1668);
	cliaddr.sin_addr.s_addr=INADDR_ANY;
	if(connect(sfd,(struct sockaddr *)&cliaddr,size)<0){
		perror("connect error : \n");
		exit(2);
	}
	else
		printf("connect successful...\n");
	do{
		mesg = recv(sfd,buffer,100,0);
		printf("%d\n",mesg);
		buffer[mesg]='\0';
		printf("string received is : %s\n",buffer);
		printf("Enter string : ");
		scanf("%s",buffer);
		printf("buffer %s\n",buffer);
		if(!strcmp(buffer,"exit")) break;
		send(sfd,buffer,100,0);
	}
	while(1);
	close(sfd);
	return 0;
}
