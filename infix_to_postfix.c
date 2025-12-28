// File Name: infix_to_postfix.c
// Title: Convert Fully Parenthesized Infix to Postfix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

char stack[MAX];
int top = -1;

// Stack functions
void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

// Check if character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Infix to Postfix conversion
void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int k = 0; // postfix index

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If operand, add to postfix
        if ((ch >= '0' && ch <= '9') || 
            (ch >= 'a' && ch <= 'z') || 
            (ch >= 'A' && ch <= 'Z')) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != '(' && top != -1) {
                postfix[k++] = pop();
            }
            pop(); // remove '(' from stack
        }
        else if (isOperator(ch)) {
            while (top != -1 && peek() != '(') {
                // No precedence check needed for fully parenthesized
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];

    printf("Enter a fully parenthesized infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
