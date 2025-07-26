/*
Remove Duplicates from Sorted Array

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place
such that each unique element appears only once. The relative order of the elements should be kept the same.

Return the number of unique elements in nums.
Do not allocate extra space for another array; modify the input in-place with O(1) extra memory.

Example:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]

Filename: remove_duplicates_from_sorted_array.c
*/

#include <stdio.h>

// Function to remove duplicates in-place
int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 0) return 0;

    int index = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[index++] = nums[i];
        }
    }
    return index;
}

// Sample test
int main() {
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int size = sizeof(nums) / sizeof(nums[0]);

    int k = removeDuplicates(nums, size);
    printf("Output: %d, nums = [", k);
    for (int i = 0; i < k; i++) {
        if (i > 0) printf(", ");
        printf("%d", nums[i]);
    }
    printf("]\n");

    return 0;
}
