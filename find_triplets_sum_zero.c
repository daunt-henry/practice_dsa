/*
Problem: Find all unique triplets in an integer array that sum to 0.

Description:
Given an integer array, return all unique triplets [a, b, c] such that:
a + b + c == 0, and no duplicate triplets are allowed.

Example:
Input: nums = [-1, 0, 1, 2, -1, -4]
Output: [-1, -1, 2], [-1, 0, 1]
*/

#include <stdio.h>
#include <stdlib.h>

// Comparison function for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to find all unique triplets that sum to 0
int** findTriplets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int capacity = 1000;
    int **result = (int **)malloc(sizeof(int *) * capacity);
    *returnColumnSizes = (int *)malloc(sizeof(int) * capacity);

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                int *triplet = (int *)malloc(sizeof(int) * 3);
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];
                result[*returnSize] = triplet;
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (left < right && nums[left] == triplet[1]) left++;
                while (left < right && nums[right] == triplet[2]) right--;

                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = realloc(result, sizeof(int *) * capacity);
                    *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * capacity);
                }
            }
        }
    }

    return result;
}

// Main function to test the implementation
int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *returnColumnSizes;

    int **triplets = findTriplets(nums, numsSize, &returnSize, &returnColumnSizes);

    printf("Triplets that sum to zero:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d]\n", triplets[i][0], triplets[i][1], triplets[i][2]);
        free(triplets[i]);  // free memory
    }

    free(triplets);
    free(returnColumnSizes);

    return 0;
}

/*
========= OUTPUT =========
Triplets that sum to zero:
[-1, -1, 2]
[-1, 0, 1]
==========================
*/
