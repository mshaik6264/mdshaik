#include "my_headers.h"

#include <signal.h>

#define PORT 8080
void handler_int(int signum)
{
	printf("\r\nsignal interrupt occurs\n");
	exit(0);
}

char buf[][50]=
{
	"my name is Mohammad Shaik",
	"i am a boy",
	"Mirafra Soft Technologies",
	"Punjagutta Hyderabad",
	"EMP 6264",
	"Software Engineer II"
};

int main()
{
	int server_fd;
	
	signal(SIGINT,handler_int);

	server_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(server_fd < 0)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in server_addr , client_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PORT);
	int len_addr = sizeof(server_addr);

	if(bind(server_fd, (struct sockaddr *)&server_addr, len_addr) < 0)
	{
		perror("bind");
		return -1;
	}
	char smsg[50]={0};
	char rmsg[50]={0};
	int client_len = sizeof(client_addr);
	while(1)
	{
	printf("waiting for the request from client\n");
	recvfrom(server_fd, rmsg, sizeof(rmsg), 0, (struct sockaddr *)&client_addr, &client_len);
	
	if(strncmp(rmsg,"exit",4)==0) break;
	if(strstr(rmsg,"name"))
	{
		strcpy(smsg,buf[0]);
	}
	else if(strstr(rmsg,"gender"))
	{
		strcpy(smsg,buf[1]);
	}
	else if(strstr(rmsg,"company"))
	{
		strcpy(smsg,buf[2]);
	}
	else if(strstr(rmsg,"address"))
	{
		strcpy(smsg,buf[3]);
	}
	else if(strstr(rmsg,"id"))
	{
		strcpy(smsg,buf[4]);
	}
	else if(strstr(rmsg,"designation"))
	{
		strcpy(smsg,buf[5]);
	}

	printf("client Data:%s\n",rmsg);
	sendto(server_fd, smsg, sizeof(smsg), 0, (struct sockaddr *)&client_addr, client_len);
	memset(smsg,0,sizeof(smsg));

	}
	close(server_fd);
	printf("closing connection\n");
	return 0;
}
	

