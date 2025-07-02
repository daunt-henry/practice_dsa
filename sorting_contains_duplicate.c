/*
Problem: Contains Duplicate

Description:
Given an integer array, return true if any value appears at least twice.
Return false if every element is distinct.

Example:
Input: [1, 2, 3, 1]
Output: true
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Compare function for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Check for duplicates
bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1) return false;

    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) return true;
    }

    return false;
}

// Test
int main() {
    int nums[] = {1, 2, 3, 1};
    int size = sizeof(nums) / sizeof(nums[0]);

    if (containsDuplicate(nums, size))
        printf("Contains Duplicate: true\n");
    else
        printf("Contains Duplicate: false\n");

    return 0;
}

/*
========= OUTPUT =========
Contains Duplicate: true
==========================
*/
