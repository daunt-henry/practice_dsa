/*
Title: Check if Word is Valid After Substitutions

Description:
  Given a string `s`, determine if it is valid.
  A string is valid if it can be transformed into an empty string by repeatedly removing the substring "abc".

  Only the substring "abc" can be removed in each operation.

Example Input:
  s = "aabcbc"

Example Output:
  true

Explanation:
  After applying:
    "aabcbc" → remove "abc" → "abc" → remove "abc" → "" (empty)

  Thus, the string is valid.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    int n = strlen(s);
    char* stack = (char*)malloc(n * sizeof(char));
    int top = -1;

    for (int i = 0; s[i]; i++) {
        stack[++top] = s[i];
        if (top >= 2 && stack[top - 2] == 'a' && stack[top - 1] == 'b' && stack[top] == 'c') {
            top -= 3; // Remove "abc"
        }
    }

    free(stack);
    return top == -1;
}

int main() {
    char s[] = "aabcbc";
    printf("Input: \"%s\"\n", s);
    printf("Is Valid? %s\n", isValid(s) ? "true" : "false");  // Expected: true

    char s2[] = "abcabcababcc";
    printf("Input: \"%s\"\n", s2);
    printf("Is Valid? %s\n", isValid(s2) ? "true" : "false");  // Expected: true

    char s3[] = "abccba";
    printf("Input: \"%s\"\n", s3);
    printf("Is Valid? %s\n", isValid(s3) ? "true" : "false");  // Expected: false

    return 0;
}
