/*
Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Example:
Input: nums = [1,2,3]
Output: [1,3,2]

Input: nums = [3,2,1]
Output: [1,2,3]

Filename: next_permutation.c
*/

#include <stdio.h>

// Swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Reverse subarray nums[start..end]
void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

// Main function to compute next permutation
void nextPermutation(int* nums, int numsSize){
    int i = numsSize - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;

    if (i >= 0) {
        int j = numsSize - 1;
        while (nums[j] <= nums[i]) j--;
        swap(&nums[i], &nums[j]);
    }

    reverse(nums, i + 1, numsSize - 1);
}

// Sample test
int main() {
    int nums[] = {1, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);

    nextPermutation(nums, size);

    printf("Next Permutation: [");
    for (int i = 0; i < size; i++) {
        if (i > 0) printf(", ");
        printf("%d", nums[i]);
    }
    printf("]\n");

    return 0;
}
