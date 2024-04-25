/*Singly Linked List in C

This program creates a singly linked list in C. It allows the user to append nodes to the list, print the list, and traverse the list from the head, from the last node, or from a specific index.
Dry Run

    The program starts by defining a Node structure which contains an integer data and a pointer next to the next node in the list.

    The appendNode(Node* head, int data) function is defined to append a new node with the given data to the end of the list. If the list is empty (i.e., the head is NULL), it sets the head to the new node. Otherwise, it traverses the list to find the last node and updates its next pointer to the new node.

    The printList(Node* head) function is defined to print the data in each node of the list from the head to the end of the list.

    The freeList(Node* head) function is defined to free the memory used by the linked list. It traverses the list and frees each node.

    The traverseFromHead(Node* head) function is defined to print the list starting from the head node.

    The traverseFromLast(Node* head) function is defined to print the list in reverse order. It first reverses the links in the list and then prints the list.

    The traverseFromIndex(Node* head, int index) function is defined to print the list starting from a given index. It first traverses the list to the start index and then prints the list from that node.

    In the main() function, five nodes are appended to the list with data 2, 5, 7, 9, and 0. The list is then printed, followed by traversals from the head, from the last node, and from a user-specified index.

    The program ends with freeList(head) to free the memory used by the list, and return 0;, indicating successful execution.
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to add a new node at the end of the linked list
Node *appendNode(Node *head, int data)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

// Function to print all elements in the linked list
void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory used by the linked list
void freeList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }
}

// Traverse the list from head to last node
void traverseFromHead(Node *head)
{
    printf("Traversing from head to last node:\n");
    printList(head);
}

// Traverse the list from last node to head
void traverseFromLast(Node *head)
{
    printf("Traversing from last node to head:\n");
    Node *current = head;
    Node *prev = NULL;
    while (current != NULL)
    {
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    printList(prev);
}

// Traverse the list from index entered by user to last node
void traverseFromIndex(Node *head, int index)
{
    printf("Traversing from index %d to last node:\n", index);
    Node *current = head;
    int count = 1;
    while (current != NULL && count < index)
    {
        current = current->next;
        count++;
    }
    if (current == NULL)
    {
        printf("Index %d is out of range.\n", index);
    }
    else
    {
        printList(current);
    }
}

// Main function where execution begins
int main()
{
    Node *head = NULL; // This will be the start of the list (initially NULL)
    int data;

    // Adding 5 elements to the list: 2, 5, 7, 9, 0
    head = appendNode(head, 2);
    head = appendNode(head, 5);
    head = appendNode(head, 7);
    head = appendNode(head, 9);
    head = appendNode(head, 0);

    // Output the numbers in the list
    printf("Current List: \n");
    printList(head); // Call printList to display the list

    // Traverse the list from head to last node
    traverseFromHead(head);

    // Traverse the list from last node to head
    traverseFromLast(head);

    // Traverse the list from index entered by user to last node
    int index;
    printf("Enter the index to start traversal from: ");
    scanf("%d", &index);
    traverseFromIndex(head, index);

    // Clean up the list and free the memory
    freeList(head);

    return 0; // Indicate that the program ended successfully
}
