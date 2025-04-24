#include <stdio.h>

int my_strcmp(const char *str1, const char *str2)
{
	while(*str1 && *str1 == *str2)
	{
		
		  str1++;
		  str2++;
	}
	return *(unsigned char *)str1 - *(unsigned char *)str2;
}
int main()
{
	char s1[20],s2[20];
	printf("Enter str1\n");
	scanf("%s",s1);
	printf("Enter str2\n");
	scanf("%s",s2);
	if(my_strcmp(s1,s2)==0)
	{
		printf("same\n");
	}
	else
	{
		printf("different\n");
	}

	return 0;
}
