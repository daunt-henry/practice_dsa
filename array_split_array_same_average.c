/*
 * Problem: Split Array With Same Average
 * 
 * Approach:
 *   - Transform nums[i] -> nums[i] * n - sum
 *   - Meet-in-the-middle: enumerate subset sums in both halves
 *   - Check if sum = 0 or left + right = 0
 * 
 * Time:  O(n * 2^(n/2))
 * Space: O(2^(n/2))
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

bool splitArraySameAverage(int* nums, int numsSize) {
    int n = numsSize;
    if (n < 2) return false;

    int sum = 0;
    for (int i = 0; i < n; i++) sum += nums[i];

    bool possible = false;
    for (int k = 1; k <= n / 2; k++) {
        if ((sum * k) % n == 0) { possible = true; break; }
    }
    if (!possible) return false;

    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) arr[i] = nums[i] * n - sum;

    int mid = n / 2;
    int leftSz = mid;
    int rightSz = n - mid;

    int leftCnt = (1 << leftSz);
    int* leftSums = malloc(leftCnt * sizeof(int));
    int cnt = 0;

    for (int mask = 1; mask < leftCnt; mask++) {
        int s = 0;
        for (int j = 0; j < leftSz; j++) {
            if (mask & (1 << j)) s += arr[j];
        }
        if (s == 0) { free(arr); free(leftSums); return true; }
        leftSums[cnt++] = s;
    }
    qsort(leftSums, cnt, sizeof(int), cmp);

    int rightCnt = 1 << rightSz;
    for (int mask = 1; mask < rightCnt; mask++) {
        int s = 0;
        for (int j = 0; j < rightSz; j++) {
            if (mask & (1 << j)) s += arr[mid + j];
        }
        if (s == 0) { free(arr); free(leftSums); return true; }
        if (mask == rightCnt - 1) continue;

        int target = -s;
        if (bsearch(&target, leftSums, cnt, sizeof(int), cmp)) {
            free(arr);
            free(leftSums);
            return true;
        }
    }

    free(arr);
    free(leftSums);
    return false;
}

int main(void) {
    int nums1[] = {1,2,3,4,5,6,7,8};
    printf("Expected: 1, Got: %d\n", splitArraySameAverage(nums1, 8));

    int nums2[] = {3,1,2,6,7};
    printf("Expected: 0, Got: %d\n", splitArraySameAverage(nums2, 5));

    return 0;
}
