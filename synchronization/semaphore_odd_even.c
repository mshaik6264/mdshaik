#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem_odd, sem_even;
int cnt = 1;
void *odd_task(void *args)
{
	while(cnt <= 10)
	{
		sem_wait(&sem_odd);
		if(cnt <= 10 && cnt % 2 == 1)
		{
			printf("odd:%d\n",cnt);
			cnt++;
		}
		sem_post(&sem_even);
	}
	return NULL;
}

void *even_task(void *args)
{
	while(cnt <= 10)
	{
		sem_wait(&sem_even);
		if(cnt <= 10 && cnt % 2 == 0)
		{
			printf("even:%d\n",cnt);
			cnt++;
		}
		sem_post(&sem_odd);
	}
	return NULL;
}
int main()
{
	pthread_t t1,t2;
	sem_init(&sem_odd, 0, 1);
	sem_init(&sem_even, 0, 0);
	
	pthread_create(&t1, NULL, odd_task, NULL);
	pthread_create(&t2, NULL, even_task, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	sem_destroy(&sem_odd);
	sem_destroy(&sem_even);

	return 0;
}

