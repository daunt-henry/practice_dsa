// Evaluate Reverse Polish Notation
// Given an array of strings tokens representing an RPN expression, evaluate it.
// Operators are "+", "-", "*", "/", and operands are integers.
// Sample Input: ["2","1","+","3","*"]
// Explanation: (2 + 1) * 3 = 9
// Output: 9

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char **tokens, int tokensSize) {
    int stack[tokensSize];
    int top = -1;
    
    for (int i = 0; i < tokensSize; i++) {
        char *token = tokens[i];
        
        if (strcmp(token, "+") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a + b;
        } else if (strcmp(token, "-") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a - b;
        } else if (strcmp(token, "*") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a * b;
        } else if (strcmp(token, "/") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a / b;
        } else {
            stack[++top] = atoi(token);
        }
    }
    
    return stack[top];
}

int main() {
    char *tokens[] = {"2", "1", "+", "3", "*"};
    int size = sizeof(tokens) / sizeof(tokens[0]);
    int result = evalRPN(tokens, size);
    printf("Result: %d\n", result); // Output: 9
    return 0;
}
