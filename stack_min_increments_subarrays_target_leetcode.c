/*
Title: Minimum Number of Increments on Subarrays to Form a Target Array

Description:
  You are given a target array. Initially, you have a zero array of the same length.
  You can increment any subarray (continuous segment) by 1 as many times as needed.
  Return the minimum number of operations required to form the target array.

Example:
  Input:  target = [1,2,3,2,1]
  Output: 3

Explanation:
  - Increment first 3 elements to 1 -> [1,1,1,0,0]
  - Increment first 3 elements again -> [2,2,2,0,0]
  - Increment first 3 elements again -> [3,3,3,0,0]
  - Decrease rest to match target -> 3 total operations needed

Approach:
  Greedy: Add to result only when current element is greater than previous.
  The difference tells how much new increment is needed at that position.
*/

#include <stdio.h>

int minNumberOperations(int* target, int targetSize){
    int result = target[0];
    for (int i = 1; i < targetSize; i++) {
        if (target[i] > target[i - 1])
            result += target[i] - target[i - 1];
    }
    return result;
}

int main() {
    int target[] = {1, 2, 3, 2, 1};
    int n = sizeof(target) / sizeof(target[0]);

    int result = minNumberOperations(target, n);
    printf("Minimum operations to reach target array: %d\n", result);  // Output: 3

    return 0;
}
