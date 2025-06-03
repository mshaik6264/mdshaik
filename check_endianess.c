#include <stdio.h>
#include <stdint.h>
union abc
{
	uint32_t t;
	uint8_t ch[4];
}test_union;
//methode 1: use a union
void by_union()
{
	test_union.t = 0x01020304;
	if(test_union.ch[0] == 0x04)
	{
		printf("%s:Little Endians\n",__func__);
	}
	else if(test_union.ch[0] == 0x01)
	{
		printf("%s:Big Endians\n",__func__);
	}
}

// methode 2: Inspect first byte of a multi-byte Variable
void by_addressVariable()
{
	uint32_t var = 0x01020304;
	uint8_t *ptr = (uint8_t *)&var;
	if( ptr[0] == 0x04)  // cast the address of var into a uint8_t pointer then dereference //
	{
		printf("%s:Little Endians\n",__func__);
	}
	else
	{	
		printf("%s:Big Endians\n",__func__);
	}
}

// methode 3: Runtime Comparison with a known byte pattern 
void by_first_byte()
{
	uint32_t val = 1;
	if(*(char *)&val == 1)
	{
		printf("%s:Little Endians\n",__func__);
	}
	else 
	{
		printf("%s:Big Endians\n",__func__);
	}
}

int main()
{
	by_union();
	by_addressVariable();
	by_first_byte();
	return 0;
}
