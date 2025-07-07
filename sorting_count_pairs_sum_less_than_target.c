/*
Problem:
Given an array of integers `nums` and an integer `target`,
return the number of pairs (i, j) such that:
- 0 <= i < j < nums.length
- nums[i] + nums[j] < target

Example Input:
nums = [1, 3, 5, 2, 8]
target = 7

Expected Output:
Number of valid pairs: 5
*/

#include <stdio.h>

int countPairs(int* nums, int numsSize, int target) {
    int count = 0;
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] < target)
                count++;
        }
    }
    return count;
}

int main() {
    int nums[] = {1, 3, 5, 2, 8};
    int target = 7;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = countPairs(nums, numsSize, target);
    printf("Number of valid pairs: %d\n", result);

    return 0;
}
