// WAP to search element in a linked list

#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node of the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to search for an element in the linked list
struct Node *search(struct Node *head, int key)
{
    // Initialize a pointer to traverse the linked list
    struct Node *current = head;

    // Traverse the linked list until the end is reached or the key is found
    while (current != NULL)
    {
        // If the current node contains the key, return the pointer to that node
        if (current->data == key)
            return current;

        // Move to the next node
        current = current->next;
    }

    // If the key is not found, return NULL
    return NULL;
}

// Function to create a new node
struct Node *createNode(int data)
{
    // Allocate memory for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1); // Exit the program
    }

    // Initialize the data and next pointer of the new node
    newNode->data = data;
    newNode->next = NULL;

    // Return a pointer to the newly created node
    return newNode;
}

int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> NULL
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    // Search for the element 2 in the linked list
    int key = 2;
    struct Node *result = search(head, key);

    // Check if the element was found
    if (result != NULL)
        printf("Element %d found in the linked list\n", key);
    else
        printf("Element %d not found in the linked list\n", key);

    return 0;
}
