/*
Problem: Wiggle Sort II

Description:
Given an unsorted array nums, reorder it in-place so that:
    nums[0] < nums[1] > nums[2] < nums[3]...

Return any valid reordering that satisfies the wiggle condition.

Approach:
1. Sort a copy of the array.
2. Split into two halves:
   - Smaller half goes to even indices (from the end)
   - Larger half goes to odd indices (from the end)

Time Complexity: O(n log n)
Space Complexity: O(n)

Example:
Input:  [1, 5, 1, 1, 6, 4]
Output: [1, 6, 1, 5, 1, 4]
*/

#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// Wiggle sort function
void wiggleSort(int* nums, int numsSize) {
    int* temp = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        temp[i] = nums[i];
    }

    qsort(temp, numsSize, sizeof(int), cmp);

    int mid = (numsSize + 1) / 2;
    int j = mid - 1;       // pointer to smaller half
    int k = numsSize - 1;  // pointer to larger half

    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            nums[i] = temp[j--];
        } else {
            nums[i] = temp[k--];
        }
    }

    free(temp);
}

// Print array
void printArray(int* nums, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", nums[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// Test
int main() {
    int nums[] = {1, 5, 1, 1, 6, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Original array: ");
    printArray(nums, size);

    wiggleSort(nums, size);

    printf("Wiggle sorted:  ");
    printArray(nums, size);

    return 0;
}

/*
========= OUTPUT =========
Original array: [1, 5, 1, 1, 6, 4]
Wiggle sorted:  [1, 6, 1, 5, 1, 4]
==========================
*/
