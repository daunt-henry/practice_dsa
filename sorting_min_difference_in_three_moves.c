/*
Minimum Difference Between Largest and Smallest Value in Three Moves

Problem:
- You can modify at most 3 elements in the array.
- Find the minimum possible difference between the largest and smallest values after these 3 moves.

Approach:
- Sort the array.
- Try removing:
  1. the 3 largest elements
  2. the 2 largest and 1 smallest
  3. the 1 largest and 2 smallest
  4. the 3 smallest elements
- Return the minimum of these differences.

Time: O(n log n)
Space: O(1)

Example:
Input: [5,3,2,4]
Output: 0
Explanation: Change any 3 numbers to 4 → array becomes [4,4,4,4], diff = 0
*/

#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minDifference(int* nums, int numsSize) {
    if (numsSize <= 4) return 0;

    qsort(nums, numsSize, sizeof(int), cmp);

    int diff1 = nums[numsSize - 1] - nums[3];
    int diff2 = nums[numsSize - 2] - nums[2];
    int diff3 = nums[numsSize - 3] - nums[1];
    int diff4 = nums[numsSize - 4] - nums[0];

    int min = diff1;
    if (diff2 < min) min = diff2;
    if (diff3 < min) min = diff3;
    if (diff4 < min) min = diff4;

    return min;
}
