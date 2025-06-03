#include <stdio.h>
#include <limits.h>

int find_3rd_largest(int a[],int size)
{
	int l1 = 0, l2 = 0, l3 = 0;
	for(int i=0;i<size;i++)
	{
		if(a[i] > l1)
		{
			l3 = l2;
			l2 = l1;
			l1 = a[i];
		}
		else if(a[i] > l2 && a[i] != l1)
		{
			l3 = l2;
			l2 = a[i];
		}
		else if(a[i] > l3 && a[i] != l2 && a[i] != l1)
		{
			l3 = a[i];
		}
	}
	printf("_1st largest:%d\n",l1);
	printf("_2nd largest:%d\n",l2);
	printf("_3rd_largest:%d\n",l3);
	return 1;
}
int main()
{
	int ar[5]={5,1,3,2,5};
	find_3rd_largest(ar, 5);

	//printf("INT_MIN : %d\n",INT_MIN);
	return 0;
}
