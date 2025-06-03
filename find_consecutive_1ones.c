#include <stdio.h>
#include <stdint.h>

int is_consecutive(uint32_t num)
{
	int prev,next;
	while(num > 0)
	{
		prev = (num & 1);
		num >>= 1;
		next = (num & 1);
		if (prev == 1 && next == 1)
		{
			return 1;
		}
	}
	return 0;
}
void print(uint32_t n)
{
	for(int i=31;i>=0;i--)
	{
		printf("%d",(n>>i)&1);
		if(i%8==0) printf(" ");
	}
	printf("\n");
}

int main()
{
	int num;
	while(1)
	{
	printf("enter the number:");
	scanf("%d",&num);
	print(num);
	int s = is_consecutive(num);
	if(s)
	{
		printf("yes\n");
	}
	else
	printf("No\n");

	}
}


