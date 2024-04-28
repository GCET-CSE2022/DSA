// Code for linear search in C (UNSORTED ARRAY)

#include <stdio.h>

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i; // Element found, return its index
        }
    }
    return -1; // Element not found
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 100, 0}; // Example array
    int key = 100;                            // Value to search for
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate array size

    int result = linearSearch(arr, size, key);

    if (result == -1)
    {
        printf("ELEMENT NOT FOUND!!\n");
    }
    else
    {
        printf("Item is present at index %d\n", result);
    }

    return 0;
}
