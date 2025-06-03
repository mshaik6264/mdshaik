#include <stdio.h>
int is_prime(int num)
{
	if(num < 2) return 0;
	if(num == 2) return 1;
	for(int i=2; i*i<=num; i++)
	{
		if(num % i == 0) return 0;
	}
	return 1;
}
int main()
{
	int num = 3571;
	int n = 1;
	while(n < num)
	{
		n *= 10;
		int temp = num;
		while(temp)
		{
			if(temp>(n/10) && is_prime(temp%n))
			{
				printf("possible prime numbers are:%d\n",temp%n);
			}
			temp /= n;
		}
	}
	return 0;
}
