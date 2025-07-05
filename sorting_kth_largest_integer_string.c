/*
Problem:
Find the Kth Largest Integer in the Array

You are given an array of strings `nums` where each string represents a positive integer.
Return the kth largest integer in the array.

Since the integers are too large, compare based on string length first, then lexicographically.

Approach:
- Use qsort with a custom comparator:
  - First by length of strings.
  - Then use strcmp to compare equal-length strings.

Example:
Input: nums = ["3", "6", "7", "10"], k = 4
Output: "3"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    char* sa = *(char**)a;
    char* sb = *(char**)b;

    int lenA = strlen(sa);
    int lenB = strlen(sb);

    if (lenA != lenB)
        return lenA - lenB;

    return strcmp(sa, sb);
}

char* kthLargestNumber(char** nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(char*), compare);
    return nums[numsSize - k];
}

/*
Sample Input:
nums = ["3", "6", "7", "10"], k = 4

Sample Output:
"3"
*/
