#include <stdio.h>
#include <string.h>

char *my_strchr(const char *str, char ch)
{
	while(*str != '\0')
	{
		if(*str == ch) return (char *)str;
		str++;
	}
	if(ch == '\0') return (char *)str;

	return NULL;
}

int main()
{
	char s1[20]={0},c;
	printf("enter the string\n");
	scanf("%s",s1);
	printf("enter char to search\n");
	scanf(" %c",&c);
	if(my_strchr(s1,c))
	{
		printf("present\n");
	}
	else
		printf("Not present\n");

	return 0;
}
