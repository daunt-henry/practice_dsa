/*
Title: Smallest K-Length Subsequence With Occurrences of a Letter

Description:
  Given a string `s`, an integer `k`, a character `letter`, and an integer `repetition`,
  return the lexicographically smallest subsequence of length `k` that contains at least 
  `repetition` occurrences of `letter`.

Example:
  Input: s = "leet", k = 3, letter = 'e', repetition = 1
  Output: "eet"

  Input: s = "abcde", k = 3, letter = 'a', repetition = 1
  Output: "abc"

Constraints:
  - 1 <= s.length <= 10^5
  - 1 <= k <= s.length
  - s consists of lowercase English letters.
  - letter is a lowercase English letter.
  - 1 <= repetition <= k
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* smallestSubsequence(char* s, int k, char letter, int repetition) {
    int n = strlen(s);
    int totalLetter = 0;

    for (int i = 0; i < n; i++)
        if (s[i] == letter) totalLetter++;

    char* stack = malloc((k + 1) * sizeof(char));
    int top = 0;
    int remain = totalLetter;

    for (int i = 0; i < n; i++) {
        char c = s[i];

        while (top > 0 && stack[top - 1] > c &&
               (top - 1 + n - i >= k) &&
               ((stack[top - 1] != letter) || (remain > repetition))) {
            if (stack[top - 1] == letter)
                repetition++;
            top--;
        }

        if (top < k) {
            if (c == letter) {
                stack[top++] = c;
                repetition--;
            } else if (k - top > repetition) {
                stack[top++] = c;
            }
        }

        if (c == letter)
            remain--;
    }

    stack[top] = '\0';
    return stack;
}

int main() {
    char s[] = "leet";
    int k = 3;
    char letter = 'e';
    int repetition = 1;
    char* result = smallestSubsequence(s, k, letter, repetition);
    printf("Output: %s\n", result); // Output: "eet"
    free(result);
    return 0;
}
