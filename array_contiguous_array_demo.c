/*
Contiguous Array (LeetCode 525)

Find the maximum length of a contiguous subarray with equal numbers of 0s and 1s.

Approach:
- Interpret 0 as -1, 1 as +1.
- Maintain a running sum (`prefix`), starting from 0.
- Map each `prefix` value to its earliest index.
- If the same `prefix` appears again later, the subarray in between sums to 0.
- Compute the length and track the maximum.

Time Complexity: O(n), Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int findMaxLength(int* nums, int numsSize) {
    int n = numsSize;
    int* map = malloc((2 * n + 1) * sizeof(int));
    for (int i = 0; i < 2 * n + 1; i++) map[i] = -2;
    int offset = n;
    map[offset] = -1;

    int maxLen = 0, sum = offset;
    for (int i = 0; i < n; i++) {
        sum += nums[i] ? 1 : -1;
        if (map[sum] >= -1) {
            int len = i - map[sum];
            if (len > maxLen) maxLen = len;
        } else {
            map[sum] = i;
        }
    }
    free(map);
    return maxLen;
}

int main(void) {
    int arr1[] = {0, 1};
    printf("max length = %d (expected 2)\n", findMaxLength(arr1, 2));

    int arr2[] = {0, 1, 0};
    printf("max length = %d (expected 2)\n", findMaxLength(arr2, 3));

    int arr3[] = {0, 0, 1, 0, 0, 0, 1, 1};
    printf("max length = %d (expected 4)\n", findMaxLength(arr3, 8));

    return 0;
}
