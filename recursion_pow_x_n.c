/*
Problem:
Implement pow(x, n) — i.e., calculate x raised to the power n.

Constraints:
- Handle negative exponents
- Use efficient O(log n) solution

Approach:
Exponentiation by Squaring (Iterative)

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <stdio.h>

double myPow(double x, int n) {
    long long N = n;
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    double result = 1.0;
    while (N) {
        if (N % 2 == 1)
            result *= x;
        x *= x;
        N /= 2;
    }
    return result;
}

// Demo
int main() {
    double x = 2.0;
    int n = -3;
    double result = myPow(x, n);
    printf("Result: %.10f\n", result);  // Output: 0.1250000000
    return 0;
}
