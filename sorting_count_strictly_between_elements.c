/*
Problem:
Given an array `nums`, return the count of elements that have both a strictly smaller and a strictly greater element in the array.

Approach:
- First, find the minimum and maximum elements in the array.
- Then, count how many elements are strictly greater than the min and strictly less than the max.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <stdio.h>

int countElements(int* nums, int numsSize){
    int min = nums[0], max = nums[0];
    for(int i = 1; i < numsSize; i++) {
        if(nums[i] < min) min = nums[i];
        if(nums[i] > max) max = nums[i];
    }

    int count = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != min && nums[i] != max) {
            count++;
        }
    }
    return count;
}

// Output Example:
// Input: nums = [11,7,2,15]
// Output: 2  (because 7 and 11 are strictly between 2 and 15)
