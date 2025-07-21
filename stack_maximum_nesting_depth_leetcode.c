/*
Title: Maximum Nesting Depth of the Parentheses

Description:
  A string is a valid parentheses string (VPS) if:
    - It is an empty string "", or
    - It is "(" + A + ")", where A is a VPS, or
    - It is A + B, where A and B are VPSs.

  The nesting depth of a VPS is the maximum number of parentheses
  opened simultaneously.

Task:
  Given a VPS string `s`, return the maximum nesting depth.

Example:
  Input: s = "(1+(2*3)+((8)/4))+1"
  Output: 3

Approach:
  - Traverse the string.
  - Increment depth on '(' and decrement on ')'.
  - Track maximum depth during the traversal.

*/

#include <stdio.h>

int maxDepth(char * s){
    int max = 0, curr = 0;
    while (*s) {
        if (*s == '(') {
            curr++;
            if (curr > max) max = curr;
        } else if (*s == ')') {
            curr--;
        }
        s++;
    }
    return max;
}

int main() {
    char input[] = "(1+(2*3)+((8)/4))+1";
    int result = maxDepth(input);
    printf("Maximum nesting depth: %d\n", result);  // Output: 3
    return 0;
}
