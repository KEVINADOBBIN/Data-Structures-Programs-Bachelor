#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

int main() {
    struct node *p, *start = NULL, *q = NULL;
    int item, count = 0;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        p = (struct node *)malloc(sizeof(struct node));

        printf("Enter the element: ");
        scanf("%d", &item);

        p->info = item;
        p->link = NULL;

        if (start == NULL) {
            start = p;
        } else {
            q->link = p;
        }
        q = p;

        printf("Do you want to enter another element (y/n): ");
        scanf(" %c", &choice);
    }

    printf("\nLinked List Elements:\n");
    p = start;
    while (p != NULL) {
        printf("%d ", p->info);
        count++;
        p = p->link;
    }

    printf("\nNumber of nodes in the linked list is %d\n", count);

    return 0;
}
