#include <stdio.h>
void check_stack_direction()
{
	volatile int a, b;
	printf("Address of a:%p\n",(void *)&a);
	printf("Address of b:%p\n",(void *)&b);
	if(&b > &a)
	{
		printf("stack is growing upward\n");
	}
	else
	{
		printf("stack is growing downward\n");
	}

	return;
}
int main()
{
	check_stack_direction();

	return 0;
}


