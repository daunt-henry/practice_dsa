/*
Problem: Sort Colors (Dutch National Flag Problem)

Description:
Given an array `nums` with n objects colored red (0), white (1), or blue (2),
sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white, and blue.

Do not use the library sort function.
Must solve it in one pass with constant space.

Example:
Input:  [2, 0, 2, 1, 1, 0]
Output: [0, 0, 1, 1, 2, 2]
*/

#include <stdio.h>

// Dutch National Flag algorithm
void sortColors(int* nums, int numsSize) {
    int low = 0, mid = 0, high = numsSize - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;
            high--;
        }
    }
}

// Main for testing
int main() {
    int nums[] = {2, 0, 2, 1, 1, 0};
    int size = sizeof(nums) / sizeof(nums[0]);

    sortColors(nums, size);

    printf("Sorted colors: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

/*
========= OUTPUT =========
Sorted colors: 0 0 1 1 2 2
==========================
*/
