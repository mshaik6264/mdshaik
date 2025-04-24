#include <stdio.h>

char *my_strcpy(char *dest, const char *src)
{
	if(*dest =='\0' && *src  == '\0') return NULL;

	while(*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return dest;
}

int main()
{
	char s1[20],s2[20];
	printf("Enter the string\n");
	scanf("%s",s1);
	printf("After copy s1 to s2\n");
	my_strcpy(s2, s1);
	printf("s2:%s\n",s2);

	return 0;
}

