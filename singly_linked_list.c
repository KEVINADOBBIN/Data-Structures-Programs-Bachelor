// File Name: singly_linked_list.c
// Title: Singly Linked List Operations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct node {
    int rollno;
    char name[20];
    struct node *link;
};

struct node *start = NULL;

// Function prototypes
void create();
void insBeg();
void delItem(int regno);
void search(int regno);
void display();

int main() {
    int choice, regno;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create Linked List\n");
        printf("2. Insert Node at Beginning\n");
        printf("3. Delete Node by Roll Number\n");
        printf("4. Search Node by Roll Number\n");
        printf("5. Display Linked List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insBeg();
                break;
            case 3:
                printf("Enter roll number to delete: ");
                scanf("%d", &regno);
                delItem(regno);
                break;
            case 4:
                printf("Enter roll number to search: ");
                scanf("%d", &regno);
                search(regno);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Error: Invalid choice!\n");
        }
    }

    return 0;
}

// Create linked list
void create() {
    char choice = 'y';
    struct node *p, *q;

    start = NULL;

    while (choice == 'y' || choice == 'Y') {
        p = (struct node*)malloc(sizeof(struct node));
        if (!p) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter roll number: ");
        scanf("%d", &p->rollno);
        printf("Enter name: ");
        scanf("%s", p->name);

        p->link = NULL;

        if (start == NULL) {
            start = p;
        } else {
            q->link = p;
        }
        q = p;

        printf("Do you want to add another node (y/n)? ");
        scanf(" %c", &choice);
    }
}

// Insert at beginning
void insBeg() {
    struct node *p = (struct node*)malloc(sizeof(struct node));
    if (!p) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &p->rollno);
    printf("Enter name: ");
    scanf("%s", p->name);

    p->link = start;
    start = p;

    printf("Node inserted at beginning.\n");
}

// Delete node by roll number
void delItem(int regno) {
    struct node *p = start, *prev = NULL;

    if (start == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    // If first node to delete
    if (start->rollno == regno) {
        start = start->link;
        free(p);
        printf("Node with roll number %d deleted.\n", regno);
        return;
    }

    while (p != NULL && p->rollno != regno) {
        prev = p;
        p = p->link;
    }

    if (p == NULL) {
        printf("Roll number %d not found in the list.\n", regno);
    } else {
        prev->link = p->link;
        free(p);
        printf("Node with roll number %d deleted.\n", regno);
    }
}

// Search node by roll number
void search(int regno) {
    struct node *p = start;
    int pos = 1;

    while (p != NULL) {
        if (p->rollno == regno) {
            printf("Node found at position %d\n", pos);
            printf("Roll Number: %d, Name: %s\n", p->rollno, p->name);
            return;
        }
        p = p->link;
        pos++;
    }
    printf("Node with roll number %d does not exist.\n", regno);
}

// Display all nodes
void display() {
    struct node *p = start;

    if (start == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked List Elements:\n");
    while (p != NULL) {
        printf("Roll Number: %d, Name: %s\n", p->rollno, p->name);
        p = p->link;
    }
}
