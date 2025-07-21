/*
Title: Remove Outermost Parentheses

Description:
  A valid parentheses string is composed of several primitive valid parentheses strings.
  Remove the outermost parentheses of every primitive string in the input.

Example Input:
  s = "(()())(())"

Example Output:
  "()()()"

Explanation:
  - "(()())" becomes "()()"
  - "(())" becomes "()"
  Final result: "()()()"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeOuterParentheses(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0, depth = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            if (depth > 0) result[index++] = '(';
            depth++;
        } else {
            depth--;
            if (depth > 0) result[index++] = ')';
        }
    }

    result[index] = '\0';
    return result;
}

int main() {
    char input1[] = "(()())(())";
    printf("Input: %s\n", input1);
    printf("Output: %s\n", removeOuterParentheses(input1)); // Expected: "()()()"

    char input2[] = "(()())(())(()(()))";
    printf("Input: %s\n", input2);
    printf("Output: %s\n", removeOuterParentheses(input2)); // Expected: "()()()()(())"

    char input3[] = "()()";
    printf("Input: %s\n", input3);
    printf("Output: %s\n", removeOuterParentheses(input3)); // Expected: ""

    return 0;
}
