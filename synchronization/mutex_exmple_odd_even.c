#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
pthread_cond_t cond;

int cnt = 1;

void *odd(void *params)
{
	while(cnt <= 10)
	{
		pthread_mutex_lock(&lock);

		if(cnt % 2 != 0)
		{
			printf("odd number: %d\n",cnt);
			pthread_cond_signal(&cond);
			cnt++;
		}
		else
		{
			pthread_cond_wait(&cond, &lock);
		}
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

void *even(void *params)
{
	while(cnt <= 10)
	{
		pthread_mutex_lock(&lock);
		
		if(cnt % 2 == 0)
		{
			printf("evn number: %d\n",cnt);
			pthread_cond_signal(&cond);
			cnt++;
		}
		else
		{
			pthread_cond_wait(&cond, &lock);
		}
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}
int main()
{
	pthread_t thread1, thread2;
	
	pthread_mutex_init(&lock,NULL);
	pthread_cond_init(&cond, NULL);

	pthread_create(&thread1, NULL, odd, NULL);
	pthread_create(&thread2, NULL, even,NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&cond);

	return 0;

}
	



