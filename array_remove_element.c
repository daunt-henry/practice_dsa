/*
Remove Element

Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
The order of the elements may be changed. Then return the number of elements that are not equal to val.

Do not allocate extra space for another array; you must do this by modifying the input array in-place with O(1) extra memory.

Example:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,3,0,4,_,_,_]

Filename: remove_element.c
*/

#include <stdio.h>

// Function to remove all occurrences of `val`
int removeElement(int* nums, int numsSize, int val){
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[index++] = nums[i];
        }
    }
    return index;
}

// Sample test
int main() {
    int nums[] = {0,1,2,2,3,0,4,2};
    int val = 2;
    int size = sizeof(nums) / sizeof(nums[0]);

    int k = removeElement(nums, size, val);
    printf("Output: %d, nums = [", k);
    for (int i = 0; i < k; i++) {
        if (i > 0) printf(", ");
        printf("%d", nums[i]);
    }
    printf("]\n");

    return 0;
}
