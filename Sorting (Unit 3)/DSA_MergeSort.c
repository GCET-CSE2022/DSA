// Merge sort is another divide-and-conquer algorithm. It divides the input array into two halves, recursively sorts each
// half, and then merges the sorted halves to produce the final sorted array

#include <stdio.h>
#include <stdlib.h>

// Function: merge
// Description: Merges two sorted subarrays into one sorted array.
// Parameters:
// - arr: Pointer to the array containing elements to be merged.
// - s: Starting index of the first subarray.
// - e: Ending index of the second subarray.
// Returns: Void
void merge(int *arr, int s, int e)
{
    // Calculate the middle index of the array
    int mid = (s + e) / 2;

    // Calculate the lengths of the two subarrays
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Dynamically allocate memory for the two subarrays
    int *left = (int *)malloc(len1 * sizeof(int));
    int *right = (int *)malloc(len2 * sizeof(int));

    // Copy elements into the left subarray
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k++];
    }

    // Copy elements into the right subarray
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k++];
    }

    // Merge the two subarrays into the main array
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while (leftIndex < len1 && rightIndex < len2)
    {
        if (left[leftIndex] < right[rightIndex])
            arr[mainArrayIndex++] = left[leftIndex++];
        else
            arr[mainArrayIndex++] = right[rightIndex++];
    }

    // Copy remaining elements from the left subarray
    while (leftIndex < len1)
        arr[mainArrayIndex++] = left[leftIndex++];

    // Copy remaining elements from the right subarray
    while (rightIndex < len2)
        arr[mainArrayIndex++] = right[rightIndex++];

    // Free the dynamically allocated memory
    free(left);
    free(right);
}

// Function: mergeSort
// Description: Sorts an array using the merge sort algorithm.
// Parameters:
// - arr: Pointer to the array to be sorted.
// - s: Starting index of the array.
// - e: Ending index of the array.
// Returns: Void
void mergeSort(int *arr, int s, int e)
{
    // Base case: If the array has one or fewer elements, it is already sorted
    if (s >= e)
        return;

    // Calculate the middle index of the array
    int mid = (s + e) / 2;

    // Recursively sort the left and right halves of the array
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    // Merge the sorted halves
    merge(arr, s, e);
}

int main()
{
    int arr[] = {3, 1, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using the mergeSort function
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array (mergeSort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}