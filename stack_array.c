// File Name: stack_array.c
// Title: Stack Implementation Using Array
#include <stdio.h>
#include <stdlib.h>

#define MAXSTK 3

int stack[MAXSTK];
int top = -1;

// Function prototypes
void push(int item);
void pop();
void display();
int isEmpty();
int isFull();

int main() {
    int choice, item;

    while (1) {
        printf("\n--- STACK SIMULATOR ---\n");
        printf("1. PUSH\n");
        printf("2. DISPLAY\n");
        printf("3. POP\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                display();
                break;

            case 3:
                pop();
                break;

            case 4:
                exit(0);

            default:
                printf("Error: Invalid choice!\n");
        }
    }

    return 0;
}

// Push function
void push(int item) {
    if (isFull()) {
        printf("STACK OVERFLOW\n");
        return;
    }
    top++;
    stack[top] = item;
    printf("%d pushed onto the stack.\n", item);
}

// Pop function
void pop() {
    int item;
    if (isEmpty()) {
        printf("STACK UNDERFLOW\n");
        return;
    }
    item = stack[top];
    top--;
    printf("%d popped from the stack.\n", item);
}

// Display function
void display() {
    int i;
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements:\n");
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

// Check if stack is empty
int isEmpty() {
    return (top == -1);
}

// Check if stack is full
int isFull() {
    return (top == MAXSTK - 1);
}
