/*
Title: Minimum Remove to Make Valid Parentheses

Description:
  Given a string s of '(', ')' and lowercase letters, remove the minimum number 
  of parentheses to make the input string valid.

A string is valid if:
  - Open parentheses are closed by the same type of parentheses.
  - Open parentheses are closed in the correct order.

Example Input:
  s = "a)b(c)d"

Example Output:
  "ab(c)d"

Explanation:
  - Remove the unmatched ')' at index 1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* minRemoveToMakeValid(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc(len + 1);
    int* stack = (int*)malloc(sizeof(int) * len);
    int top = -1;
    int* valid = (int*)calloc(len, sizeof(int));

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else if (s[i] == ')') {
            if (top != -1) {
                valid[stack[top--]] = 1;
                valid[i] = 1;
            }
        } else {
            valid[i] = 1;
        }
    }

    int j = 0;
    for (int i = 0; i < len; i++) {
        if (valid[i]) {
            result[j++] = s[i];
        }
    }

    result[j] = '\0';
    free(stack);
    free(valid);
    return result;
}

int main() {
    char s1[] = "a)b(c)d";
    printf("Input: %s\n", s1);
    printf("Output: %s\n", minRemoveToMakeValid(s1));  // Expected: "ab(c)d"

    char s2[] = "))((";
    printf("Input: %s\n", s2);
    printf("Output: %s\n", minRemoveToMakeValid(s2));  // Expected: ""

    char s3[] = "(a(b(c)d)";
    printf("Input: %s\n", s3);
    printf("Output: %s\n", minRemoveToMakeValid(s3));  // Expected: "a(b(c)d)"

    return 0;
}
