/*
Problem:
Return an array "counts" such that counts[i] is the number of elements smaller
than nums[i] to its right.

Approach:
Use a modified merge sort on index array:
- Sort by nums[index].
- When moving elements from the right half before left ones,
  increment a counter for how many smaller elements are seen.

Time: O(n log n), Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

static void merge_count(int indices[], int temp[], int counts[], int left, int mid, int right, int nums[]) {
    int i = left, j = mid + 1, k = left, right_count = 0;
    while (i <= mid && j <= right) {
        if (nums[indices[j]] < nums[indices[i]]) {
            temp[k++] = indices[j++];
            right_count++;
        } else {
            counts[indices[i]] += right_count;
            temp[k++] = indices[i++];
        }
    }
    while (i <= mid) {
        counts[indices[i]] += right_count;
        temp[k++] = indices[i++];
    }
    while (j <= right) {
        temp[k++] = indices[j++];
    }
    for (int p = left; p <= right; ++p)
        indices[p] = temp[p];
}

static void sort_and_count(int indices[], int temp[], int counts[], int left, int right, int nums[]) {
    if (left >= right) return;
    int mid = (left + right) >> 1;
    sort_and_count(indices, temp, counts, left, mid, nums);
    sort_and_count(indices, temp, counts, mid + 1, right, nums);
    merge_count(indices, temp, counts, left, mid, right, nums);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int *counts = calloc(numsSize, sizeof(int));
    int *indices = malloc(numsSize * sizeof(int));
    int *temp = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; ++i) indices[i] = i;

    sort_and_count(indices, temp, counts, 0, numsSize - 1, nums);

    free(indices);
    free(temp);
    *returnSize = numsSize;
    return counts;
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *answer = countSmaller(nums, size, &returnSize);
    printf("Counts: ");
    for (int i = 0; i < returnSize; ++i)
        printf("%d ", answer[i]);
    printf("\n");
    free(answer);
    return 0;
}
