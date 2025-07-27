/*
Problem: Remove Duplicates from Sorted Array II

Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. 
The relative order of the elements should be kept the same. 

Return the new length of the array after removing the extra duplicates.

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7
Modified nums = [0,0,1,1,2,3,3]

*/

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    if (numsSize <= 2) return numsSize;
    
    int index = 2;
    for (int i = 2; i < numsSize; i++) {
        if (nums[i] != nums[index - 2]) {
            nums[index++] = nums[i];
        }
    }
    return index;
}

int main() {
    int nums[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int newLen = removeDuplicates(nums, size);

    printf("New length: %d\n", newLen);
    printf("Modified array: ");
    for (int i = 0; i < newLen; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
