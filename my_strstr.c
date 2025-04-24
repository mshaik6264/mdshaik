#include <stdio.h>
#include <string.h>

char *my_strstr(const char *str, const char *substr)
{
	//if(*substr == '\0') return (char *)str;

	while(*str != '\0')
	{
		const char *m = str;
		const char *s = substr;

		while(*m != '\0' && *s != '\0' && *m == *s)
		{
			m++;
			s++;
		}
		if(*s == '\0') return (char *)str;

		str++;
	}
	return NULL;
}

int main()
{
	char s1[25],s2[15];
	printf("Enter string\n");
	fgets(s1, sizeof(s1),stdin);
	//scanf("%s",s1);
	printf("Enter the substring\n");
	scanf("%s",s2);

	if(my_strstr(s1, s2))
	{
		puts("found");
	}
	else
		puts("not found");

	return 0;

}
