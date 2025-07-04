/*
Check If a String Can Break Another String

Problem:
- Two strings `s1` and `s2` are said to break each other if after sorting both,
  for every index i, `s1[i] >= s2[i]` OR `s2[i] >= s1[i]`.
- Return true if one string can break the other.

Approach:
- Sort both strings.
- Compare each character at same index.
- If either s1 always >= s2 or s2 always >= s1, return true.

Time: O(n log n) — for sorting
Space: O(1) extra (in-place sort allowed)

Example:
Input: s1 = "abc", s2 = "xya"
Sorted: s1 = "abc", s2 = "axy"
Check: s2 breaks s1 → true
Output: true
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int cmpChar(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

bool checkIfCanBreak(char* s1, char* s2) {
    int len = strlen(s1);
    qsort(s1, len, sizeof(char), cmpChar);
    qsort(s2, len, sizeof(char), cmpChar);

    int can_s1_break_s2 = 1, can_s2_break_s1 = 1;

    for (int i = 0; i < len; i++) {
        if (s1[i] < s2[i]) can_s1_break_s2 = 0;
        if (s2[i] < s1[i]) can_s2_break_s1 = 0;
    }

    return can_s1_break_s2 || can_s2_break_s1;
}
