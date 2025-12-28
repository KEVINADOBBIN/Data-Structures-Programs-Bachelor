#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX 50

float stack[MAX];
int top = -1;

/* Function declarations */
void push(float item);
float pop(void);

int main() {
    char postfix[MAX];
    int i;
    float n1, n2, result, value;

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {

        /* If operand is a digit */
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        }

        /* If operand is a variable */
        else if (isalpha(postfix[i])) {
            printf("Enter value of %c: ", postfix[i]);
            scanf("%f", &value);
            push(value);
        }

        /* If operator */
        else {
            n2 = pop();
            n1 = pop();

            switch (postfix[i]) {
                case '+':
                    result = n1 + n2;
                    break;
                case '-':
                    result = n1 - n2;
                    break;
                case '*':
                    result = n1 * n2;
                    break;
                case '/':
                    result = n1 / n2;
                    break;
                case '^':
                    result = pow(n1, n2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(result);
        }
    }

    printf("Result of postfix expression = %.2f\n", pop());
    return 0;
}

/* Push operation */
void push(float item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

/* Pop operation */
float pop(void) {
    if (top == -1) {
        printf("Invalid postfix expression\n");
        exit(1);
    }
    return stack[top--];
}
