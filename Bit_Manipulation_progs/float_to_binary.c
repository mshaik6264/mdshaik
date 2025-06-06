#include <stdio.h>
#include <stdint.h>

long int float_to_int(float num)
{
	union 
	{
		float f;
		uint32_t u;
	}cnvrt;

	cnvrt.f = num;
	long int bin = 0;
	int mulp = 1;
	for(int i=31;i>=0;i--)
	{
		printf("%d",(cnvrt.u>>i)&1);
		if(i == 31 || i == 23) printf(" ");
		bin = bin + ((cnvrt.u >> i)&1) * mulp;
		mulp *= 10;
	}
	printf("\n");
	return bin;
}
int main()
{
	float n;
	printf("Enter the float number to print in binary: ");
	scanf("%f",&n);
	long int b = float_to_int(n);
	printf("float binary stored value: %ld\n",b);

	return 0;
}
