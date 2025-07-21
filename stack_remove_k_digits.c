/*
Title: Remove K Digits

Problem:
Given a non-negative integer num represented as a string, remove k digits from the number 
so that the new number is the smallest possible.

Note:
- The result should not contain leading zeros unless the result is 0.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"

Example 2:
Input: num = "10200", k = 1
Output: "200"

Example 3:
Input: num = "10", k = 2
Output: "0"

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeKdigits(char* num, int k) {
    int n = strlen(num);
    char* stack = (char*)malloc(n + 1);
    int top = 0;

    for (int i = 0; i < n; i++) {
        while (top > 0 && k > 0 && stack[top - 1] > num[i]) {
            top--;
            k--;
        }
        stack[top++] = num[i];
    }

    // If still have k digits to remove
    top -= k;
    if (top < 0) top = 0;

    // Remove leading zeros
    int idx = 0;
    while (idx < top && stack[idx] == '0') idx++;

    int len = top - idx;
    if (len <= 0) {
        char* result = (char*)malloc(2);
        strcpy(result, "0");
        free(stack);
        return result;
    }

    char* result = (char*)malloc(len + 1);
    strncpy(result, stack + idx, len);
    result[len] = '\0';

    free(stack);
    return result;
}

// Test example
int main() {
    char num1[] = "1432219";
    int k1 = 3;
    printf("Result: %s\n", removeKdigits(num1, k1));  // Output: 1219

    char num2[] = "10200";
    int k2 = 1;
    printf("Result: %s\n", removeKdigits(num2, k2));  // Output: 200

    char num3[] = "10";
    int k3 = 2;
    printf("Result: %s\n", removeKdigits(num3, k3));  // Output: 0

    return 0;
}
