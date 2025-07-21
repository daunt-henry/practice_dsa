/*
Title: Remove All Adjacent Duplicates in String

Description:
  Given a string, repeatedly remove adjacent duplicate characters until no more can be removed.

Example Input:
  s = "abbaca"

Example Output:
  "ca"

Explanation:
  - "abbaca" → remove "bb" → "aaca"
  - "aaca" → remove "aa" → "ca"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeDuplicates(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc((len + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (top >= 0 && stack[top] == s[i]) {
            top--;  // remove duplicate
        } else {
            stack[++top] = s[i];  // push current char
        }
    }

    stack[top + 1] = '\0';
    return stack;
}

int main() {
    char input1[] = "abbaca";
    printf("Input: %s\n", input1);
    printf("Output: %s\n", removeDuplicates(input1));  // Expected: "ca"

    char input2[] = "azxxzy";
    printf("Input: %s\n", input2);
    printf("Output: %s\n", removeDuplicates(input2));  // Expected: "ay"

    char input3[] = "a";
    printf("Input: %s\n", input3);
    printf("Output: %s\n", removeDuplicates(input3));  // Expected: "a"

    return 0;
}
