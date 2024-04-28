#include <stdio.h>

// Function: insertSorted
// Inserts a key in arr[] of given capacity while maintaining sorted order.
// Parameters:
// - arr: Array in which the key is to be inserted.
// - n: Current size of arr[].
// - key: Key to be inserted.
// - capacity: Maximum capacity of arr[].
// Returns:
// - Updated size of arr[] after insertion.
int insertSorted(int arr[], int n, int key, int capacity)
{
    // Check if there is space available in the array
    if (n >= capacity)
        return n; // If no space available, return current size

    // Insert the key at the end of the array
    arr[n] = key;

    // Return updated size after insertion
    return (n + 1);
}

// Driver Code
int main()
{
    // Initialize array with some values
    int arr[20] = {12, 16, 20, 40, 50, 70};

    // Calculate capacity of the array
    int capacity = sizeof(arr) / sizeof(arr[0]);

    // Current size of the array
    int n = 6;

    // Key to be inserted
    int key = 26;

    // Print elements of the array before insertion
    printf("\nBefore Insertion: ");
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    // Insert key into the array
    n = insertSorted(arr, n, key, capacity);

    // Print elements of the array after insertion
    printf("\nAfter Insertion: ");
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    return 0;
}