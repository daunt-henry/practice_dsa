/*
Title: Longest Valid Parentheses

Description:
Given a string containing just the characters '(' and ')',
find the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:
Input: s = ""
Output: 0
*/

#include <stdio.h>
#include <string.h>

int longestValidParentheses(char* s) {
    int maxLen = 0;
    int stack[100000];
    int top = -1;

    stack[++top] = -1;

    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;
            if (top == -1) {
                stack[++top] = i;
            } else {
                int len = i - stack[top];
                if (len > maxLen) maxLen = len;
            }
        }
    }

    return maxLen;
}

int main() {
    char* s1 = "(()";
    char* s2 = ")()())";

    printf("Input: %s -> Longest valid: %d\n", s1, longestValidParentheses(s1));
    printf("Input: %s -> Longest valid: %d\n", s2, longestValidParentheses(s2));

    return 0;
}
