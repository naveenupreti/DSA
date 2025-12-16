//A non-recursive program for binary search:
# include <stdio.h>

//function prototype
void binarySearchIteration(int[],int,int,int,int); 

int number[5];//global declaration of array

//Function definition
void binarySearchIteration(int number[], int size, int low, int high, int data)
{
	int mid,flag=0;
	while(low <= high)
	{
		mid = (low + high)/2;
		if(number[mid] == data)
		{
			flag = 1;
			break;
		}
		else
		{
			if(data < number[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	if(flag == 1)
		printf("\n %d found at location: %d", data, mid + 1);
	else
		printf("\n %d Not Found",data);
}

void main()
{
	int size, data, i, low, high;
	printf("\n Enter the number of elements: ");
	scanf("%d", &size);
	printf("\n Enter the elements in ascending order: ");
	for(i = 0; i < size; i++)
		scanf("%d", &number[i]);
	printf("\n Enter the element to be searched: ");
	scanf("%d", &data);
	low = 0; high = size-1;
	//function calling
	binarySearchIteration(number,size,low,high,data); 
}