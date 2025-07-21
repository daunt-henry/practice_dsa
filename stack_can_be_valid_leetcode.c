/*
Title: Check if a Parentheses String Can Be Valid

Description:
  A parentheses string s is valid if:
    - It is the empty string,
    - It can be written as AB (A and B are valid),
    - Or it can be written as (A), where A is valid.

  Given a string s and a string locked, where:
    - locked[i] == '1' means s[i] is locked and cannot be changed.
    - locked[i] == '0' means s[i] can be either '(' or ')'.

  Return true if it is possible to make s valid, else false.

Example:
  Input: s = "))()(", locked = "01011"
  Output: true

Constraints:
  - n == s.length == locked.length
  - n is even
  - 1 <= n <= 10^5
  - s[i] is '(' or ')'
  - locked[i] is '0' or '1'
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool canBeValid(char * s, char * locked){
    int n = strlen(s);
    if (n % 2 != 0) return false;

    int balance = 0;

    // Forward check
    for (int i = 0; i < n; ++i) {
        if (locked[i] == '0' || s[i] == '(') balance++;
        else balance--;
        if (balance < 0) return false;
    }

    balance = 0;

    // Backward check
    for (int i = n - 1; i >= 0; --i) {
        if (locked[i] == '0' || s[i] == ')') balance++;
        else balance--;
        if (balance < 0) return false;
    }

    return true;
}

int main() {
    char s[] = "))()(";
    char locked[] = "01011";
    bool valid = canBeValid(s, locked);
    printf("Output: %s\n", valid ? "true" : "false"); // Output: true
    return 0;
}
