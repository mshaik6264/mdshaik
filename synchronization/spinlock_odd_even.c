#include <stdio.h>
#include <pthread.h>

volatile int odd_lock=0, even_lock=0;
int turn = 1; // 1 for odd and 2 for even
static int cnt = 1;

void spin_lock(volatile int *lock)
{
	while(__sync_lock_test_and_set(lock,1))
	{
		//busy : wait;
	}
}
void spin_unlock(volatile int *lock)
{
	__sync_lock_release(lock);
}

void *odd_task(void *args)
{
	while(1)
	{

		spin_lock(&odd_lock);
		if( cnt > 10)
		{
			spin_unlock(&odd_lock);
			return NULL;
		}

		if(cnt % 2 == 1) 
		{
			printf("odd:%d\n",cnt);
			cnt++;
		}
		spin_unlock(&odd_lock);
	}

	return NULL;
}
void *even_task(void *args)
{
	while(1)
	{
		spin_lock(&odd_lock);
		if(cnt > 10)
		{
			spin_unlock(&odd_lock);
			return NULL;
		}
		if(cnt % 2 == 0)
		{	
			printf("even:%d\n",cnt);
			cnt++;
		}
		spin_unlock(&odd_lock);
		
	}
	return NULL;
}

int main()
{
	pthread_t t1,t2;

	pthread_create(&t1, NULL, odd_task, NULL);
	pthread_create(&t2, NULL, even_task, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return 0;
}

