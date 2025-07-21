/*
Title: Replace Non-Coprime Numbers in Array

Description:
  You are given an array of integers nums. 
  You should perform the following operation repeatedly:
    - If two adjacent numbers in the array are not coprime, 
      replace them with their least common multiple (LCM),
      and repeat this until no more such adjacent pairs exist.

  Return the final modified array.

Example:
  Input: nums = [6,4,3,2,7,6,2]
  Output: [12,7,6]

Constraints:
  - 1 <= nums.length <= 10^5
  - 1 <= nums[i] <= 10^8
*/

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int* replaceNonCoprimes(int* nums, int numsSize, int* returnSize){
    int* stack = (int*)malloc(sizeof(int) * numsSize);
    int top = -1;

    for (int i = 0; i < numsSize; ++i) {
        int cur = nums[i];
        while (top >= 0 && gcd(stack[top], cur) > 1) {
            cur = lcm(stack[top], cur);
            --top;
        }
        stack[++top] = cur;
    }

    *returnSize = top + 1;
    return stack;
}

int main() {
    int nums[] = {6, 4, 3, 2, 7, 6, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* result = replaceNonCoprimes(nums, n, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; ++i) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n"); // Output: [12, 7, 6]

    free(result);
    return 0;
}
