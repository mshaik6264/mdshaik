#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;
void *task(void *arg)
{
	sem_wait(&sem); // waiting (decreament semaphore)
	printf("Task %d is entered\n",*(int *)arg);
	sleep(3);
	printf("Task %d is leaved\n",*(int *)arg);
	sem_post(&sem); // signaled (increament semaphore)

	return NULL;
}
int main()
{
	pthread_t t4[4];
	int ids[4]={1,2,3,4};

	sem_init(&sem, 0, 2);  // initialising semaphore with only 2 permits
	
	for(int i=0;i<4;i++)
	{
		pthread_create(&t4[i], NULL, task, &ids[i]);
	}

	for(int i=0;i<4;i++)
	{
		pthread_join(t4[i], NULL);
	}
	sem_destroy(&sem);

	return 0;
}
	

