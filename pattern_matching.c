// File Name: pattern_matching.c
// Title: Pattern Matching Algorithm (Naive Method)

#include <stdio.h>
#include <string.h>

// Function prototype
int search(char *text, char *pattern);

int main() {
    char text[30], pattern[15];
    int index;

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    if (strlen(text) < strlen(pattern)) {
        printf("Text length is smaller than pattern length\n");
        return 0;
    }

    index = search(text, pattern);

    if (index == 0)
        printf("Pattern is not found in the text\n");
    else
        printf("Pattern is found at position %d\n", index);

    return 0;
}

// Function to search pattern in text
int search(char *text, char *pattern) {
    int i, j;
    int textLen = strlen(text);
    int patLen = strlen(pattern);

    for (i = 0; i <= textLen - patLen; i++) {
        for (j = 0; j < patLen; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == patLen)
            return (i + 1);   // Position starts from 1
    }

    return 0;
}
