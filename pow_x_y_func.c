#include <stdio.h>

double my_pow(double x, int y)
{
	double result = 1.0;
	int exponent = y;

	if(y < 0)
	{
		x = 1/x;
		exponent = -y;
	}
	while(exponent > 0)
	{
		if(exponent % 2 == 1)
		{
			result *= x;
		}
		x *= x;
		exponent /= 2;
	}
	return result;
}
int main()
{
	double base = 2.0;
	int exp = 3;
	printf("Result:%.3f\n",my_pow(base, exp));

	return 0;
}
