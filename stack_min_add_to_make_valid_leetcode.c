/*
Title: Minimum Add to Make Parentheses Valid

Description:
  Given a string s of '(' and ')', return the minimum number of parentheses you must add to make the string valid.

  A string is valid if:
    - Open brackets are closed by the same type of brackets.
    - Open brackets are closed in the correct order.

Example Input:
  s = "()))(("

Example Output:
  4

Explanation:
  Add two '(' before the string and two ')' at the end to make it valid.
*/

#include <stdio.h>

int minAddToMakeValid(char* s) {
    int open = 0, add = 0;

    for (int i = 0; s[i]; ++i) {
        if (s[i] == '(') {
            open++;
        } else { // s[i] == ')'
            if (open > 0) {
                open--;
            } else {
                add++;
            }
        }
    }

    return add + open;
}

int main() {
    char s1[] = "()))((";
    printf("Input: %s\n", s1);
    printf("Minimum Additions: %d\n", minAddToMakeValid(s1)); // Expected: 4

    char s2[] = "(((";
    printf("Input: %s\n", s2);
    printf("Minimum Additions: %d\n", minAddToMakeValid(s2)); // Expected: 3

    char s3[] = "()";
    printf("Input: %s\n", s3);
    printf("Minimum Additions: %d\n", minAddToMakeValid(s3)); // Expected: 0

    return 0;
}
