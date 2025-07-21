/*
Title: Make The String Great

Description:
  Given a string `s` of lower and upper case English letters,
  the string is called "good" if no two adjacent characters
  have the same letter but different cases (e.g., 'a' and 'A').

  You can repeatedly remove such adjacent pairs.
  Return the final "good" string after applying the process until
  no more such pairs exist.

Example:
  Input:  s = "leEeetcode"
  Output: "leetcode"

Explanation:
  The pair 'eE' is bad and gets removed.
  Remaining string becomes "leetcode".

Approach:
  - Use a stack-like array.
  - Compare top of stack with current char.
  - If they form a bad pair (diff = 32), pop.
  - Else, push to stack.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* makeGood(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(len + 1);
    int top = 0;

    for (int i = 0; s[i]; ++i) {
        if (top > 0 && abs(stack[top - 1] - s[i]) == 32)
            top--;
        else
            stack[top++] = s[i];
    }

    stack[top] = '\0';
    return stack;
}

int main() {
    char s[] = "leEeetcode";
    char* result = makeGood(s);
    printf("Final good string: %s\n", result);  // Output: "leetcode"
    free(result);
    return 0;
}
