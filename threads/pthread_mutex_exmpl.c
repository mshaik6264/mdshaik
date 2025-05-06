
#include <pthread.h>
#include <stdio.h>

int i = 0;
pthread_mutex_t lock;

void* t1(void* arg)
{
	pthread_mutex_lock(&lock);
	i = 0;
	i++;
	i--;
	pthread_mutex_unlock(&lock);
	return NULL;
}

void* t2(void* arg)
{
	pthread_mutex_lock(&lock);
	++i;
	i--;
	i += 5;
	pthread_mutex_unlock(&lock);
	return NULL;
}

int main()
{
	pthread_t thread1, thread2;
	pthread_mutex_init(&lock, NULL);

	pthread_create(&thread1, NULL, t1, NULL);
	pthread_create(&thread2, NULL, t2, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Final value of i: %d\n", i);

	pthread_mutex_destroy(&lock);
	return 0;
}

