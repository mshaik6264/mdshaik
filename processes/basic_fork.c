#include <stdio.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	pid = fork();
	
	if(pid == 0)
	{
		printf("i am in child processes\n");
		printf("child processes ID:%d\n",getpid());
		printf("child parents	ID:%d\n",getppid());
	}
	else
	{
		printf("i am in parent processes\n");
		printf("parent processesID:%d\n",getpid());
		printf("parentID (shel id):%d\n",getppid());
	}
	return 0;
}
