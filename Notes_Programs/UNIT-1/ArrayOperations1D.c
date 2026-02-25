// -------------------------------------------------------------
// Array Operations in C
// Operations: Create, Traverse, Insert, Delete, Update,
//             Sort (Bubble Sort), Search
// -------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function Prototypes
void createArray(int arr[], int *size);
void traverseArray(int arr[], int size);
void insertInArray(int arr[], int *size);
void deleteInArray(int arr[], int *size);
void updateArray(int arr[], int size);
void sortArray(int arr[], int size);
void searchArray(int arr[], int size);

int main()
{
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    do
    {
        printf("\n========== ARRAY OPERATIONS ==========\n");
        printf("1. Create Array\n");
        printf("2. Traverse Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Update Element\n");
        printf("6. Sort Array\n");
        printf("7. Search Element\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createArray(arr, &size);
                break;

            case 2:
                traverseArray(arr, size);
                break;

            case 3:
                insertInArray(arr, &size);
                break;

            case 4:
                deleteInArray(arr, &size);
                break;

            case 5:
                updateArray(arr, size);
                break;

            case 6:
                sortArray(arr, size);
                break;

            case 7:
                searchArray(arr, size);
                break;

            case 8:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 8);

    return 0;
}

// -------------------------------------------------------------
// Function to Create Array (Input until -1 is entered)
// -------------------------------------------------------------
void createArray(int arr[], int *size)
{
    int num;
    *size = 0;   // Reset size

    printf("Enter elements (-1 to stop):\n");

    while(*size < MAX_SIZE)
    {
        scanf("%d", &num);

        if(num == -1)
            break;

        arr[*size] = num;
        (*size)++;
    }

    printf("Array created successfully. Total elements = %d\n", *size);
}

// -------------------------------------------------------------
// Function to Traverse (Display) Array
// -------------------------------------------------------------
void traverseArray(int arr[], int size)
{
    int i;

    if(size == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// -------------------------------------------------------------
// Function to Insert Element at Given Index
// -------------------------------------------------------------
void insertInArray(int arr[], int *size)
{
    int index, value, i;

    if(*size == MAX_SIZE)
    {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    printf("Enter index to insert: ");
    scanf("%d", &index);

    if(index < 0 || index > *size)
    {
        printf("Invalid index.\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    // Shift elements to right
    for(i = *size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    (*size)++;

    printf("Element inserted successfully.\n");
}

// -------------------------------------------------------------
// Function to Delete Element from Given Index
// -------------------------------------------------------------
void deleteInArray(int arr[], int *size)
{
    int index, i;

    if(*size == 0)
    {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    printf("Enter index to delete: ");
    scanf("%d", &index);

    if(index < 0 || index >= *size)
    {
        printf("Invalid index.\n");
        return;
    }

    // Shift elements to left
    for(i = index; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*size)--;

    printf("Element deleted successfully.\n");
}

// -------------------------------------------------------------
// Function to Update Element
// -------------------------------------------------------------
void updateArray(int arr[], int size)
{
    int index, value;

    if(size == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter index to update: ");
    scanf("%d", &index);

    if(index < 0 || index >= size)
    {
        printf("Invalid index.\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    arr[index] = value;

    printf("Element updated successfully.\n");
}

// -------------------------------------------------------------
// Function to Sort Array using Bubble Sort
// -------------------------------------------------------------
void sortArray(int arr[], int size)
{
    int i, j, temp;

    if(size == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Array sorted successfully (Ascending Order).\n");
    traverseArray(arr, size);
}

// -------------------------------------------------------------
// Function to Search Element (Linear Search)
// -------------------------------------------------------------
void searchArray(int arr[], int size)
{
    int target, i;

    if(size == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &target);

    for(i = 0; i < size; i++)
    {
        if(arr[i] == target)
        {
            printf("Element found at index %d\n", i);
            return;
        }
    }

    printf("Element not found.\n");
}