#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node
{
    int value;
    struct node *next;
};

// Function to print the values in the linked list
void printLinkedListValues(struct node *p)
{
    if (p == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n"); // Print a newline at the end for better format
}

int main()
{
    // Initialize pointers to nodes
    struct node *head = NULL;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    // Allocate memory for nodes
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    // Assign values to nodes
    one->value = 1;
    two->value = 2;
    three->value = 3;

    // Connect nodes
    one->next = two;
    two->next = three;
    three->next = NULL;

    // Set head to point to the first node
    head = one;

    // Print the values in the linked list
    printLinkedListValues(head);

    // Free allocated memory
    free(one);
    free(two);
    free(three);

    return 0; // Return success
}
