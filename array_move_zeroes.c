/*
Problem: Move Zeroes

Given an array `nums`, write a function to move all 0’s to the end 
while maintaining the relative order of the non-zero elements.

Example:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int pos = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[pos++] = nums[i];
        }
    }
    while (pos < numsSize) {
        nums[pos++] = 0;
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int n = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, n);

    printf("After moving zeroes: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
