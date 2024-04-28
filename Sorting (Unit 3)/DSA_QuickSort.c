#include <stdio.h>

// Quick sort is a divide-and-conquer algorithm. It selects a pivot element and partitions the array around the pivot,
// such that elements less than the pivot are placed before it, and elements greater than the pivot are placed after it.
// The process is recursively applied to the sub-arrays until the entire array is sorted.

// Function: partition
// Description: Partitions the array into two halves based on a pivot element.
// Parameters:
// - arr: Pointer to the array to be partitioned.
// - s: Starting index of the partition.
// - e: Ending index of the partition.
// Returns: Index of the pivot element after partitioning.
int partition(int *arr, int s, int e)
{
    // Select the pivot element (first element in this case)
    int pivotIndex = s;
    int pivotElement = arr[s];
    int count = 0;

    // Count the number of elements smaller than or equal to the pivot
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivotElement)
            ++count;
    }

    // Calculate the index where the pivot should be placed after partitioning
    int rightIndex = s + count;

    // Swap the pivot with the element at the calculated index
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[rightIndex];
    arr[rightIndex] = temp;
    pivotIndex = rightIndex;

    // Partition the array into two halves around the pivot element
    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        // Move the index i to find an element greater than the pivot
        while (arr[i] <= pivotElement)
            ++i;
        // Move the index j to find an element less than or equal to the pivot
        while (arr[j] > pivotElement)
            --j;
        // Swap elements if necessary to ensure all elements to the left of the pivot are smaller,
        // and all elements to the right are larger
        if (i < pivotIndex && j > pivotIndex)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Return the index of the pivot element after partitioning
    return pivotIndex;
}

// Function: quickSort
// Description: Sorts an array using the quick sort algorithm.
// Parameters:
// - arr: Pointer to the array to be sorted.
// - s: Starting index of the array.
// - e: Ending index of the array.
// Returns: Void
void quickSort(int *arr, int s, int e)
{
    // Base case: If the array has one or fewer elements, it is already sorted
    if (s >= e)
        return;

    // Partition the array and recursively sort the partitions
    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1); // Sort the left partition
    quickSort(arr, p + 1, e); // Sort the right partition
}

int main()
{
    // Input array
    int arr[] = {8, 1, 3, 4, 20, 50, 50, 50, 50, 50, 5, 1, 1, 1, 2, 2, 2, 50, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using quick sort
    int s = 0;
    int e = n - 1;
    quickSort(arr, s, e);

    // Print the sorted array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
