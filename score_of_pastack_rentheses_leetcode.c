/*
Title: Score of Parentheses

Description:
  Given a balanced parentheses string `s`, compute the score based on the following rules:
    - "()" has score 1
    - AB has score A + B, where A and B are balanced parentheses strings
    - (A) has score 2 * A

Example Input:
  s = "(()(()))"

Example Output:
  6

Explanation:
  - "(()(()))" = 2 + (2 * 1) = 6
*/

#include <stdio.h>
#include <stdlib.h>

int scoreOfParentheses(char* s) {
    int stack[100];
    int top = -1;
    stack[++top] = 0;

    for (int i = 0; s[i]; ++i) {
        if (s[i] == '(') {
            stack[++top] = 0;
        } else {
            int v = stack[top--];
            int score = (v == 0) ? 1 : 2 * v;
            stack[top] += score;
        }
    }

    return stack[top];
}

int main() {
    char s1[] = "(()(()))";
    printf("Input: %s\n", s1);
    printf("Score: %d\n", scoreOfParentheses(s1)); // Expected: 6

    char s2[] = "()()";
    printf("Input: %s\n", s2);
    printf("Score: %d\n", scoreOfParentheses(s2)); // Expected: 2

    return 0;
}
