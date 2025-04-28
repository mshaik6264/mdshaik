#include<stdio.h>
void *my_memcpy(void *dest,const void *src, int n)
{
	unsigned char *d = (unsigned char *) dest;
	const unsigned char *s = (unsigned char *) src;
	for (int i=0;i<n;i++)
	{
		d[i] = s[i];
	}
	return dest;
}
int main()
{
	char str[50]={0};
	char s2[]="ahsan ahmed";
	printf("main str: %s\n",s2);
	my_memcpy(str,s2,5);
	//my_memcpy(str+5,'\0',1);
	printf("after cpy: %s\n",str);

}
