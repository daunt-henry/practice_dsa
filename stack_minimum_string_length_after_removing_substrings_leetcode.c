/*
Title: Minimum String Length After Removing Substrings
Link: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/

You are given a string s. You can repeatedly remove "AB" or "CD" from it.
Return the minimum possible length of the resulting string.

Example:
Input: s = "ABFCACDB"
Output: 2
Explanation:
- Remove "AB" -> "FCACDB"
- Remove "CD" -> "FCAB"
- Remove "AB" -> "FC"
Remaining string has length 2.

Approach:
- Use a stack to simulate the removal process.
- If top of stack + current character forms "AB" or "CD", pop the top.
- Else, push current character to the stack.

Time Complexity: O(n)
*/

#include <stdio.h>
#include <string.h>

int minLength(char* s) {
    int top = -1;
    int len = strlen(s);
    char stack[len];

    for (int i = 0; i < len; i++) {
        if (top >= 0 && ((stack[top] == 'A' && s[i] == 'B') || (stack[top] == 'C' && s[i] == 'D'))) {
            top--;  // Remove "AB" or "CD"
        } else {
            stack[++top] = s[i];  // Push character
        }
    }

    return top + 1;
}

int main() {
    char s1[] = "ABFCACDB";
    printf("Input: \"%s\"\nOutput: %d\n", s1, minLength(s1)); // Output: 2

    char s2[] = "AABB";
    printf("Input: \"%s\"\nOutput: %d\n", s2, minLength(s2)); // Output: 2

    char s3[] = "CDAB";
    printf("Input: \"%s\"\nOutput: %d\n", s3, minLength(s3)); // Output: 0

    return 0;
}
