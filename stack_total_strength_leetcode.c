/*
Title: Sum of Total Strength of Wizards

Given an array `strength`, return the sum of total strengths of all non-empty subarrays.
The total strength of a subarray is the product of the minimum value in the subarray
and the sum of all values in the subarray.

Example:
Input: strength = [1,3,1,2]
Output: 44

Explanation:
Subarrays and their strength:
[1] => min:1, sum:1 -> 1*1 = 1
[1,3] => min:1, sum:4 -> 1*4 = 4
[1,3,1] => min:1, sum:5 -> 1*5 = 5
[1,3,1,2] => min:1, sum:7 -> 1*7 = 7
[3] => 3*3 = 9
[3,1] => 1*4 = 4
[3,1,2] => 1*6 = 6
[1] => 1
[1,2] => 1*3 = 3
[2] => 2
Sum = 1+4+5+7+9+4+6+1+3+2 = 42
*/

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int totalStrength(int* strength, int n) {
    long long* preSum = (long long*)calloc(n + 2, sizeof(long long));
    long long* prePreSum = (long long*)calloc(n + 3, sizeof(long long));
    int* left = (int*)malloc(n * sizeof(int));
    int* right = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; ++i)
        preSum[i + 1] = (preSum[i] + strength[i]) % MOD;
    for (int i = 0; i <= n + 1; ++i)
        prePreSum[i + 1] = (prePreSum[i] + preSum[i]) % MOD;

    int top = -1;
    int* stack = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; ++i) {
        while (top >= 0 && strength[stack[top]] >= strength[i]) top--;
        left[i] = top == -1 ? -1 : stack[top];
        stack[++top] = i;
    }

    top = -1;
    for (int i = n - 1; i >= 0; --i) {
        while (top >= 0 && strength[stack[top]] > strength[i]) top--;
        right[i] = top == -1 ? n : stack[top];
        stack[++top] = i;
    }

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        int l = left[i], r = right[i];
        int x = i - l, y = r - i;

        long long totalLeft = (prePreSum[i + 1] - prePreSum[l + 1] + MOD) % MOD;
        long long totalRight = (prePreSum[r + 1] - prePreSum[i + 1] + MOD) % MOD;

        long long contrib = strength[i] * ((totalRight * x % MOD - totalLeft * y % MOD + MOD) % MOD) % MOD;
        res = (res + contrib) % MOD;
    }

    free(preSum);
    free(prePreSum);
    free(left);
    free(right);
    free(stack);
    return (int)res;
}

int main() {
    int strength[] = {1, 3, 1, 2};
    int n = sizeof(strength) / sizeof(strength[0]);
    int result = totalStrength(strength, n);
    printf("Total strength of all subarrays: %d\n", result);  // Output: 44
    return 0;
}
