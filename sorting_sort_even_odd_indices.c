/*
Problem:
Sort elements at even indices in non-decreasing order,
and elements at odd indices in non-increasing order.

Approach:
1. Separate even and odd index elements.
2. Sort even indices in ascending order.
3. Sort odd indices in descending order.
4. Merge them back into original positions.

Time Complexity: O(N log N)
Space Complexity: O(N)

Example:
Input: [4,1,2,3]
Even indices: [4,2] -> sorted: [2,4]
Odd indices: [1,3] -> sorted: [3,1]
Output: [2,3,4,1]
*/

#include <stdio.h>
#include <stdlib.h>

int compareAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compareDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int* sortEvenOdd(int* nums, int numsSize, int* returnSize){
    int evenSize = (numsSize + 1) / 2;
    int oddSize = numsSize / 2;
    int* even = (int*)malloc(sizeof(int) * evenSize);
    int* odd = (int*)malloc(sizeof(int) * oddSize);
    
    for (int i = 0, e = 0, o = 0; i < numsSize; i++) {
        if (i % 2 == 0) even[e++] = nums[i];
        else odd[o++] = nums[i];
    }
    
    qsort(even, evenSize, sizeof(int), compareAsc);
    qsort(odd, oddSize, sizeof(int), compareDesc);
    
    for (int i = 0, e = 0, o = 0; i < numsSize; i++) {
        if (i % 2 == 0) nums[i] = even[e++];
        else nums[i] = odd[o++];
    }
    
    free(even);
    free(odd);
    
    *returnSize = numsSize;
    return nums;
}
