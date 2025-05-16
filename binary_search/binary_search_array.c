#include<stdio.h>
void print(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

int binarysearch(int array[], int size, int val)
{
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	printf("sorted:");
	print(array,size);

       int l = 0, r = size - 1;
       while(l <= r)
       {
	       int mid = l + (r - l)/2;
	       if(val == array[mid])
	       {
		       return mid;
	       }
	       else if(val < array[mid])
	       {
		       r = mid - 1;
	       }
	       else if(val > array[mid])
	       {
		      l = mid + 1;
	       } 
       }
	return -1;       
}
int main()
{
	int a[5];
	int s = sizeof(a) / sizeof(a[0]);
	int v;
#if 1
	printf("enter the values of 5 items\n");
	for(int i=0;i<s;i++)
	{
		printf("Enter item:%d\n",i+1);
		scanf("%d",&a[i]);
	}
#endif
	print(a,s);

	printf("Enter the value to search\n");
	scanf("%d",&v);

	int res = binarysearch(a,s,v);
	if(res != -1)
	{
		printf("value is found at index : %d\n",res);
	}
	else
	{
		printf("value is not found\n");
	}
}


