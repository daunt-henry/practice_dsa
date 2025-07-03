/*
Problem:
Sort an integer array in ascending order using any efficient algorithm.

Approach:
- Use Merge Sort (divide and conquer)
- Time Complexity: O(n log n)
- Space Complexity: O(n) extra space for merging
*/

#include <stdio.h>
#include <stdlib.h>

void merge(int* nums, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int* L = malloc(n1 * sizeof(int));
    int* R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = nums[left + i];
    for (int i = 0; i < n2; i++) R[i] = nums[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        nums[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) nums[k++] = L[i++];
    while (j < n2) nums[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int* nums, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    mergeSort(nums, 0, numsSize - 1);
    *returnSize = numsSize;
    return nums;
}

// Test
int main() {
    int nums[] = {5, 2, 3, 1};
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* sorted = sortArray(nums, size, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", sorted[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    return 0;
}

/*
========= OUTPUT =========
Output: [1, 2, 3, 5]
==========================
*/
