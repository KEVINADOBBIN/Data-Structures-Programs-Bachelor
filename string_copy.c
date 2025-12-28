// File Name: string_copy.c
// Title: Copy One String into Another Without Using String Functions

#include <stdio.h>

// Function prototype
void copy(char *dest, char *src);

int main() {
    char s1[50], s2[50];

    printf("Enter a string: ");
    scanf("%s", s1);

    copy(s2, s1);

    printf("\nSTRING 1 is: %s\n", s1);
    printf("STRING 2 is: %s\n", s2);

    return 0;
}

// Function to copy string
void copy(char *dest, char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';   // Null terminate destination string
}
