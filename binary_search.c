// File Name: binary_search.c
// Title: Binary Search in an Array
#include <stdio.h>
#include <stdlib.h>

// Function prototype
void binsearch(int n, int a[], int item);

int main() {
    int a[100], i, n, item;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter elements of the array in sorted order:\n");
    for (i = 0; i < n; i++) {
        printf("Element [%d]: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Enter the item to be searched: ");
    scanf("%d", &item);

    binsearch(n, a, item);

    return 0;
}

// Function to perform binary search
void binsearch(int n, int a[], int item) {
    int beg = 0, end = n - 1, mid;

    while (beg <= end) {
        mid = (beg + end) / 2;

        if (item == a[mid]) {
            printf("Item %d is found at position %d\n", item, mid + 1);
            return;
        }
        else if (item > a[mid]) {
            beg = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    printf("Item %d is not found in the array.\n", item);
}
