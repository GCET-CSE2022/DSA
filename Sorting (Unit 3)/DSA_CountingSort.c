/*Counting sort is an algorithm for sorting a collection of objects according to keys that are small integers;
that is, it is an integer sorting algorithm. It operates by counting the number of objects that have each distinct key value,
and using arithmetic on those counts to determine the positions of each key value in the output sequence.
Its running time is linear in the number of items and the difference between the maximum and minimum key values,
so it is only suitable for direct use in situations where the variation in keys is not significantly greater than the number of items.

Here is the source code of the C program to sort integers using Counting Sort technique.*/
/*

 * C Program for counting sort

 */

#include <stdio.h>

/*  Counting sort function  */

void counting_sort(int A[], int k, int n)

{

    int i, j;

    int B[15], C[100];

    for (i = 0; i <= k; i++)

        C[i] = 0;

    for (j = 1; j <= n; j++)

        C[A[j]] = C[A[j]] + 1;

    for (i = 1; i <= k; i++)

        C[i] = C[i] + C[i - 1];

    for (j = n; j >= 1; j--)

    {

        B[C[A[j]]] = A[j];

        C[A[j]] = C[A[j]] - 1;
    }

    printf("The Sorted array is : ");

    for (i = 1; i <= n; i++)

        printf("%d ", B[i]);
}

/*  End of counting_sort()  */

/*  The main() begins  */

int main()

{

    int n, k = 0, A[15], i;

    printf("Enter the number of input : ");

    scanf("%d", &n);

    printf("\nEnter the elements to be sorted :\n");

    for (i = 1; i <= n; i++)

    {

        scanf("%d", &A[i]);

        if (A[i] > k)
        {

            k = A[i];
        }
    }

    counting_sort(A, k, n);

    printf("\n");
    return 0;
}
/*Here’s a brief explanation of how this code works:

    The counting_sort function takes an array A[], the maximum key value k, and the number of elements n as input.
    It initializes two arrays B[] and C[]. B[] will hold the sorted array and C[] is used for counting.
    The function first counts the occurrence of each element in the array A[] and stores it in C[].
    Then it calculates the cumulative count of elements in C[].
    It then places the elements from A[] to B[] according to the cumulative count in C[], and decreases the count of each element in C[] by 1.
    Finally, it prints the sorted array B[].

In the main function, it asks the user for the number of inputs and the elements to be sorted. It finds the maximum element k to be used as the maximum key value for the counting_sort function.

This algorithm is efficient when the range of input values (keys) is not significantly greater than the number of values to be sorted, making it suitable for use in specific situations. It has a linear running time complexity of O(n+k).Here’s a brief explanation of how your code works:

    The counting_sort function takes an array A[], the maximum key value k, and the number of elements n as input.
    It initializes two arrays B[] and C[]. B[] will hold the sorted array and C[] is used for counting.
    The function first counts the occurrence of each element in the array A[] and stores it in C[].
    Then it calculates the cumulative count of elements in C[].
    It then places the elements from A[] to B[] according to the cumulative count in C[], and decreases the count of each element in C[] by 1.
    Finally, it prints the sorted array B[].

In the main function, it asks the user for the number of inputs and the elements to be sorted. It finds the maximum element k to be used as the maximum key value for the counting_sort function.

This algorithm is efficient when the range of input values (keys) is not significantly greater than the number of values to be sorted, making it suitable for use in specific situations. It has a linear running time complexity of O(n+k).
*/