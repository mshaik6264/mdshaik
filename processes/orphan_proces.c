#include <stdio.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	pid = fork();
	
	if(pid == 0)
	{
		sleep(5);
		printf("i am in child processes\n");
		printf("child processes ID:%d\n",getpid());
		printf("child parents	ID:%d\n",getppid());
	}
	else
	{
		printf("i am in parent processes\n");
		printf("parent porcesses	 ID:%d\n",getpid());
		printf("parents parent ID(shell id):%d\n",getppid());
	}
	return 0;
}
