/*
Problem: Clear Digits


You are given a string s consisting of lowercase letters and digits.

You need to remove digits one by one. Each time a digit is found, remove that digit 
and also remove the character immediately **before** it.

Return the final string after processing.

Example:
Input:  s = "abc1d2"
Output: "a"

Explanation:
  '1' → remove 'c' and '1' → "ab"
  '2' → remove 'b' and '2' → "a"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* clearDigits(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(len + 1);
    int top = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (top > 0) top--;
        } else {
            stack[top++] = s[i];
        }
    }
    stack[top] = '\0';
    return stack;
}

// Sample test driver
int main() {
    char input[] = "abc1d2";
    char* result = clearDigits(input);
    printf("Result: %s\n", result);  // Output: "a"
    free(result);
    return 0;
}
