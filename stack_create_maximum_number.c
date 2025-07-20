// Create Maximum Number
// Select k digits from two arrays (preserving order) to form the largest possible number

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

// Return the max subsequence of length k
int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
    int* stack = (int*)malloc(sizeof(int) * k);
    int top = -1;
    int drop = numsSize - k;

    for (int i = 0; i < numsSize; i++) {
        while (top >= 0 && drop > 0 && stack[top] < nums[i]) {
            top--;
            drop--;
        }
        if (top + 1 < k)
            stack[++top] = nums[i];
        else
            drop--;
    }

    *returnSize = k;
    return stack;
}

// Compare remaining subsequences
int greater(int* nums1, int i, int* nums2, int j, int n1, int n2) {
    while (i < n1 && j < n2 && nums1[i] == nums2[j]) {
        i++;
        j++;
    }
    if (j == n2) return 1;
    if (i < n1 && nums1[i] > nums2[j]) return 1;
    return 0;
}

// Merge two subsequences into the max one
int* merge(int* nums1, int n1, int* nums2, int n2, int* returnSize) {
    int* merged = (int*)malloc(sizeof(int) * (n1 + n2));
    int i = 0, j = 0, k = 0;

    while (i < n1 || j < n2) {
        if (greater(nums1, i, nums2, j, n1, n2))
            merged[k++] = nums1[i++];
        else
            merged[k++] = nums2[j++];
    }

    *returnSize = n1 + n2;
    return merged;
}

// Main function to create the max number from two arrays
int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    int* result = (int*)calloc(k, sizeof(int));
    *returnSize = k;

    for (int i = max(0, k - nums2Size); i <= k && i <= nums1Size; i++) {
        int size1, size2, mergedSize;
        int* sub1 = maxSubsequence(nums1, nums1Size, i, &size1);
        int* sub2 = maxSubsequence(nums2, nums2Size, k - i, &size2);
        int* merged = merge(sub1, size1, sub2, size2, &mergedSize);

        if (greater(merged, 0, result, 0, k, k)) {
            for (int j = 0; j < k; j++)
                result[j] = merged[j];
        }

        free(sub1);
        free(sub2);
        free(merged);
    }

    return result;
}

int main() {
    int nums1[] = {3, 4, 6, 5};
    int nums2[] = {9, 1, 2, 5, 8, 3};
    int k = 5;
    int returnSize;

    int* result = maxNumber(nums1, 4, nums2, 6, k, &returnSize);

    printf("Max number: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
