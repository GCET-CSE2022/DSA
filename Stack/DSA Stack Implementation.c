// DSA Stack implementation using array in C

#include <stdio.h>

#define MAX_SIZE 100 // Maximum size of the stack

int stack[MAX_SIZE];
int top = -1; // Initialize top of stack to -1

void push(int item)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }
    stack[++top] = item;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1;
    }
    return stack[top--];
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice, item;

    printf("STACK OPERATIONS USING ARRAY\n");
    printf("----------------------------\n");
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. DISPLAY\n");
    printf("4. EXIT\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter an element to push: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            item = pop();
            if (item != -1)
            {
                printf("Popped element: %d\n", item);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
