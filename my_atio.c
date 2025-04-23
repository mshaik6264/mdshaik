#include <stdio.h>

int my_atoi(const char *str)
{
	int result = 0, sign = 1;
	while(*str == ' ' && *str == '\t')
	{
		str++;
	}
	if(*str == '-')
	{
		sign = -1;
		str++;
	}
	else if(*str == '+')
	{
		str++;
	}
	while(*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return sign * result;
}
int main()
{
	char buf[25]={0};
	printf("Enter the strings\n");
	scanf("%s",buf);
	int rs=my_atoi(buf);
	printf("%d\n",rs);
	return 0;
}
