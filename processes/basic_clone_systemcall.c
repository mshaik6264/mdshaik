#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
#include <signal.h>

int my(int n)
{
	printf("i am from child function :%d ......................\n",n);
}
int main()
{
	pid_t p1;
	int *st,k=9;
	st = (int *)malloc(2000)+1000;

	p1 = clone(my(k), st, SIGCHLD, NULL);

	if(p1 < 0)
	{
		perror("error in fork\n");
	}
	printf("Before child ................\n");
	if(p1 == 0)
	{
		printf("I am in child\n");
	}
	else
	{
		printf("I am from parent\n");
	}

	return 0;
}

