/*
Title: Backspace String Compare

Description:
  Given two strings `s` and `t`, return true if they are equal when both are typed into empty text editors.
  '#' means a backspace character.

Example Input:
  s = "ab#c"
  t = "ad#c"

Example Output:
  true

Explanation:
  - s becomes "ac"
  - t becomes "ac"
  => They are equal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void build(char *s, char *result) {
    int i, j = 0;
    for (i = 0; s[i]; i++) {
        if (s[i] == '#') {
            if (j > 0) j--;
        } else {
            result[j++] = s[i];
        }
    }
    result[j] = '\0';
}

bool backspaceCompare(char *s, char *t) {
    char *res1 = (char *)malloc(strlen(s) + 1);
    char *res2 = (char *)malloc(strlen(t) + 1);
    build(s, res1);
    build(t, res2);
    bool equal = strcmp(res1, res2) == 0;
    free(res1);
    free(res2);
    return equal;
}

int main() {
    char s1[] = "ab#c";
    char t1[] = "ad#c";
    printf("Compare(\"%s\", \"%s\") = %s\n", s1, t1, backspaceCompare(s1, t1) ? "true" : "false");

    char s2[] = "a#c";
    char t2[] = "b";
    printf("Compare(\"%s\", \"%s\") = %s\n", s2, t2, backspaceCompare(s2, t2) ? "true" : "false");

    return 0;
}
