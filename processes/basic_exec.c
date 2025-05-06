#include <stdio.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	pid_t pid;

	pid = fork();
#if 0
	if(argc >= 3)
	{
		printf("Invalid comand line argumnet !\n");
		return 0;
	}
#endif
	if(pid == 0)
	{
		printf("child process\n");
		execl("/bin/ps",argv[1],argv[2],(char *)0);
		printf("This wont print\n");
	}
	else
	{
		printf("parent process\n");
	}

	return 0;
}

