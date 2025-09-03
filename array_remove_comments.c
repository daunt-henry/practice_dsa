/*
Problem: Remove Comments
URL: https://leetcode.com/problems/remove-comments/

Description:
Given a C++ program, remove the line comments (//) and block comments (/* ... * /).
Return the program after removing comments.

Example:
Input:
[
  "/*Test program * /",
  "int main()",
  "{ ",
  "  // variable declaration ",
  "int a, b, c;",
  "/* This is a test",
  "   multiline  ",
  "   comment for ",
  "   testing * /",
  "a = b + c;",
  "}"
]

Output:
[
  "int main()",
  "{ ",
  "  ",
  "int a, b, c;",
  "a = b + c;",
  "}"
]
*/

#include <stdlib.h>
#include <string.h>

char** removeComments(char** source, int sourceSize, int* returnSize) {
    char** result = malloc(sourceSize * sizeof(char*));
    int resCount = 0;
    int block = 0;  // Flag: 1 if inside block comment, else 0
    char buffer[1000];  // Temporary buffer for current line
    int bufIdx = 0;

    for (int i = 0; i < sourceSize; i++) {
        char* line = source[i];
        int len = strlen(line);

        for (int j = 0; j < len; j++) {
            if (block) {
                if (j + 1 < len && line[j] == '*' && line[j+1] == '/') {
                    block = 0;
                    j++;
                }
            } else {
                if (j + 1 < len && line[j] == '/' && line[j+1] == '/') {
                    break;  // rest of line is comment
                }
                if (j + 1 < len && line[j] == '/' && line[j+1] == '*') {
                    block = 1;
                    j++;
                } else {
                    buffer[bufIdx++] = line[j];
                }
            }
        }

        if (!block && bufIdx > 0) {
            buffer[bufIdx] = '\0';
            result[resCount] = strdup(buffer);
            resCount++;
            bufIdx = 0;
        }
    }

    *returnSize = resCount;
    return result;
}

/* ----------------- Showcase Main ----------------- */
#include <stdio.h>

int main() {
    char* source[] = {
        "/*Test program */",
        "int main()",
        "{ ",
        "  // variable declaration ",
        "int a, b, c;",
        "/* This is a test",
        "   multiline  ",
        "   comment for ",
        "   testing */",
        "a = b + c;",
        "}"
    };
    int size = sizeof(source) / sizeof(source[0]);
    int returnSize;

    char** cleaned = removeComments(source, size, &returnSize);

    printf("Output after removing comments:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", cleaned[i]);
        free(cleaned[i]);
    }
    free(cleaned);

    return 0;
}
