#include <stdio.h>

// Quick sort -> based on Partition Logic (element -> Also known as PIVOT)
// PIVOT is an element whose right and left sides should be sorted
int partition(int *arr, int s, int e)
{
    int pivotIndex = s;
    int pivotElement = arr[s];
    int count = 0;

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivotElement)
            ++count;
    }

    int rightIndex = s + count;
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[rightIndex];
    arr[rightIndex] = temp;
    pivotIndex = rightIndex;

    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivotElement)
            ++i;
        while (arr[j] > pivotElement)
            --j;
        if (i < pivotIndex && j > pivotIndex)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    return pivotIndex;
}

// TC : O(n log n), SC : O(n)
void quickSort(int *arr, int s, int e)
{
    if (s >= e)
        return;

    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {8, 1, 3, 4, 20, 50, 50, 50, 50, 50, 5, 1, 1, 1, 2, 2, 2, 50, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    int s = 0;
    int e = n - 1;
    quickSort(arr, s, e);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
