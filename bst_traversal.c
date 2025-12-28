// File Name: bst_traversal.c
// Title: Binary Search Tree Creation and Traversal
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int info;
    struct node *left;
    struct node *right;
};

// Function prototypes
void insert(struct node **p, int item);
void inorder(struct node *p);
void preorder(struct node *p);
void postorder(struct node *p);

int main() {
    struct node *ptr = NULL;
    int n, i, item, ch;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Create BST\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter number of elements to add: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &item);
                    insert(&ptr, item);
                }
                break;

            case 2:
                printf("Preorder Traversal:\n");
                preorder(ptr);
                printf("\n");
                break;

            case 3:
                printf("Inorder Traversal:\n");
                inorder(ptr);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal:\n");
                postorder(ptr);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Error: Invalid choice!\n");
        }
    }

    return 0;
}

// Insert node into BST
void insert(struct node **p, int item) {
    if (*p == NULL) {
        *p = (struct node*)malloc(sizeof(struct node));
        if (!(*p)) {
            printf("Memory allocation failed\n");
            return;
        }
        (*p)->info = item;
        (*p)->left = NULL;
        (*p)->right = NULL;
        printf("Node %d created.\n", item);
        return;
    }

    if (item < (*p)->info) {
        insert(&((*p)->left), item);
    } else if (item > (*p)->info) {
        insert(&((*p)->right), item);
    } else {
        printf("Key %d found! Duplicate value rejected.\n", item);
    }
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct node *p) {
    if (p != NULL) {
        inorder(p->left);
        printf("%d ", p->info);
        inorder(p->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct node *p) {
    if (p != NULL) {
        printf("%d ", p->info);
        preorder(p->left);
        preorder(p->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct node *p) {
    if (p != NULL) {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->info);
    }
}
