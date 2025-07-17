/*
Title: Reverse Pairs (LeetCode #493)
Count pairs (i, j) where i < j and nums[i] > 2 * nums[j]

Approach: Modified merge sort
- Count qualifying pairs between left/right halves
- Then merge halves maintaining sorted order

Time: O(n log n)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static int merge_count(int* nums, int l, int m, int r, int* tmp) {
    int64_t count = 0;
    int t = m + 1;
    for (int i = l; i <= m; i++) {
        while (t <= r && (int64_t)nums[i] > 2LL * nums[t]) {
            ++t;
        }
        count += t - (m + 1);
    }

    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        tmp[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
    }
    while (i <= m) tmp[k++] = nums[i++];
    while (j <= r) tmp[k++] = nums[j++];
    for (i = l; i <= r; ++i) nums[i] = tmp[i];

    return (int)count;
}

static int sort_count(int* nums, int l, int r, int* tmp) {
    if (l >= r) return 0;
    int m = (l + r) / 2;
    int cnt = sort_count(nums, l, m, tmp)
            + sort_count(nums, m + 1, r, tmp)
            + merge_count(nums, l, m, r, tmp);
    return cnt;
}

int reversePairs(int* nums, int numsSize) {
    int* tmp = malloc(numsSize * sizeof(int));
    int res = sort_count(nums, 0, numsSize - 1, tmp);
    free(tmp);
    return res;
}

int main() {
    int nums[] = {1, 3, 2, 3, 1};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("Reverse pairs: %d\n", reversePairs(nums, size));  // Output: 2

    int nums2[] = {2, 4, 3, 5, 1};
    size = sizeof(nums2) / sizeof(nums2[0]);
    printf("Reverse pairs: %d\n", reversePairs(nums2, size)); // Output: 3

    return 0;
}
