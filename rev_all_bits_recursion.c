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

int rev_bits(uint32_t num,int i)
{
	static int result=0;
	if(i>=32) return result;

		result <<=1;
		result |= (num & 1);
		num >>=1;

	rev_bits(num,i+1);

}
// another methode to aproach
int rev_bits_2(uint32_t num,int i, int j)
{

	if(i>=j) return num;

		if(((num>>i)&1) != ((num>>j)&1))
		{
			num ^= (1<<i);
			num ^= (1<<j);
		}

	rev_bits_2(num, i+1, j-1);
}

int main()
{
	int num = 15;
	int i=0,j=31;
	print(num);
	num = rev_bits(num,i);
	//num = rev_bits_2(num,i,j);
	printf("After reverse\n");
	print(num);

	return 0;

}
