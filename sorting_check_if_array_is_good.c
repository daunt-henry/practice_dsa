// Question:
// You are given an integer array nums. We say that the array is good if:
// - nums.length == n + 1, where n is some positive integer,
// - nums contains all integers in the range [1, n], and
// - The integer n appears exactly twice.
// Return true if the array is good, otherwise return false.
//
// Example:
// Input: nums = [2, 1, 3, 4, 4]
// Output: true

#include <stdio.h>
#include <stdbool.h>

bool isGood(int* nums, int numsSize){
    int count[100001] = {0};
    int maxVal = 0;

    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
        if (nums[i] > maxVal) maxVal = nums[i];
    }

    if (maxVal != numsSize - 1) return false;
    if (count[maxVal] != 2) return false;

    for (int i = 1; i < maxVal; i++) {
        if (count[i] != 1) return false;
    }

    return true;
}

int main() {
    int nums[] = {2, 1, 3, 4, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    if (isGood(nums, n))
        printf("Output: true\n");  // Expected Output: true
    else
        printf("Output: false\n");

    return 0;
}
