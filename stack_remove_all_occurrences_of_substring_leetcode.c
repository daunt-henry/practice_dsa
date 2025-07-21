/*
Title: Remove All Occurrences of a Substring

Description:
  Given two strings `s` and `part`, remove all occurrences of `part` in `s`
  until no more occurrences can be removed. Return the final string.

Example:
  Input: s = "daabcbaabcbc", part = "abc"
  Output: "dab"

Approach:
  - Simulate a stack using a character array.
  - Iterate over the string and push characters onto the stack.
  - If the top of the stack matches the `part`, pop it.
  - Return the remaining stack as the result.

Constraints:
  - 1 <= s.length <= 1000
  - 1 <= part.length <= 100

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* removeOccurrences(char* s, char* part) {
    int lenS = strlen(s), lenP = strlen(part);
    char* stack = (char*)malloc(lenS + 1);
    int top = 0;

    for (int i = 0; i < lenS; ++i) {
        stack[top++] = s[i];

        if (top >= lenP && strncmp(&stack[top - lenP], part, lenP) == 0) {
            top -= lenP;
        }
    }

    stack[top] = '\0';
    return stack;
}

int main() {
    char s1[] = "daabcbaabcbc";
    char part1[] = "abc";
    printf("Input: \"%s\", Part: \"%s\"\n", s1, part1);
    printf("Output: \"%s\"\n", removeOccurrences(s1, part1)); // Output: "dab"

    char s2[] = "axxxxyyyyb";
    char part2[] = "xy";
    printf("Input: \"%s\", Part: \"%s\"\n", s2, part2);
    printf("Output: \"%s\"\n", removeOccurrences(s2, part2)); // Output depends on repeated removal

    return 0;
}
