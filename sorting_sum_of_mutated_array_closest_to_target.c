/*
Problem:
Find the integer value to replace elements in an array such that the mutated array's sum is closest to a given target.
If there's a tie, return the smaller value.

Approach:
- Binary search the replacement value in the range [0, max(arr)].
- For each mid value, compute the sum of the mutated array and check how close it is to the target.

Time: O(n log m) where m = max(arr)
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculateSum(int* arr, int size, int value) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (arr[i] > value ? value : arr[i]);
    }
    return sum;
}

int findBestValue(int* arr, int arrSize, int target) {
    int left = 0, right = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > right) right = arr[i];
    }

    int best = 0;
    int closest = abs(target);

    while (left <= right) {
        int mid = (left + right) / 2;
        int currSum = calculateSum(arr, arrSize, mid);
        int diff = abs(currSum - target);

        if (diff < closest || (diff == closest && mid < best)) {
            best = mid;
            closest = diff;
        }

        if (currSum < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return best;
}

// Test
int main() {
    int arr[] = {2,3,5};
    int target = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = findBestValue(arr, n, target);
    printf("Best value to mutate array closest to target: %d\n", result); // Expected: 5

    return 0;
}

/*
========= OUTPUT =========
Best value to mutate array closest to target: 5
==========================
*/
