// Question:
// Given an array nums and integer k, for each element you may increase or decrease it by up to k.
// After doing this to all elements, find the size of the largest group of equal numbers possible.
//
// Example:
// Input: nums = [4,6,1,2], k = 2
// Output: 3

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maximumBeauty(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int maxCount = 0, left = 0;
    
    for (int right = 0; right < numsSize; right++) {
        while (nums[right] - nums[left] > 2 * k) {
            left++;
        }
        int window = right - left + 1;
        if (window > maxCount) {
            maxCount = window;
        }
    }
    
    return maxCount;
}

int main() {
    int nums[] = {4, 6, 1, 2};
    int k = 2;
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int result = maximumBeauty(nums, size, k);
    printf("Output: %d\n", result); // Expected: 3

    return 0;
}
