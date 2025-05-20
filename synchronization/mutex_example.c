#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

void *task1(void *arg)
{
	pthread_mutex_lock(&mutex);
	printf("task 1 is Running\n");
	sleep(1);
	pthread_mutex_unlock(&mutex);
	return NULL;
}

void *task2(void *arg)
{
	pthread_mutex_lock(&mutex);
	printf("task 2 is Running\n");
	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main()
{
	pthread_t t1,t2;
	
	pthread_mutex_init(&mutex,NULL);

	pthread_create(&t1, NULL, task1, NULL);
	pthread_create(&t2, NULL, task2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	pthread_mutex_destroy(&mutex);

	return 0;
}
