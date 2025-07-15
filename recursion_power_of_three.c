/*
Problem:
Return true if the integer n is a power of 3.

Examples:
Input: 27 → true
Input: 0 → false
Input: 9 → true
Input: 45 → false

Approach:
- Base case: if n == 1, return true.
- If n is less than 1 or not divisible by 3, return false.
- Else, recursively check n / 3.

Time Complexity: O(log₃ n)
*/

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    if (n == 1) return true;
    if (n % 3 != 0) return false;
    return isPowerOfThree(n / 3);
}

// Demo
int main() {
    int nums[] = {27, 0, 9, 45, 1};
    for (int i = 0; i < 5; i++) {
        printf("isPowerOfThree(%d) = %s\n", nums[i], isPowerOfThree(nums[i]) ? "true" : "false");
    }
    return 0;
}
