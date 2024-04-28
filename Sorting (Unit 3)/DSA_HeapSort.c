// Heap sort is a comparison-based sorting algorithm that builds a heap from the input array and then repeatedly
// extracts the maximum element from the heap and places it at the end of the sorted array. The process is repeated
// until the heap is empty.

#include <stdio.h>

// Function to heapify a subtree rooted at node i, which is an index in arr[]
// Heapify ensures that the subtree rooted at node i satisfies the heap property
void heapify(int arr[], int n, int i) {
    int largest = i;            // Initialize largest as root
    int left = 2 * i + 1;       // Left child index
    int right = 2 * i + 2;      // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        // Swap arr[i] and arr[largest]
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
// Heap Sort is a comparison-based sorting algorithm that converts the input array into a heap,
// then repeatedly removes the largest element from the heap and places it at the end of the sorted array.
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
