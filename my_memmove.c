#include<stdio.h>
#include<stdint.h>

void *my_memmove(void *dest, const void *src, int n)
{
	uint8_t *d = (uint8_t *)dest;
	const uint8_t  *s = (uint8_t *)src;

	if(d < s)
	{
		for(int i=0;i<n;i++)
			d[i] = s[i];
	}
	else
	{
		for(int i=n;i>0;i--)
			d[i-1] = s[i-1];
	}
	return dest;
}
int main()
{
	uint8_t s[25]="abcdefsg";
	char s2[25]={0};
	printf("org:%s\n",s);
	my_memmove(s+3,s,5);
	printf("After:%s\n",s);
}
