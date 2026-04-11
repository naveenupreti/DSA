/*
Enter Prefix Expression: /+A*B-CD-E*FG

Infix Expression: ((A+(B*(C-D)))/(E-(F*G)))
Postfix Expression: ABCD-*+EFG*-/
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack to store strings
char stack[MAX][MAX];
int top = -1;

// PUSH function (no ++ inside array)
void push(char str[]) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    top = top + 1;          // Step 1: increment top
    strcpy(stack[top], str); // Step 2: copy string into stack
}

// POP function (no -- inside array)
void pop(char str[]) {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    strcpy(str, stack[top]); // Step 1: copy top element
    top = top - 1;           // Step 2: decrement top
}

// Function to check operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// PREFIX ? INFIX
void prefixToInfix(char prefix[], char infix[]) {

    char op1[MAX], op2[MAX], temp[MAX];

    int i;

    // Scan from RIGHT to LEFT
    for (i = strlen(prefix) - 1; i >= 0; i--) {

        // If operand ? push as string
        if (isalnum(prefix[i])) {
            temp[0] = prefix[i];
            temp[1] = '\0';
            push(temp);
        }

        // If operator
        else if (isOperator(prefix[i])) {

            // Pop two operands
            pop(op1);
            pop(op2);

            // Form: (op1 operator op2)
            strcpy(temp, "(");
            strcat(temp, op1);

            int len = strlen(temp);
            temp[len] = prefix[i];
            temp[len + 1] = '\0';

            strcat(temp, op2);
            strcat(temp, ")");

            // Push back result
            push(temp);
        }
    }

    // Final result
    pop(infix);
}

// PREFIX ? POSTFIX
void prefixToPostfix(char prefix[], char postfix[]) {

    char op1[MAX], op2[MAX], temp[MAX];

    int i;

    // Scan from RIGHT to LEFT
    for (i = strlen(prefix) - 1; i >= 0; i--) {

        // If operand ? push
        if (isalnum(prefix[i])) {
            temp[0] = prefix[i];
            temp[1] = '\0';
            push(temp);
        }

        // If operator
        else if (isOperator(prefix[i])) {

            // Pop two operands
            pop(op1);
            pop(op2);

            // Form: op1 op2 operator
            strcpy(temp, op1);
            strcat(temp, op2);

            int len = strlen(temp);
            temp[len] = prefix[i];
            temp[len + 1] = '\0';

            // Push result
            push(temp);
        }
    }

    // Final result
    pop(postfix);
}

int main() {

    char prefix[MAX], infix[MAX], postfix[MAX];

    printf("Enter Prefix Expression: ");
    gets(prefix);   // as per requirement

    // Convert to INFIX
    top = -1;
    prefixToInfix(prefix, infix);

    // Convert to POSTFIX
    top = -1;
    prefixToPostfix(prefix, postfix);

    printf("\nInfix Expression: %s", infix);
    printf("\nPostfix Expression: %s", postfix);

    return 0;
}