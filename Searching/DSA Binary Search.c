// Code for Binary search in C (SORTED ARRAY)

#include <stdio.h>

int binarySearch(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid; // Element found, return its index
        }
        else if (arr[mid] < key)
        {
            low = mid + 1; // Search the right half
        }
        else
        {
            high = mid - 1; // Search the left half
        }
    }

    return -1; // Element not found
}

int main()
{
    int arr[] = {3, 4, 5, 6, 7, 8, 9};       // Example sorted array
    int key = 4;                             // Value to search for
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate array size

    int result = binarySearch(arr, size, key);

    if (result != -1)
    {
        printf("Element is present at index %d\n", result);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}
