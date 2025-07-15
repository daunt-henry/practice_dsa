/*
Problem:
Return true if n is a power of four, else return false.

Examples:
Input: 16 → true  (4^2)
Input: 5  → false
Input: 1  → true  (4^0)

Approach:
- If n <= 0 → false
- If n == 1 → true (base case)
- If n is not divisible by 4 → false
- Recursively check n / 4

Time Complexity: O(log₄ n)
*/

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfFour(int n) {
    if (n <= 0) return false;
    if (n == 1) return true;
    if (n % 4 != 0) return false;
    return isPowerOfFour(n / 4);
}

// Demo
int main() {
    int nums[] = {16, 5, 1, 64, 20};
    for (int i = 0; i < 5; i++) {
        printf("isPowerOfFour(%d) = %s\n", nums[i], isPowerOfFour(nums[i]) ? "true" : "false");
    }
    return 0;
}
