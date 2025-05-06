#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define STACK_SIZE 1024*1024


int child_function(void *arg) 
{
	    printf("Hello from child process!\n");
	        return 0;
}

int main() 
{
	void *stack = malloc(STACK_SIZE);
	      	if (!stack) 
		{
		       	perror("malloc");
			exit(1);
		}

	pid_t pid = clone(child_function, stack + STACK_SIZE, SIGCHLD, NULL);
		if (pid == -1) 
		{
			perror("clone");
			exit(1);
		}
		printf("Child PID: %d\n", pid);
		wait(NULL);
		free(stack);

		return 0;
}

