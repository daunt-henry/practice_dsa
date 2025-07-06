/*
Problem:
You are given an array `nums` and an integer `original`.
Every time you find `original` in `nums`, multiply it by 2.
Repeat this process until `original` is not found in `nums`.
Return the final value of `original`.

Approach:
- Keep checking if `original` exists in the array.
- If yes, multiply it by 2 and repeat.
- If no, return the value.

Time Complexity: O(n * log(original)) in worst case.
Space Complexity: O(1)
*/

#include <stdbool.h>

bool findInArray(int* arr, int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) return true;
    }
    return false;
}

int findFinalValue(int* nums, int numsSize, int original){
    while(findInArray(nums, numsSize, original)) {
        original *= 2;
    }
    return original;
}

// Output Example:
// Input: nums = [5,3,6,1,12], original = 3
// Output: 24  (3 -> 6 -> 12 -> 24)
