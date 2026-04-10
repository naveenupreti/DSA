/*
Enter Infix Expression: (A+B)*(C-D)

Postfix Expression: AB+CD-*
Prefix Expression: *+AB-CD
--------------------------------

Enter Infix Expression: (A+B*(C-D))/(E-F*G)

Postfix Expression: ABCD-*+EFG*-/
Prefix Expression: /+A*B-CD-E*FG
--------------------------------
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack for operators
char stack[MAX];
int top = -1;

// Push an element into stack
void push(char x) {
    stack[++top] = x;
}

// Pop an element from stack
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

// Check precedence of operators
int precedence(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

// Function to convert INFIX to POSTFIX
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {

        ch = infix[i];

        // If operand → add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        // If '(' → push to stack
        else if (ch == '(') {
            push(ch);
        }

        // If ')' → pop until '('
        else if (ch == ')') {
            while ((ch = pop()) != '(') {
                postfix[j++] = ch;
            }
        }

        // If operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // End string
}

// Function to reverse a string
void reverse(char exp[]) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(exp) - 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

// Function to convert INFIX to PREFIX
void infixToPrefix(char infix[], char prefix[]) {

    char temp[MAX];

    // Step 1: Reverse infix
    strcpy(temp, infix);
    reverse(temp);

    // Step 2: Replace ( with ) and vice versa
    for (int i = 0; temp[i]; i++) {
        if (temp[i] == '(')
            temp[i] = ')';
        else if (temp[i] == ')')
            temp[i] = '(';
    }

    // Step 3: Convert to postfix
    char postfix[MAX];
    top = -1;  // Reset stack
    infixToPostfix(temp, postfix);

    // Step 4: Reverse postfix → prefix
    reverse(postfix);
    strcpy(prefix, postfix);
}

int main() {

    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter Infix Expression: ");
    gets(infix);  

    // Convert to postfix
    top = -1;
    infixToPostfix(infix, postfix);

    // Convert to prefix
    top = -1;
    infixToPrefix(infix, prefix);

    printf("\nPostfix Expression: %s", postfix);
    printf("\nPrefix Expression: %s", prefix);

    return 0;
}
