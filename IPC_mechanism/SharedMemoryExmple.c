#include "headers.h"
#include <sys/shm.h>

//define a srtucture to store a shared memory data
struct sm 
{
	char data[25]; //character array to store data
};

//Declare pointers to shared memory structure
struct sm *send_cmd,*recv_cmd;

int main()
{
	int shmid;
	//creat a shared memory segment with key=10 and size equal to struct sm
	//IPC_CREAT: creat the segment if it doesnt exits
	//0666: Read and write permission for user and group and others
	shmid = shmget(10, sizeof(struct sm), IPC_CREAT | 0666);
	if(shmid == -1)
	{
		perror("error"); //print error messages
		exit(1); //exit with error
	}
	//attach to the shared memory segment and assign to send_cmd pointer
	send_cmd = (struct sm *) shmat(shmid, 0, 0);
	//attach again to the same shared memory segment for reading (recv_cmd)
	recv_cmd = (struct sm *) shmat(shmid, 0, 0);

	//prompt the user to enter data to write into shared memory
	printf("Enter the data to write\n");
	scanf("%s",send_cmd->data);
	//Read and print the data from shared memory (through recv_cmd)
	//since both send_cmd and recv_cmd point to the same memory,
	//this will show what was written above
	printf("Received Data from SM:%s\n",recv_cmd->data);
	
	//Detach both pointers fron shared memory
	shmdt(send_cmd);
	shmdt(recv_cmd);

	//Mark the shared memory segment for deletion
	shmctl(shmid, IPC_RMID,0);

	return 0;
}

