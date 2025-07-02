/*
Problem: Intersection of Two Arrays II

Description:
Return the intersection of two arrays, including duplicate elements.
The result may be returned in any order.

Approach:
1. Sort both arrays
2. Use two-pointer technique to find common elements (including duplicates)

Time: O(n log n + m log m)
Space: O(min(n, m))
*/

#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);

    int* result = malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int i = 0, j = 0, k = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            result[k++] = nums1[i];
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }

    *returnSize = k;
    return result;
}

// Test
int main() {
    int nums1[] = {4, 9, 5};
    int nums2[] = {9, 4, 9, 8, 4};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize = 0;

    int* result = intersect(nums1, size1, nums2, size2, &returnSize);

    printf("Intersection with duplicates: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}

/*
========= OUTPUT =========
Intersection with duplicates: 4 9
==========================
*/
