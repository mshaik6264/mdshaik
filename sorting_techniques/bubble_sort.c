#include <stdio.h>

void bubble_sort(int arr[],int size)
{
	for(int i=1; i<size ;i++)
	{
		for(int j=1;j < size-i ;j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
	
		}
	}	
}
void print(int arr[],int size)
{
	for(int i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int main()
{
	int a[5]={1,3,2,5,4};
	print(a,5);
	bubble_sort(a,5);
	print(a,5);
}
