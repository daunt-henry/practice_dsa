/*
Problem: Maximize Number of Nice Divisors

You are given an integer `primeFactors`, which represents the total number
of prime factors (counted with multiplicity) for a number `n`.

A divisor of `n` is called nice if it is divisible by at least one of
`n`'s prime factors.

Find the maximum number of nice divisors a number with `primeFactors`
prime factors can have.

Example:
Input: primeFactors = 5
Output: 6

Explanation:
5 = 2 + 3 → 2*3 = 6 is max product of factors summing to 5
*/

#include <stdio.h>

#define MOD 1000000007

// Fast power function with modulo
long long power(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = result * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return result;
}

// Core function to maximize nice divisors
int maxNiceDivisors(int primeFactors) {
    if (primeFactors <= 3) return primeFactors;

    int q = primeFactors / 3;
    int r = primeFactors % 3;

    if (r == 0) return (int)power(3, q);
    if (r == 1) return (int)(power(3, q - 1) * 4 % MOD);
    return (int)(power(3, q) * 2 % MOD);
}

// Main test function
int main() {
    int primeFactors = 5;
    int result = maxNiceDivisors(primeFactors);
    printf("Maximum number of nice divisors for %d prime factors = %d\n", primeFactors, result);
    return 0;
}
