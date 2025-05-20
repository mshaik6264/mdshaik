#include <stdio.h>
int main()
{
	int arry[2]={1,2};
	printf("Difference: %ld\n",(&arry[1] - &arry[0]));

	if(&arry[1] - &arry[0] < 0)
	{
		printf("stack is upward\n");
	}
	else
	{
		printf("stack is downward\n");
	}
	return 0;
}
