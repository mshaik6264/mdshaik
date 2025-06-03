#include <stdio.h>

void find_3rd_smallest(int a[], int s)
{
	int s1=a[0],s2=0,s3=0;
	for(int i=0; i<s; i++)
	{
		if(a[i] < s1)
		{
			s3 = s2;
			s2 = s1;
			s1 = a[i];
		}
		else if(a[i] < s2 && a[i] != s1)
		{
			s3 = s2;
			s2 = a[i];
		}
		else if(a[i] < s3 && a[i] != s2 && a[i] != s1)
		{
			s3 = a[i];
		}
	}
	printf("_1st smallest:%d\n",s1);
	printf("_2nd smallest:%d\n",s2);
	printf("_3rd smallest:%d\n",s3);
}
int main()
{
	int arr[5]={5,2,4,1,3};
	find_3rd_smallest(arr,5);

	return 0;
}

