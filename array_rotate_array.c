/*
Problem: Rotate Array

Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
*/

#include <stdio.h>

void reverse(int* nums, int start, int end) {
    while (start < end) {
        int tmp = nums[start];
        nums[start++] = nums[end];
        nums[end--] = tmp;
    }
}

void rotate(int* nums, int numsSize, int k){
    if (numsSize == 0 || k == 0) return;
    k = k % numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

// Sample test
int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    int n = sizeof(nums) / sizeof(nums[0]);

    rotate(nums, n, k);

    printf("Rotated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
