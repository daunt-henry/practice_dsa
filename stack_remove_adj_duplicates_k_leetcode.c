/*
Title: Remove All Adjacent Duplicates in String II

Description:
  Given a string `s` and an integer `k`, remove all k adjacent duplicates in the string until 
  no more such duplicates remain.

Example Input:
  s = "deeedbbcccbdaa", k = 3

Example Output:
  "aa"

Explanation:
  - "eee", "bbb", and "ccc" are removed as they appear 3 times.
  - After removals and re-checks, the remaining string is "aa".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeDuplicates(char* s, int k) {
    int len = strlen(s);
    char* res = (char*)malloc(len + 1);
    int* count = (int*)malloc(sizeof(int) * len);
    int i = 0;

    for (int j = 0; j < len; j++) {
        res[i] = s[j];
        count[i] = (i > 0 && res[i] == res[i - 1]) ? count[i - 1] + 1 : 1;
        if (count[i] == k)
            i -= k - 1;
        else
            i++;
    }

    res[i] = '\0';
    free(count);
    return res;
}

int main() {
    char s1[] = "deeedbbcccbdaa";
    int k1 = 3;
    printf("Input: %s, k = %d\n", s1, k1);
    printf("Output: %s\n", removeDuplicates(s1, k1));  // Expected: "aa"

    char s2[] = "pbbcggttciiippooaais";
    int k2 = 2;
    printf("Input: %s, k = %d\n", s2, k2);
    printf("Output: %s\n", removeDuplicates(s2, k2));  // Expected: "ps"

    return 0;
}
