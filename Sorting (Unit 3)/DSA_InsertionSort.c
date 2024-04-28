// // DSA Insertion sort in C
// Insertion sort builds the sorted array one element at a time by repeatedly taking the next element and
// inserting it into its correct position in the already sorted portion of the array.

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
