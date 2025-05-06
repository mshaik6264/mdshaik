
#include "headers.h"

#define IS_WRITE 1
#define IS_READ 0

int main()
{
	int fd;
	char wbuf[30];
	char rbuf[30];
	mkfifo("temp_fifo", 0777);
#if IS_WRITE
	fd = open("temp_fifo", O_RDWR);
	printf("Enter data to write\n");
	scanf("%s",wbuf);
	write(fd, wbuf, strlen(wbuf)+1);
	printf("Write success now going to Read\n");
	read(fd, rbuf, sizeof(rbuf));
	printf("Read data is:%s\n",rbuf);

	close(fd);
#elif IS_READ
	fd = open("temp_fifo", O_RDONLY);
	read(fd, rbuf, sizeof(rbuf));
	printf("Read data from fifo is:%s\n",rbuf);
	close(fd);
#endif
	return 0;
}
