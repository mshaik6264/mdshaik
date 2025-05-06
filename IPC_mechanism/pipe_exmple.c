#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int fd[2];
	pid_t pid;
	char wmsg[]="Hello from Mshaik mirafra soft";
	char rmsg[50];

	if(pipe(fd) == -1)
	{
		printf("fails to create a pipe\n");
		return -1;
	}

	pid = fork();
	if(pid > 0)
	{
		//inside parent process//
		close(fd[0]);
		write(fd[1], wmsg, strlen(wmsg)+1);
		printf("Write data from Parent process is:%s\n",wmsg);
		close(fd[1]);
	}
	else if(pid == 0)
	{
		//inside child process//
		close(fd[1]);
		read(fd[0], rmsg, sizeof(rmsg));
		printf("Reads data from Child  process is:%s\n",rmsg);
		close(fd[0]);
	}
	return 0;
}
