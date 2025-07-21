/*
Title: Reverse Substrings Between Each Pair of Parentheses

Description:
  Given a string `s` containing characters and parentheses,
  reverse the substrings between each pair of matching parentheses starting from the innermost one.

  The final string should not contain any parentheses.

Example Input:
  s = "(u(love)i)"

Example Output:
  "iloveu"

Explanation:
  - Inner reversal: (love) → evol
  - Outer: (u[evol]i) → iloveu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseParentheses(char* s) {
    int len = strlen(s);
    int stack[2000], top = -1;
    int pair[2000];

    for (int i = 0; i < len; i++) {
        if (s[i] == '(')
            stack[++top] = i;
        else if (s[i] == ')') {
            int j = stack[top--];
            pair[i] = j;
            pair[j] = i;
        }
    }

    char* res = (char*)malloc(len + 1);
    int idx = 0, i = 0, dir = 1;

    while (i < len) {
        if (s[i] == '(' || s[i] == ')') {
            i = pair[i];
            dir = -dir;
        } else {
            res[idx++] = s[i];
        }
        i += dir;
    }

    res[idx] = '\0';
    return res;
}

int main() {
    char s1[] = "(u(love)i)";
    printf("Input: %s\n", s1);
    printf("Output: %s\n", reverseParentheses(s1));  // Expected: "iloveu"

    char s2[] = "(ed(et(oc))el)";
    printf("Input: %s\n", s2);
    printf("Output: %s\n", reverseParentheses(s2));  // Expected: "leetcode"

    return 0;
}
