#include "headers.h"

typedef struct message
{
	int mtype;
	char mdata[30];
}mq;

mq send_data, recv_data;

int main()
{
	pid_t pid;

	int msgid;

	msgid = msgget(10, IPC_CREAT | 0666);
	if(msgid < 0)
	{
		perror("msgget");
		printf("line:%d\n",__LINE__);
		exit(1);
	}

	pid = fork();
	if(pid == 0)
	{
		
		send_data.mtype = 1;
		strncpy(send_data.mdata, "MohammadShaik", strlen("MohammadShaik"));
		if(msgsnd(msgid, &send_data, sizeof(send_data.mdata), 0) == -1)
		{
			perror("msgsnd");
		}
		else
		printf("send data to Queue:%s\n",send_data.mdata);
		//system("ipcs");
	}
	else
	{
		sleep(1);
		//printf("Parent process reading data from queue\n");
		if(msgrcv(msgid, &recv_data, sizeof(recv_data.mdata), 1, 0) == -1)
		{
			perror("msgrecv");
		}
		else
		{
		printf("Received Data from Queue is:%s\n",recv_data.mdata);
		}
		//system("ipcs");
	}
	msgctl(msgid, IPC_RMID, NULL);

	return 0;
}
