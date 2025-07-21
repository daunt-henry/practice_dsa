/*
Title: Smallest Subsequence of Distinct Characters

Description:
  Return the lexicographically smallest subsequence of the input string `s` 
  that contains all the distinct characters of `s` exactly once.

Example Input:
  s = "cbacdcbc"

Example Output:
  "acdb"

Explanation:
  - All distinct letters: c, b, a, d
  - Lexicographically smallest valid order with all unique: "acdb"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* smallestSubsequence(char* s) {
    int n = strlen(s);
    int lastIndex[26] = {0};
    bool inStack[26] = {false};

    for (int i = 0; i < n; i++) {
        lastIndex[s[i] - 'a'] = i;
    }

    char* stack = (char*)malloc(n + 1);
    int top = -1;

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (inStack[c - 'a']) continue;

        while (top >= 0 && stack[top] > c && lastIndex[stack[top] - 'a'] > i) {
            inStack[stack[top--] - 'a'] = false;
        }

        stack[++top] = c;
        inStack[c - 'a'] = true;
    }

    stack[top + 1] = '\0';
    return stack;
}

int main() {
    char input1[] = "cbacdcbc";
    printf("Input: %s\n", input1);
    printf("Output: %s\n", smallestSubsequence(input1)); // Expected: "acdb"

    char input2[] = "bcabc";
    printf("Input: %s\n", input2);
    printf("Output: %s\n", smallestSubsequence(input2)); // Expected: "abc"

    return 0;
}
