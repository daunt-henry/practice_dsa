/*
Title: Parsing a Boolean Expression

Description:
  Given a string expression representing a boolean expression,
  return the result of evaluating it.

  The expression can contain the following characters:
    - 't' for true, 'f' for false
    - '!' for NOT
    - '&' for AND
    - '|' for OR
    - Parentheses and commas for grouping

Example Input:
  expression = "|(&(t,f,t),!(t))"

Example Output:
  false

Explanation:
  - AND(t,f,t) → false
  - NOT(t) → false
  - OR(false, false) → false
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool parseBoolExpr(char* expression) {
    char stack[5000];
    int top = -1;

    for (int i = 0; expression[i]; i++) {
        char c = expression[i];
        if (c == ',' || c == '(') continue;
        if (c == ')') {
            int t = 0, f = 0;
            while (stack[top] != '!' && stack[top] != '&' && stack[top] != '|') {
                if (stack[top--] == 't') t++;
                else f++;
            }
            char op = stack[top--];
            if (op == '!') stack[++top] = f == 1 ? 't' : 'f';
            else if (op == '&') stack[++top] = f == 0 ? 't' : 'f';
            else if (op == '|') stack[++top] = t > 0 ? 't' : 'f';
        } else {
            stack[++top] = c;
        }
    }
    return stack[0] == 't';
}

int main() {
    char expr1[] = "|(&(t,f,t),!(t))";
    printf("Input: %s\n", expr1);
    printf("Output: %s\n", parseBoolExpr(expr1) ? "true" : "false");  // Expected: false

    char expr2[] = "!(&(f,t))";
    printf("Input: %s\n", expr2);
    printf("Output: %s\n", parseBoolExpr(expr2) ? "true" : "false");  // Expected: true

    return 0;
}
