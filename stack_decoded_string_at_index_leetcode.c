/*
Title: Decoded String at Index

Description:
  Given an encoded string `s` and an index `k`, return the k-th letter in the decoded string.
  The encoding rule is: `k[encoded_string]` means the `encoded_string` inside the square brackets is repeated `k` times.

Example Input:
  s = "leet2code3", k = 10

Example Output:
  "o"

Explanation:
  The decoded string is "leetleetcodeleetleetcodeleetleetcode", the 10th letter is "o"
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* decodeAtIndex(char* s, int k) {
    long long size = 0;
    int len = strlen(s);

    // First pass: compute total length of decoded string
    for (int i = 0; i < len; ++i) {
        if (isdigit(s[i])) {
            size *= s[i] - '0';
        } else {
            size += 1;
        }
    }

    // Second pass: reverse to locate the k-th letter
    for (int i = len - 1; i >= 0; --i) {
        k %= size;
        if (k == 0 && isalpha(s[i])) {
            static char res[2];
            res[0] = s[i];
            res[1] = '\0';
            return res;
        }

        if (isdigit(s[i])) {
            size /= s[i] - '0';
        } else {
            size--;
        }
    }

    return "";
}

int main() {
    char s1[] = "leet2code3";
    int k1 = 10;
    printf("Input: \"%s\", k = %d\n", s1, k1);
    printf("Output: \"%s\"\n", decodeAtIndex(s1, k1)); // Expected: "o"

    char s2[] = "ha22";
    int k2 = 5;
    printf("Input: \"%s\", k = %d\n", s2, k2);
    printf("Output: \"%s\"\n", decodeAtIndex(s2, k2)); // Expected: "h"

    return 0;
}
