#include <stdio.h>
#include <string.h>

int search(char *text, char *pattern);

int main() {
    char text[30], pattern[15];
    int index;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';   // remove newline

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // remove newline

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

int search(char *text, char *pattern) {
    int i, j, found;
    int max = strlen(text) - strlen(pattern) + 1;

    for (i = 0; i < max; i++) {
        found = 1;
        for (j = 0; j < strlen(pattern); j++) {
            if (text[i + j] != pattern[j]) {
                found = 0;
                break;
            }
        }
        if (found)
            return (i + 1);   // position starts from 1
    }
    return 0;
}
