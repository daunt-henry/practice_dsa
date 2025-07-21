/*
Title: Construct Smallest Number From DI String

You are given a string 'pattern' of length n, consisting only of 'I' (increase) and 'D' (decrease).
You must return the lexicographically smallest permutation of numbers [1..n+1] that fits the pattern.

Example:
Input: pattern = "IDID"
Output: "13254"

Explanation:
- Start from left to right.
- Push numbers to stack and pop whenever 'I' is found or at end.

Approach:
- Use stack to reverse sequences of 'D'.
- For every index, push (i+1) to stack.
- When 'I' is found or end is reached, pop stack to result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* smallestNumber(char* pattern) {
    int n = strlen(pattern) + 1;
    char* res = (char*)malloc((n + 1) * sizeof(char));
    int stack[n], top = -1, idx = 0;

    for (int i = 0; i <= strlen(pattern); i++) {
        stack[++top] = i + 1;

        if (i == strlen(pattern) || pattern[i] == 'I') {
            while (top >= 0) {
                res[idx++] = stack[top--] + '0';
            }
        }
    }

    res[n] = '\0';
    return res;
}

int main() {
    char pattern[] = "IDID";
    char* result = smallestNumber(pattern);
    printf("Output: %s\n", result); // Expected: 13254
    free(result);
    return 0;
}
