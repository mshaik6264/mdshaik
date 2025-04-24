#include <stdio.h>
#define MY_SIZEOF(x)  ((char *)(&x+1) - (char *)(&x))

int main()
{
	int x=2;
	char c='a';
	short d=2;
	printf("char : %ld\n",MY_SIZEOF(c));
	printf("short: %ld\n",MY_SIZEOF(d));
	printf("integ: %ld\n",MY_SIZEOF(x));

	return 0;
}
