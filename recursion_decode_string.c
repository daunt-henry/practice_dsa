/*
Problem:
Given a string with encoding like "3[a2[c]]", decode and return the expanded string.

Example:
Input: "3[a2[c]]" → Output: "accaccacc"

Approach:
- Use recursion to handle nested encodings.
- Parse digits before '[' as repeat count.
- Recursively decode inside brackets.
- Concatenate result as we backtrack.

Time Complexity: O(n * k), where n is the length of string and k is the repeat multiplier.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decodeHelper(const char** s) {
    char* result = calloc(10000, sizeof(char));  // buffer
    int idx = 0;

    while (**s && **s != ']') {
        if (isdigit(**s)) {
            int k = 0;
            while (isdigit(**s)) {
                k = k * 10 + (*(*s) - '0');
                (*s)++;
            }
            (*s)++;  // skip '['
            char* decoded = decodeHelper(s);
            for (int i = 0; i < k; i++) {
                strcat(result, decoded);
                idx += strlen(decoded);
            }
            free(decoded);
            (*s)++;  // skip ']'
        } else {
            result[idx++] = *(*s);
            (*s)++;
        }
    }

    result[idx] = '\0';
    return result;
}

char* decodeString(char* s) {
    const char* ptr = s;
    return decodeHelper(&ptr);
}

// Demo
int main() {
    char input[] = "3[a2[c]]";
    char* output = decodeString(input);
    printf("Decoded string: %s\n", output);
    free(output);
    return 0;
}
