#include <stdio.h>
#include <stdint.h>
union endian
{
	uint32_t num;
	uint8_t value[4];
};

int change_endians(uint32_t num)
{
	union endian original, reverse;
	original.num = num;
	reverse.value[0] = original.value[3];
	reverse.value[1] = original.value[2];
	reverse.value[2] = original.value[1];
	reverse.value[3] = original.value[0];

	return reverse.num;
}
int main()
{
	uint32_t number = 0x12345678;
	printf("After swap:%08x\n",change_endians(number));

	return 0;
}
