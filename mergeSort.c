#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *left = (int *)malloc(len1 * sizeof(int));
    int *right = (int *)malloc(len2 * sizeof(int));

    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k++];
    }

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

    while (leftIndex < len1)
        arr[mainArrayIndex++] = left[leftIndex++];

    while (rightIndex < len2)
        arr[mainArrayIndex++] = right[rightIndex++];

    free(left);
    free(right);
}

// Merge sort algo, TC : O(n log n), SC : O(n)
void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = (s + e) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}


void merge2(int *arr, int *temp, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= end)
        temp[k++] = arr[j++];

    while (start <= end)
    {
        arr[start] = temp[start];
        ++start;
    }
}

// TC : O(n log n), SC : O(n)
void mergeSort2(int *arr, int *temp, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    mergeSort2(arr, temp, start, mid);
    mergeSort2(arr, temp, mid + 1, end);
    merge2(arr, temp, start, mid, end);
}

int main()
{
    int arr[] = {3, 1, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    int arr2[] = {3, 1, 2, 9};
    int temp[4];
    mergeSort2(arr2, temp, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr2[i]);

    printf("\n");

    return 0;
}
