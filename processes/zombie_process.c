#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	pid_t pid;
	pid = fork();

	if(pid == 0)
	{
		printf("I am in child process\n");
		printf("Child processID:%d\n",getpid());
		printf("Child parentsID:%d\n",getppid());
	}
	else
	{
		getchar();
		printf("I am in parent process\n");
		printf("Parent procesID:%d\n",getpid());
		printf("Parent(shel ID):%d\n",getppid());
	}

	return 0;
}
