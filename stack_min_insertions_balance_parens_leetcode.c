/*
Title: Minimum Insertions to Balance a Parentheses String

Description:
  Given a parentheses string `s` where each '(' needs to be closed with exactly two ')' characters,
  return the minimum number of insertions needed to balance the string.

Rules:
  - Each '(' requires exactly two ')'
  - Insertions can be made at any position

Example:
  Input:  s = "(()))"
  Output: 1

Explanation:
  One more ')' is needed after the second '(' to balance it as per rules.

Approach:
  - Use a greedy strategy by maintaining `right_needed` (how many ')' are required).
  - If an unmatched ')' is found, insert a '('.
  - At the end, add any remaining unmatched ')' to the result.

*/

#include <stdio.h>

int minInsertions(char* s) {
    int insertions = 0, right_needed = 0;

    for (int i = 0; s[i]; ++i) {
        if (s[i] == '(') {
            right_needed += 2;
            if (right_needed % 2 != 0) {
                insertions++;
                right_needed--;
            }
        } else {
            right_needed--;
            if (right_needed < 0) {
                insertions++;
                right_needed = 1;
            }
        }
    }

    return insertions + right_needed;
}

int main() {
    char* s = "(()))";
    int result = minInsertions(s);
    printf("Minimum insertions needed: %d\n", result);  // Output: 1
    return 0;
}
