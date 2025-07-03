/*
Problem:
Count the number of triplets (i, j, k) where i < j < k and arr[i] + arr[j] + arr[k] == target.
Since values are limited to 0 <= arr[i] <= 100, we can use frequency counting.

Approach:
- Count frequency of each number in range 0–100.
- Iterate i ≤ j ≤ k and check if i + j + k == target.
- Handle cases:
  - All same: i == j == k
  - Two same: i == j != k or i != j == k
  - All different: i < j < k

Time: O(101³) => practically O(100²)
Space: O(1)
*/

#include <stdio.h>

#define MOD 1000000007

int threeSumMulti(int* arr, int arrSize, int target) {
    long count[101] = {0};
    for (int i = 0; i < arrSize; i++)
        count[arr[i]]++;

    long res = 0;

    for (int i = 0; i <= 100; i++) {
        for (int j = i; j <= 100; j++) {
            int k = target - i - j;
            if (k < 0 || k > 100) continue;

            if (i == j && j == k) {
                res += count[i] * (count[i] - 1) * (count[i] - 2) / 6;
            } else if (i == j && j != k) {
                res += count[i] * (count[i] - 1) / 2 * count[k];
            } else if (i < j && j < k) {
                res += count[i] * count[j] * count[k];
            }
            res %= MOD;
        }
    }

    return (int)res;
}

// Test
int main() {
    int arr[] = {1, 1, 2, 2, 3, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = threeSumMulti(arr, size, target);
    printf("Output: %d\n", result);  // Expected: 8

    return 0;
}

/*
========= OUTPUT =========
Output: 8
==========================
*/
