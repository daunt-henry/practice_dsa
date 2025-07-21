/*
Title: Removing Stars From a String

You are given a string 's'. Each time a '*' is found, remove it and the character before it.
Return the final string after all '*' operations are processed.

Example:
Input: s = "leet**cod*e"
Output: "lecoe"

Explanation:
- 't' and '*' are removed -> "lee*cod*e"
- 'e' and '*' removed -> "lecod*e"
- 'd' and '*' removed -> "lecoe"

Approach:
- Use a character array like a stack.
- Push normal characters.
- Pop on '*'.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeStars(char* s) {
    int n = strlen(s);
    char* res = (char*)malloc((n + 1) * sizeof(char));
    int top = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            if (top > 0) top--;
        } else {
            res[top++] = s[i];
        }
    }

    res[top] = '\0';
    return res;
}

int main() {
    char s[] = "leet**cod*e";
    char* result = removeStars(s);
    printf("Output: %s\n", result); // Expected: lecoe
    free(result);
    return 0;
}
