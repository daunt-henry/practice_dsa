// sort_even_odd_indices_independently.c

/*
Problem:
You are given a 0-indexed integer array nums. Rearrange the values of nums
according to the following rules:

1. Sort the values at even indices of nums in non-decreasing order.
2. Sort the values at odd indices of nums in non-increasing order.
Return the array formed after rearranging the values of nums.

Example:
Input: nums = [4,1,2,3]
Output: [2,3,4,1]
*/

#include <stdio.h>
#include <stdlib.h>

// Comparator for ascending order
int cmp_asc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Comparator for descending order
int cmp_desc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int* sortEvenOdd(int* nums, int numsSize, int* returnSize){
    int evenCount = (numsSize + 1) / 2;
    int oddCount = numsSize / 2;
    int* even = (int*)malloc(sizeof(int) * evenCount);
    int* odd = (int*)malloc(sizeof(int) * oddCount);
    int i, j = 0, k = 0;

    // Separate even and odd indexed elements
    for(i = 0; i < numsSize; i++) {
        if(i % 2 == 0)
            even[j++] = nums[i];
        else
            odd[k++] = nums[i];
    }

    // Sort even indices in ascending and odd indices in descending
    qsort(even, evenCount, sizeof(int), cmp_asc);
    qsort(odd, oddCount, sizeof(int), cmp_desc);

    // Merge them back into original array
    j = k = 0;
    for(i = 0; i < numsSize; i++) {
        if(i % 2 == 0)
            nums[i] = even[j++];
        else
            nums[i] = odd[k++];
    }

    *returnSize = numsSize;
    free(even);
    free(odd);
    return nums;
}

/*
Test Case:
Input: nums = [4,1,2,3]
Output: [2,3,4,1]
*/
