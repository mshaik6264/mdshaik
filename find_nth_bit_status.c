#include <stdio.h>
#include <stdint.h>
void print(uint32_t num)
{
	for (int i=31;i>=0;i--)
	{
		printf("%d",(num>>i)&1);
		if(i%8==0)
			printf(" ");
	}
	printf("\n");
}
int is_set(int num, int bit)
{
	if((num >> bit)&1)
	{
		printf("Set bit\n");
	}else
		printf("Reset bit\n");

	return 0;
}

int main()
{
	int n,b;
	printf("Enter the number\n");
	scanf("%d",&n);
	print(n);
	printf("enter the bit position\n");
	scanf("%d",&b);
	is_set(n,b);

	return 0;
}
