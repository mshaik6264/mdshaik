#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

volatile int lock = 0;

void spin_lock(volatile int *lock)
{
	while(__sync_lock_test_and_set(lock,1))
	{
		// busy - wait
	}
}
void spin_unlock(volatile int *lock)
{
	__sync_lock_release(lock);
}

void *task(void *arg)
{
	spin_lock(&lock);
	printf("task %d is in critical section\n",*(int *)arg);
	// do some quick work
	
	spin_unlock(&lock);
	return NULL;
}

int main()
{
	int id = 1;
	pthread_t t;
	pthread_create(&t, NULL, task, &id);
	pthread_join(t, NULL);

	return 0;
}
