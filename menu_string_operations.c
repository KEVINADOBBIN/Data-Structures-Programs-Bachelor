// File Name: string_operations.c
// Title: Menu Driven String Operations Without Using String Functions
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int stringLength(char *s);
void stringConcat(char *s1, char *s2);
void stringReverse(char *s);

int main() {
    char s1[100], s2[100];
    int choice;

    while (1) {
        printf("\n\n--- Main Menu ---\n");
        printf("1: String Length\n");
        printf("2: String Concatenation\n");
        printf("3: String Reverse\n");
        printf("4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                scanf("%s", s1);
                printf("Length of \"%s\" is %d\n", s1, stringLength(s1));
                break;

            case 2:
                printf("Enter first string: ");
                scanf("%s", s1);
                printf("Enter second string: ");
                scanf("%s", s2);
                stringConcat(s1, s2);
                printf("Concatenated string: %s\n", s1);
                break;

            case 3:
                printf("Enter a string: ");
                scanf("%s", s1);
                stringReverse(s1);
                printf("Reversed string: %s\n", s1);
                break;

            case 4:
                exit(0);

            default:
                printf("Error: Invalid choice!\n");
        }
    }

    return 0;
}

// Function to calculate string length
int stringLength(char *s) {
    int length = 0;
    while (*s != '\0') {
        length++;
        s++;
    }
    return length;
}

// Function to concatenate two strings
void stringConcat(char *s1, char *s2) {
    while (*s1 != '\0') {
        s1++;
    }
    while (*s2 != '\0') {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

// Function to reverse a string
void stringReverse(char *s) {
    int len = stringLength(s);
    int i;
    char temp;
    for (i = 0; i < len / 2; i++) {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}
