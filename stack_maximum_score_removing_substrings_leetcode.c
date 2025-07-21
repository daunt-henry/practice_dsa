/*
Title: Maximum Score From Removing Substrings

Description:
  You are given a string `s` and two integers `x` and `y`.
  You can perform two types of operations on `s`:
    - Remove substring "ab" and gain `x` points.
    - Remove substring "ba" and gain `y` points.
  Return the maximum score you can get after applying the operations optimally.

Example:
  Input: s = "cdbcbbaaabab", x = 4, y = 5
  Output: 19

Approach:
  - Use a greedy stack-based approach.
  - Always remove the higher scoring pattern first to maximize the total score.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removePattern(char* s, char a, char b, int score) {
    int top = -1, gain = 0;
    char* stack = (char*)malloc(sizeof(char) * (strlen(s) + 1));

    for (int i = 0; s[i]; i++) {
        if (top >= 0 && stack[top] == a && s[i] == b) {
            top--;
            gain += score;
        } else {
            stack[++top] = s[i];
        }
    }

    stack[++top] = '\0';
    strcpy(s, stack);
    free(stack);
    return gain;
}

int maximumGain(char* s, int x, int y) {
    int score = 0;

    if (x > y) {
        score += removePattern(s, 'a', 'b', x);
        score += removePattern(s, 'b', 'a', y);
    } else {
        score += removePattern(s, 'b', 'a', y);
        score += removePattern(s, 'a', 'b', x);
    }

    return score;
}

int main() {
    char s[] = "cdbcbbaaabab";
    int x = 4, y = 5;

    int result = maximumGain(s, x, y);
    printf("Maximum score after removing substrings: %d\n", result);
    return 0;
}
