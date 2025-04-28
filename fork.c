#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid = fork();
	if(pid < 0)
	{
		printf("fork fails to create\n");
	}
	else if(pid == 0)
		printf("chld :%d\n",getpid());
	else
		printf("parent id:%d  child id:%d\n",getpid(),pid);
}
