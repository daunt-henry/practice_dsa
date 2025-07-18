/*
Question: Sliding Window Maximum
--------------------------------
You are given an array of integers `nums`, and there is a sliding window of size `k` 
which moves from the very left to the very right. You can only see the `k` numbers in the window. 
Each time the sliding window moves right by one position.

Return the maximum values in each sliding window.

Example:
---------
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

Explanation:
Window position        Max
----------------------------
[1  3 -1] -3  5  3  6  7     -> 3
 1 [3 -1 -3] 5  3  6  7     -> 3
 1  3 [-1 -3 5] 3  6  7     -> 5
 1  3 -1 [-3 5 3] 6  7     -> 5
 1  3 -1 -3 [5 3 6] 7     -> 6
 1  3 -1 -3  5 [3 6 7]     -> 7
*/

#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int* deque = (int*)malloc(sizeof(int) * numsSize);
    int front = 0, back = 0;
    int resIndex = 0;

    for (int i = 0; i < numsSize; i++) {
        // Remove indices outside the window
        if (front < back && deque[front] <= i - k) {
            front++;
        }

        // Remove smaller elements from the back
        while (front < back && nums[deque[back - 1]] < nums[i]) {
            back--;
        }

        deque[back++] = i;

        // Start recording max after the first full window
        if (i >= k - 1) {
            result[resIndex++] = nums[deque[front]];
        }
    }

    *returnSize = resIndex;
    free(deque);
    return result;
}

// --- Test Main ---
int main() {
    int nums[] = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    int returnSize = 0;

    int* result = maxSlidingWindow(nums, sizeof(nums)/sizeof(nums[0]), k, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    free(result);
    return 0;
}
