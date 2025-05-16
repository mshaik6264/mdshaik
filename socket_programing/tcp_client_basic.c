#include "my_headers.h"
//for client

#define PORT 8080

int main(int argc, char *argv[])
{
	if(argc == 3 || argc == 1)
	{
		printf("Usage:->  ./a.out space IP Address \n");
		return -1;
	}

	int client_fd=0;
	struct sockaddr_in client_addr;

	client_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(client_fd < 0)
	{
		perror("socket");
		return 1;
	}

	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = inet_addr(argv[1]);
	printf("IP Addr: %s\n",argv[1]);
	client_addr.sin_port = htons(PORT);

	if(connect(client_fd,(struct sockaddr *)&client_addr,sizeof(client_addr)) < 0)
	{
		perror("connect");
		return -1;
	}
	char smsg[50]={0};//"This is Shaik from client";
	char rmsg[50]={0};
	while(1)
	{
	printf("if you want to disconnect type: exit\n");
	printf("Enter the data to sent to the server\n");
	fgets(smsg, 49, stdin);
	//scanf("%s",smsg);

	if(strncmp(smsg,"exit",4)==0) break;

	int sendbyte = send(client_fd, smsg, sizeof(smsg), 0);

	if(sendbyte <=0) break;

	recv(client_fd, rmsg, sizeof(rmsg), 0);
	printf("Response Data:%s\n",rmsg);

	}
	close(client_fd);
	printf("Disconnecting from server\n");
	return 0;
}



	
