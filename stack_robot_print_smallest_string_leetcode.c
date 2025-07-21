/*
Title: Using a Robot to Print the Lexicographically Smallest String

You are given a string s. You need to simulate a robot that can:
1. Push the first character of s to a stack (one by one).
2. Pop the top from the stack to build the output string.

Return the lexicographically smallest output string possible.

Example:
Input: s = "zza"
Output: "azz"

Approach:
- Count frequency of all characters.
- Push into a stack as we iterate.
- At each step, try to pop as many characters from the stack as possible,
  as long as no smaller character remains to come later.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* robotWithString(char* s) {
    int n = strlen(s);
    int freq[26] = {0};
    for (int i = 0; i < n; i++) freq[s[i] - 'a']++;

    char* stack = (char*)malloc(n + 1);
    int top = 0;

    char* result = (char*)malloc(n + 1);
    int resIndex = 0;

    for (int i = 0; i < n; i++) {
        stack[top++] = s[i];
        freq[s[i] - 'a']--;

        while (top > 0) {
            int canPop = 1;
            for (int c = 0; c < stack[top - 1] - 'a'; c++) {
                if (freq[c] > 0) {
                    canPop = 0;
                    break;
                }
            }
            if (canPop) {
                result[resIndex++] = stack[--top];
            } else {
                break;
            }
        }
    }

    while (top > 0) {
        result[resIndex++] = stack[--top];
    }

    result[resIndex] = '\0';
    free(stack);
    return result;
}

int main() {
    char s[] = "zza";
    char* output = robotWithString(s);
    printf("Output: %s\n", output); // Expected: azz
    free(output);
    return 0;
}
