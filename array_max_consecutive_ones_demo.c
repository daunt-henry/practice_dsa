/*
Max Consecutive Ones (LeetCode 485)

Given a binary array consisting of only 0's and 1's, return the maximum number
of consecutive 1's in the array.

Approach:
Maintain two counters while scanning:
- curr: current streak of consecutive 1's
- maxLen: longest streak seen so far

If nums[i] == 1 → increment curr, update maxLen if needed
Else (nums[i] == 0) → reset curr to 0

Time Complexity: O(n), Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

// Function to find maximum number of consecutive 1's
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int maxLen = 0, curr = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            curr++;
            if (curr > maxLen) maxLen = curr;
        } else {
            curr = 0;
        }
    }
    return maxLen;
}

int main(void) {
    int arr1[] = {1, 1, 0, 1, 1, 1};
    int n1 = sizeof(arr1)/sizeof(int);
    printf("Output: %d (expected 3)\n", findMaxConsecutiveOnes(arr1, n1));

    int arr2[] = {0, 0, 0, 0};
    int n2 = sizeof(arr2)/sizeof(int);
    printf("Output: %d (expected 0)\n", findMaxConsecutiveOnes(arr2, n2));

    return 0;
}
