#include <stdio.h>
#include <stdint.h>
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
	int num,i,j;
	printf("Enter the number:\n");
	scanf("%d",&num);
	print(num);
	printf("enter ith and jth position to set bits in int\n");
	scanf("%d%d",&i,&j);
	num |=((1<<(j-i)+1) -1)<<i;
	print(num);
}
