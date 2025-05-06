#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

//bool eve = false;
//bool odd = false;
//
static int cnt;

pthread_mutex_t mutex;

void task1(void *params)
{
	pthread_mutex_lock(&mutex);
	cnt = 0;
	++cnt;
	cnt++;
	cnt--;
	pthread_mutex_unlock(&mutex);
	return NULL;
}
void task2(void *params)
{
	pthread_mutex_lock(&mutex);
	cnt++;
	--cnt;
	cnt--;
	cnt +=7;
	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main()
{
	pthread_t thread1,thread2;
	pthread_mutex_init(&mutex,NULL);
	
	pthread_creat(&thread1,NULL,task1,NULL);
	pthread_creat(&thread2,NULL,task2,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	printf("Final value of cntr:%d\n",cnt);

	pthread_mutex_destroy(&mutex);

	return 0;
}
		
	
