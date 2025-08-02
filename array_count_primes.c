/*
Problem: Count Primes

Count the number of prime numbers less than a non-negative number, n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10: 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int countPrimes(int n) {
    if (n <= 2) return 0;

    bool *isPrime = (bool *)malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) isPrime[i] = true;

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
    }

    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) count++;
    }

    free(isPrime);
    return count;
}

int main() {
    int n = 10;
    printf("Count of primes less than %d: %d\n", n, countPrimes(n));
    return 0;
}
