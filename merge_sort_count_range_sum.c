/*
Title: Count of Range Sum
Approach: 
1. Build prefix sums array `sum[]`, where sum[i] = nums[0] + ... + nums[i-1].
2. The subarray sum nums[i] + ... + nums[j] equals sum[j+1] - sum[i].
3. Count pairs (i < j) with lower <= sum[j] - sum[i] <= upper using merge sort.
4. Use two pointers in merge_count to accumulate valid ranges efficiently.
Time Complexity: O(n log n), Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static int64_t merge_count(int64_t *sum, int l, int m, int r, int lower, int upper, int64_t *tmp) {
    int64_t cnt = 0;
    int j_low = m + 1, j_high = m + 1;

    for (int i = l; i <= m; ++i) {
        while (j_low <= r && sum[j_low] - sum[i] < lower) ++j_low;
        while (j_high <= r && sum[j_high] - sum[i] <= upper) ++j_high;
        cnt += j_high - j_low;
    }

    int p = l, q = m + 1, k = l;
    while (p <= m && q <= r)
        tmp[k++] = (sum[p] <= sum[q] ? sum[p++] : sum[q++]);
    while (p <= m) tmp[k++] = sum[p++];
    while (q <= r) tmp[k++] = sum[q++];
    for (int t = l; t <= r; ++t) sum[t] = tmp[t];

    return cnt;
}

static int64_t sort_count(int64_t *sum, int l, int r, int lower, int upper, int64_t *tmp) {
    if (l >= r) return 0;
    int m = (l + r) >> 1;
    return sort_count(sum, l, m, lower, upper, tmp)
         + sort_count(sum, m + 1, r, lower, upper, tmp)
         + merge_count(sum, l, m, r, lower, upper, tmp);
}

int countRangeSum(int *nums, int numsSize, int lower, int upper) {
    int n = numsSize;
    int64_t *sum = malloc((n + 1) * sizeof(int64_t));
    int64_t *tmp = malloc((n + 1) * sizeof(int64_t));

    sum[0] = 0;
    for (int i = 0; i < n; ++i)
        sum[i + 1] = sum[i] + (int64_t)nums[i];

    int64_t ans = sort_count(sum, 0, n, lower, upper, tmp);
    free(sum); free(tmp);
    return (int)ans;
}

// Demo
int main() {
    int nums[] = {-2, 5, -1};
    int lower = -2, upper = 2;
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = countRangeSum(nums, size, lower, upper);
    printf("Count of range sums: %d\n", result);
    return 0;
}
