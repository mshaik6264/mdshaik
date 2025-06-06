#include <stdio.h>
int max_rep_elem(int arr[],int size)
{
	int count = 0, max = 0, max1 = 0;
	for(int i=0;i<size;i++)
	{
		for(int j=1;j<size;j++)
		{
			if(arr[i] == arr[j])
			{
				count++;
			}
		}
		if(count >= max)
		{
			max = count;
			max1 = arr[i];
			count = 0;
		}
	}
	return max1;
}
int main()
{
	int a[5] = {1,2,3,4,4};
	//printf("max repeat element:%d\n",max_rep_elem(a,5));
	int (*func)(int*,int) = NULL;
	func = &max_rep_elem;
	printf("max:%d\n",func(a,5));
}
