/*
Enter Postfix Expression: ABCD-*+EFG*-/

Infix Expression: ((A+(B*(C-D)))/(E-(F*G)))
Prefix Expression: /+A*B-CD-E*FG
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack to store strings 
char stack[MAX][MAX];
int top = -1;

// PUSH function 
void push(char str[]) {

    // Check overflow
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    // Step 1: increase top
    top = top + 1;

    // Step 2: copy string into stack
    strcpy(stack[top], str);
}

// POP function
void pop(char str[]) {

    // Check underflow
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    // Step 1: copy top element
    strcpy(str, stack[top]);

    // Step 2: decrease top
    top = top - 1;
}

// Check if operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// POSTFIX ? INFIX
void postfixToInfix(char postfix[], char infix[]) {

    char op1[MAX], op2[MAX], temp[MAX];
    int i;

    // Scan LEFT ? RIGHT
    for (i = 0; postfix[i] != '\0'; i++) {

        // If operand ? push
        if (isalnum(postfix[i])) {
            temp[0] = postfix[i];
            temp[1] = '\0';
            push(temp);
        }

        // If operator
        else if (isOperator(postfix[i])) {

            // Pop two operands
            pop(op2);   // IMPORTANT: second operand first
            pop(op1);   // then first operand

            // Form: (op1 operator op2)
            strcpy(temp, "(");
            strcat(temp, op1);

            int len = strlen(temp);
            temp[len] = postfix[i];
            temp[len + 1] = '\0';

            strcat(temp, op2);
            strcat(temp, ")");

            // Push result
            push(temp);
        }
    }

    // Final result
    pop(infix);
}

// POSTFIX ? PREFIX
void postfixToPrefix(char postfix[], char prefix[]) {

    char op1[MAX], op2[MAX], temp[MAX];
    int i;

    // Scan LEFT ? RIGHT
    for (i = 0; postfix[i] != '\0'; i++) {

        // Operand
        if (isalnum(postfix[i])) {
            temp[0] = postfix[i];
            temp[1] = '\0';
            push(temp);
        }

        // Operator
        else if (isOperator(postfix[i])) {

            // Pop two operands
            pop(op2);
            pop(op1);

            // Form: operator op1 op2
            temp[0] = postfix[i];
            temp[1] = '\0';

            strcat(temp, op1);
            strcat(temp, op2);

            // Push result
            push(temp);
        }
    }

    // Final result
    pop(prefix);
}

int main() {

    char postfix[MAX], infix[MAX], prefix[MAX];

    printf("Enter Postfix Expression: ");
    gets(postfix);   

    // Convert to INFIX
    top = -1;
    postfixToInfix(postfix, infix);

    // Convert to PREFIX
    top = -1;
    postfixToPrefix(postfix, prefix);

    printf("\nInfix Expression: %s", infix);
    printf("\nPrefix Expression: %s", prefix);

    return 0;
}