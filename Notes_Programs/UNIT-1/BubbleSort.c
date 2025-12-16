// C program for implementation of Bubble sort
#include <stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j,temp;
   for (i = 0; i < n-1; i++)
   {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                //swap(&arr[j], &arr[j+1]);
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
              }
              printf("\ni=%d,j=%d\n",i,j);
              printArray(arr, n);
        }

   }

}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {20,10,30,40,50};
	//int arr[] = {50,40,30,20,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: \n");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
/*
Unsorted array:
20 10 30 40 50

i=0,j=0
10 20 30 40 50

i=0,j=1
10 20 30 40 50

i=0,j=2
10 20 30 40 50

i=0,j=3
10 20 30 40 50

i=1,j=0
10 20 30 40 50

i=1,j=1
10 20 30 40 50

i=1,j=2
10 20 30 40 50

i=2,j=0
10 20 30 40 50

i=2,j=1
10 20 30 40 50

i=3,j=0
10 20 30 40 50
Sorted array:
10 20 30 40 50
*/
