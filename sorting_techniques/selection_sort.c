#include <stdio.h>
void selection_sort(int arr[], int size)
{
	int i,j,min;

	for(i=0; i<size-1;i++)
	{
		min = i; //assume i is minimum value
		
		for(j=i+1;j<size;j++) 	// find actual minimum value
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}

			if(min != i)
			{
				int t = arr[i];
				arr[i] = arr[min];
				arr[min] = t;
			}
		}
	}
}
void print(int arr[], int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int array[5]={1,3,2,5,4};
	int s = sizeof(array) / sizeof(array[0]);
	printf("size of array :%d\n",s);
	print(array,s);
	selection_sort(array,s);
	print(array,s);
}

