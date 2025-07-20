/*
Title: Valid Parentheses


Description:
Given a string `s` containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

Example:
Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false
*/

#include <stdio.h>
#include <stdbool.h>

bool isValid(char* s) {
    char stack[10000];
    int top = -1;
    
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else {
            if (top == -1) return false;
            if ((s[i] == ')' && stack[top] != '(') ||
                (s[i] == '}' && stack[top] != '{') ||
                (s[i] == ']' && stack[top] != '[')) {
                return false;
            }
            top--;
        }
    }
    
    return top == -1;
}

int main() {
    char* s1 = "()[]{}";
    char* s2 = "(]";
    
    printf("Input: %s -> %s\n", s1, isValid(s1) ? "true" : "false");
    printf("Input: %s -> %s\n", s2, isValid(s2) ? "true" : "false");

    return 0;
}
