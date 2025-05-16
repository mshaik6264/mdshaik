#include "my_headers.h"

#include <signal.h>

#define PORT 8080
void handler_int(int signum)
{
	printf("\r\nsignal interrupt occurs\n");
	exit(0);
}

int main()
{
	int server_fd,new_socket;
	
	signal(SIGINT,handler_int);

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_fd < 0)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PORT);
	int len_addr = sizeof(server_addr);

	if(bind(server_fd, (struct sockaddr *)&server_addr, len_addr) < 0)
	{
		perror("bind");
		return -1;
	}
	listen(server_fd, 3);
	printf("listening on PortNumber:%d\n",PORT);
	//now going for accept
	
	new_socket = accept(server_fd, (struct sockaddr *)&server_addr, (socklen_t*)&len_addr);
	if(new_socket < 0)
	{
		perror("accept");
		return -1;
	}
	char smsg[]="Request Acknowledge";
	char rmsg[50]={0};
	while(1)
	{
	printf("waiting for the request from client\n");
	int recvbyte = recv(new_socket, rmsg, sizeof(rmsg), 0);
	if(recvbyte <=0) break;
	if(strncmp(rmsg,"exit",4)==0) break;

	printf("client Data:%s\n",rmsg);
	send(new_socket, smsg, sizeof(smsg), 0);

	}
	close(server_fd);
	close(new_socket);
	printf("closing connection\n");
	return 0;
}
	

