/*
Title: Maximum Score of a Good Subarray

Description:
  Given an array of integers nums and an index k, return the maximum score of a good subarray.
  A good subarray is a subarray that contains the index k and has the minimum value of all elements
  in the subarray multiplied by its length.

Example:
  Input: nums = [1,4,3,7,4,5], k = 3
  Output: 15

Approach:
  - Expand outwards from index k.
  - At each step, move left or right depending on which side has a higher value.
  - Track the minimum in the current range and update the max score accordingly.
*/

#include <stdio.h>

int maximumScore(int* nums, int numsSize, int k) {
    int left = k, right = k;
    int minVal = nums[k];
    int maxScore = nums[k];

    while (left > 0 || right < numsSize - 1) {
        if ((left > 0 ? nums[left - 1] : -1) > (right < numsSize - 1 ? nums[right + 1] : -1)) {
            left--;
            if (nums[left] < minVal) minVal = nums[left];
        } else {
            right++;
            if (nums[right] < minVal) minVal = nums[right];
        }
        int score = minVal * (right - left + 1);
        if (score > maxScore) maxScore = score;
    }

    return maxScore;
}

int main() {
    int nums[] = {1, 4, 3, 7, 4, 5};
    int k = 3;
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = maximumScore(nums, size, k);
    printf("Maximum score of good subarray: %d\n", result);  // Output: 15
    return 0;
}
