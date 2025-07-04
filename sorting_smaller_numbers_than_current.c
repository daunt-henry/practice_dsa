/*
How Many Numbers Are Smaller Than the Current Number

Problem:
- For each element in the array, count how many numbers are smaller than it.

Approach:
- Count frequency of each number (0 to 100).
- Use prefix sum to find how many numbers are smaller.
- Map result based on prefix sum.

Time: O(n + k), where k = 101
Space: O(k) for frequency array

Example:
Input:  [8, 1, 2, 2, 3]
Output: [4, 0, 1, 1, 3]
*/

#include <stdlib.h>

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int freq[101] = {0};  // For numbers 0 to 100

    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    for (int i = 1; i < 101; i++) {
        freq[i] += freq[i - 1];
    }

    int* result = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i] == 0 ? 0 : freq[nums[i] - 1];
    }

    *returnSize = numsSize;
    return result;
}
