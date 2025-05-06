#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define file_path "my_fifo"
int main()
{
	int ft;
	char wbuf[]="MohammadShaik from Mirafra Soft";
	char rbuf[50];
	pid_t pid;
	mkfifo(file_path, 0777);
	pid = fork();
	if(pid > 0)
	{
		//inside the parent process //

	ft = open(file_path, O_WRONLY);
	write(ft, wbuf, strlen(wbuf)+1);
	printf("write done is:%s\n",wbuf);
	close(ft);
	}
	else if(pid == 0)
	{
		//inside child process //

	ft = open(file_path, O_RDONLY);
	read(ft, rbuf, sizeof(rbuf));
	printf("Read the data is:%s\n",rbuf);
	close(ft);
	}
	return 0;
}
	
