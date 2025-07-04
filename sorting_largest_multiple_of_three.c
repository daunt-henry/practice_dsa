/*
Largest Multiple of Three

Problem:
- Given an array of digits, return the largest number (as a string) that is a multiple of 3.

Approach:
1. Count the sum of digits and use modulo 3 rules.
2. Remove smallest number(s) that make the sum divisible by 3.
3. Sort in descending order and build string.

Time: O(N log N) due to sorting
Space: O(N) for result string

Example:
Input: [8,1,9]
Output: "981"
*/

#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

char* largestMultipleOfThree(int* digits, int digitsSize) {
    int count[10] = {0};
    int sum = 0;

    for (int i = 0; i < digitsSize; ++i) {
        count[digits[i]]++;
        sum += digits[i];
    }

    int mod = sum % 3;

    if (mod != 0) {
        int found = 0;
        for (int i = 1; i <= 9 && !found; ++i) {
            if (i % 3 == mod && count[i]) {
                count[i]--;
                found = 1;
            }
        }
        if (!found) {
            int toRemove = 2;
            for (int i = 1; i <= 9 && toRemove > 0; ++i) {
                while (i % 3 == 3 - mod && count[i] && toRemove > 0) {
                    count[i]--;
                    toRemove--;
                }
            }
            if (toRemove > 0)
                return strdup("");
        }
    }

    char *res = (char *)malloc(digitsSize + 1);
    int pos = 0;
    for (int i = 9; i >= 0; --i) {
        while (count[i]--) {
            res[pos++] = i + '0';
        }
    }
    res[pos] = '\0';

    if (pos == 0)
        return strdup("");
    if (res[0] == '0')
        return strdup("0");

    return res;
}
