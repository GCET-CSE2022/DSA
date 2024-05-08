// program to creates a singly linked list with three nodes and prints their values:

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    // Create three nodes
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    // Assign data and set next pointers
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // Print the elements of the linked list
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Free the allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}
