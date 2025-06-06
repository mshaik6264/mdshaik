#include <stdio.h>
#include <stdint.h>

int int_to_bin(int num)
{
	int bin = 0;
	int multiplier = 1;
	while(num)
	{
		bin = bin + (num & 1) * multiplier;
		multiplier *= 10;
		num >>= 1;
	}
	return bin;
}
int main()
{
	int n;
	printf("Enter the integer number: ");
	scanf("%d",&n);
	printf("in Bin : %d\n",int_to_bin(n));

	return 0;
}
