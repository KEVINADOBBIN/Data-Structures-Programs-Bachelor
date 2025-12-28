// File Name: bubble_sort.c
// Title: Bubble Sort Algorithm
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n, temp;
    int a[30];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the list:\n");
    for (i = 0; i < n; i++) {
        printf("Element [%d]: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\nBUBBLE SORT\n");
    printf("Original Order:\n");
    for (i = 0; i < n; i++) {
        printf("%5d", a[i]);
    }
    printf("\n****************\n");

    // Bubble sort algorithm
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("Sorted Order:\n");
    for (i = 0; i < n; i++) {
        printf("%5d", a[i]);
    }
    printf("\n****************\n");

    return 0;
}
