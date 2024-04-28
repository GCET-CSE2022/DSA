// DSA Bubble Sort
// Bubble sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong
// order. The pass through the list is repeated until the list is sorted.

#include <stdio.h>

int main()
{
    int arr[] = {5, 1, 4, 2, 8};          // Example array
    int N = sizeof(arr) / sizeof(arr[0]); // Calculate array size

    // Bubble sort
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
