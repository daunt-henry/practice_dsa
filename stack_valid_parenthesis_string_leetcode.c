/*
Valid Parenthesis String

Given a string s containing only three types of characters: '(', ')' and '*',
return true if s is valid.

The rules for a valid string are:
- Every '(' must have a corresponding ')'.
- Every ')' must have a corresponding '('.
- '(' must come before ')'.
- '*' can be treated as '(', ')' or an empty string.

Examples:
Input: "()"
Output: true

Input: "(*)"
Output: true

Input: "(*))"
Output: true
*/

#include <stdio.h>
#include <stdbool.h>

bool checkValidString(char* s) {
    int low = 0, high = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            low++;
            high++;
        } else if (s[i] == ')') {
            if (low > 0) low--;
            high--;
        } else { // '*'
            if (low > 0) low--;
            high++;
        }

        if (high < 0) return false;
    }

    return low == 0;
}

// Test
int main() {
    char* tests[] = {"()", "(*)", "(*))", "((*)", "(((**))", "(*()"};
    int n = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < n; i++) {
        printf("Input: \"%s\" => Output: %s\n", tests[i], checkValidString(tests[i]) ? "true" : "false");
    }

    return 0;
}
