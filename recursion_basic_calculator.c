/*
Problem:
Implement a basic calculator to evaluate expressions like:
"1 + (2 - (3 + 4))"

Only digits, '+', '-', '(', ')', and whitespace are allowed.

Approach:
Use a stack to save previous result and sign before entering parentheses.
Use variables to track current number, sign, and result.

Time Complexity: O(n)
Space Complexity: O(n) — due to stack
*/

#include <stdio.h>
#include <ctype.h>

int calculate(char* s) {
    int stack[1000], top = -1;
    int result = 0, sign = 1, num = 0;

    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        } else if (s[i] == '+') {
            result += sign * num;
            sign = 1;
            num = 0;
        } else if (s[i] == '-') {
            result += sign * num;
            sign = -1;
            num = 0;
        } else if (s[i] == '(') {
            stack[++top] = result;
            stack[++top] = sign;
            result = 0;
            sign = 1;
        } else if (s[i] == ')') {
            result += sign * num;
            result *= stack[top--]; // sign
            result += stack[top--]; // previous result
            num = 0;
        }
    }

    result += sign * num;
    return result;
}

// Demo
int main() {
    char expr[] = "1 + (2 - (3 + 4))";
    int res = calculate(expr);
    printf("Result of \"%s\" = %d\n", expr, res);
    return 0;
}
