#include <stdio.h>

char *my_strcat(char *dest, const char *src)
{
	char *ptr = dest;
	while(*ptr != '\0')
	{
		ptr++;
	}
	while(*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return dest;
}

int main()
{
	char s1[25]={0},s2[10]={0};
	printf("Enter main str\n");
	scanf("%s",s1);
	printf("Enter the sub str\n");
	scanf("%s",s2);
	printf("After concatenate\n");
	my_strcat(s1,s2);
	printf("%s\n",s1);

	return 0;
}
