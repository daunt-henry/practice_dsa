/*
Problem:
Determine if an integer is a power of two.

Approach:
Use bit manipulation.
- A power of two has only one set bit.
- So, (n & (n - 1)) == 0 for powers of two.

Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// Demo
int main() {
    int n = 16;
    printf("Is %d a power of two? %s\n", n, isPowerOfTwo(n) ? "Yes" : "No");

    n = 18;
    printf("Is %d a power of two? %s\n", n, isPowerOfTwo(n) ? "Yes" : "No");

    return 0;
}
