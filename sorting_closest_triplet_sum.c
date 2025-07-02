/*
Problem: Find the triplet in an array whose sum is closest to a given target.

Description:
Given an array of integers and a target value, find the sum of three integers
in the array such that the sum is closest to the target.

You must return exactly one such closest sum.
Assume that there is exactly one solution.

Example:
Input: nums = [-1, 2, 1, -4], target = 1
Output: 2

Explanation:
The sum that is closest to 1 is 2. (-1 + 2 + 1 = 2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Comparison function for sorting
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to find the closest sum of any three numbers
int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);
    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1, right = numsSize - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            if (abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum;
            }

            if (currentSum < target)
                left++;
            else if (currentSum > target)
                right--;
            else
                return target; // exact match
        }
    }

    return closestSum;
}

// Main function to test locally
int main() {
    int nums[] = {-1, 2, 1, -4};
    int target = 1;
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = threeSumClosest(nums, size, target);
    printf("Closest triplet sum to %d is: %d\n", target, result);

    return 0;
}

/*
========= OUTPUT =========
Closest triplet sum to 1 is: 2
==========================
*/
