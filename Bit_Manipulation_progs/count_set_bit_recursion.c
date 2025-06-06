#include <stdio.h>
int cnt_set_bits(int num)
{
	static int cnt = 0;
	if(num <= 0)
	{
		return cnt;
	}
	cnt += num & 1;
	num >>= 1;
	cnt_set_bits(num);
}
int main()
{
	int n;
	printf("Enter the number : ");
	scanf("%d",&n);
	printf("No of Set Bits are:%d\n",cnt_set_bits(n));

	return 0;
}	
