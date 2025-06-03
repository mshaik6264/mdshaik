#include <stdio.h>
#include <string.h>
void revstr(char *str)
{
	int start = 0;
	int end = strlen(str) - 1;
	for(;start<end;start++,end--)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
	}
}
void revstr_reccursion(char *str,int x, int y)
{
	if(x >= y)
	{
		printf("returning from recusion\n");
		return;
	}
	char t = str[x];
	str[x] = str[y];
	str[y] = t;

	revstr_reccursion(str,x+1,y-1);
	
}
int main()
{
	char buf[]="MohammadShaik";
	int s = 0,e = strlen(buf)-1;
	revstr_reccursion(buf,s,e);
	printf("%s\n",buf);
}
