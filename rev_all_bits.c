#include <stdio.h>
#include <stdint.h>

void print(uint32_t num)
{
	for(int i=31;i>=0;i--)
	{
		printf("%d",(num>>i)&1);
	
	if(i%8==0)	printf(" ");
	}
	printf("\n");
}

int rev_bits(uint32_t num)
{
	int result=0;
	for (int i=0; i<32; i++)
	{
		result <<=1;
		result |= (num & 1);
		num >>=1;
	}
	return result;
}
// another methode to aproach
int rev_bits_2(uint32_t num)
{
	for(int i=0,j=31;i<j;i++,j--)
	{
		if(((num>>i)&1) != ((num>>j)&1))
		{
			num ^= (1<<i);
			num ^= (1<<j);
		}
	}
	return num;
}

int main()
{
	int num = 15;
	print(num);
	num = rev_bits_2(num);
	printf("After reverse\n");
	print(num);

	return 0;

}
