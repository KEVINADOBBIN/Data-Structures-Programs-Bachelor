// File Name: towers_of_hanoi.c
// Title: Towers of Hanoi Problem
#include <stdio.h>
#include <stdlib.h>

// Function prototype
void towers(int n, char source, char aux, char dest);

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("\nThe sequence of moves is:\n");
    towers(n, 'A', 'B', 'C');

    return 0;
}

// Function to solve Towers of Hanoi
void towers(int n, char source, char aux, char dest) {
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", source, dest);
        return;
    }

    // Move n-1 disks from source to auxiliary
    towers(n - 1, source, dest, aux);

    // Move the nth disk from source to destination
    printf("Move disk %d from peg %c to peg %c\n", n, source, dest);

    // Move n-1 disks from auxiliary to destination
    towers(n - 1, aux, source, dest);
}
