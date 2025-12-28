// File Name: circular_queue.c
// Title: Circular Queue Simulation Using Array
#include <stdio.h>
#include <stdlib.h>

#define N 5  // Size of circular queue

int queue[N];
int front = -1, rear = -1;

// Function prototypes
void cginsert(int item);
void cqdelete();
void cqdisplay();
int cgempty();
int cgfull();

int main() {
    int choice, item;

    while (1) {
        printf("\n--- Circular Queue SIMULATOR ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                cginsert(item);
                break;

            case 2:
                cqdisplay();
                break;

            case 3:
                cqdelete();
                break;

            case 4:
                exit(0);

            default:
                printf("Error: Invalid choice!\n");
        }
    }

    return 0;
}

// Insert element into circular queue
void cginsert(int item) {
    if (cgfull()) {
        printf("Circular queue overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % N;
    }

    queue[rear] = item;
    printf("%d inserted into the queue.\n", item);
}

// Delete element from circular queue
void cqdelete() {
    if (cgempty()) {
        printf("Circular queue underflow\n");
        return;
    }

    int item = queue[front];
    printf("Deleted element is %d\n", item);

    if (front == rear) { // Only one element
        front = rear = -1;
        printf("Circular queue is now empty.\n");
    } else {
        front = (front + 1) % N;
    }
}

// Display elements of circular queue
void cqdisplay() {
    if (cgempty()) {
        printf("Circular queue is empty\n");
        return;
    }

    printf("Queue elements:\n");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % N;
    }
    printf("\n");
}

// Check if queue is empty
int cgempty() {
    return (front == -1 && rear == -1);
}

// Check if queue is full
int cgfull() {
    return ((rear + 1) % N == front);
}
