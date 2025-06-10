#include <stdio.h>
void insertion_sort(int arr[], int size)
{
	for(int i=1; i<size; i++)
	{
		int  key = arr[i], j = i - 1;
		while(j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	printf("Sorted Array: ");
	for(int i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
int main()
{
	int a[5]={2,4,1,3,5};
	insertion_sort(a,5);

	return 0;
}
