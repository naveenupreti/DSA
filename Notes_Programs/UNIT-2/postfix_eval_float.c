/*
C program to evaluate a postfix expression that supports:
	Multi-digit numbers
	Negative numbers
	Decimal (floating-point) numbers
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack for float values (to support decimals)
float stack[MAX];
int top = -1;

// Push value into stack
void push(float value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

// Pop value from stack
float pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return 0;   // return safe value
    }
    return stack[top--];
}

// Evaluate postfix expression
float evaluatePostfix(char exp[]) {

    int i = 0;

    while (exp[i] != '\0') {

        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        /* -----------------------------------
           CASE 1: NUMBER (int / decimal / negative)
           ----------------------------------- */

        // Detect number:
        // digit OR '.' OR '-' used as sign at start of token
        if (isdigit(exp[i]) || exp[i] == '.' ||
           (exp[i] == '-' && (i == 0 || exp[i-1] == ' ') &&
           (isdigit(exp[i+1]) || exp[i+1] == '.'))) {

            int sign = 1;

            // Handle negative sign
            if (exp[i] == '-') {
                sign = -1;
                i++;   // move to actual number
            }

            float num = 0;

            // Build integer part
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            // Build decimal part
            if (exp[i] == '.') {
                float frac = 0, divisor = 1;
                i++;

                while (isdigit(exp[i])) {
                    frac = frac * 10 + (exp[i] - '0');
                    divisor *= 10;
                    i++;
                }

                num += frac / divisor;
            }

            // Apply sign and push
            push(sign * num);
        }

        /* -----------------------------------
           CASE 2: OPERATOR
           ----------------------------------- */
        else {

            // Ensure enough operands exist
            if (top < 1) {
                printf("Error: Invalid expression\n");
                return 0;
            }

            float val2 = pop();  // second operand
            float val1 = pop();  // first operand

            float result;

            switch (exp[i]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;

                // Modulus only for integers
                case '%': result = (int)val1 % (int)val2; break;

                default:
                    printf("Invalid operator: %c\n", exp[i]);
                    return 0;
            }

            push(result);
            i++;   // move ahead
        }
    }

    // Final result should be only one element
    if (top != 0) {
        printf("Error: Invalid postfix expression\n");
        return 0;
    }

    return pop();
}

int main() {

    char exp[MAX];

    printf("Enter postfix expression (space separated):\n");

    // Read full line input
    fgets(exp, MAX, stdin);

    // Remove newline character added by fgets()
    exp[strcspn(exp, "\n")] = '\0';

    float result = evaluatePostfix(exp);

    printf("Result = %.2f\n", result);

    return 0;
}

/*
Enter postfix expression (space separated):
-12.5 2 3 + *
Result = -62.50
*/
