#include<stdio.h>
#include<stdint.h>
void check_endians(uint32_t num)	
{
	if((char)num & 1 )
	{
		printf("Little Endians\n");
	}
	else
	{
		printf("Big Endians\n");
	}
	return;
}
int change_endians(uint32_t num)
{
	return ((num & 0xff000000)>>24 | (num & 0x000000ff)<<24 | (num & 0x00ff0000)>>8 | (num & 0x0000ff00)<<8);
}
int main()
{
	uint32_t x=0x01;
	check_endians(x);
	printf("After change endians\n");
	x = change_endians(x);
	check_endians(x);
	return 0;
}
