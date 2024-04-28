// Radix sort is a non-comparative sorting algorithm that sorts integers by grouping them by individual digits or radix. It
// can be applied to numbers represented in any positional numeral system. Radix sort processes the digits of each
// number position by position, from the least significant digit to the most significant digit, using counting sort as a
// subroutine.

#include <stdio.h>

// Function to find the maximum element in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Function to perform counting sort based on a specific digit (exp)
// Counting sort is a sorting algorithm that sorts the elements of an array by counting the number of occurrences of each unique element in the array.
// It works by counting the number of occurrences of each digit in the input array, then using these counts to determine the position of each element in the sorted output array.
void countSort(int arr[], int n, int exp) {
    int output[n];              // Output array
    int count[10] = {0};        // Initialize count array with 10 digits (0 to 9)

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] to contain the actual position of the digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[] so that arr[] now contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort function to sort an array of integers using radix sort algorithm
// Radix sort is a non-comparative sorting algorithm that sorts numbers by processing individual digits of the numbers.
// It sorts the numbers by first grouping the individual digits of the same place value, and then sorting the numbers according to each digit.
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);   // Find the maximum number to know number of digits

    // Do counting sort for every digit.
    // Instead of passing digit number, exp is passed. exp is 10^i where i is current digit number
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
