/*
Problem: Reordered Power of 2 (LeetCode 869)

Given an integer n, check if any permutation of its digits forms a power of 2.

Approach:
- Count digit frequency of n
- Compare with digit frequencies of all 2^0 to 2^30

Time: O(31 * 10) = O(1)
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void countDigits(int n, int* count) {
    memset(count, 0, sizeof(int) * 10);
    while (n > 0) {
        count[n % 10]++;
        n /= 10;
    }
}

bool reorderedPowerOf2(int n) {
    int targetCount[10];
    countDigits(n, targetCount);

    for (int i = 0; i < 31; i++) {
        int power = 1 << i;
        int powerCount[10];
        countDigits(power, powerCount);

        if (memcmp(targetCount, powerCount, sizeof(targetCount)) == 0) {
            return true;
        }
    }
    return false;
}

// Test
int main() {
    int n1 = 1;
    int n2 = 10;
    int n3 = 821;

    printf("Output (1): %s\n", reorderedPowerOf2(n1) ? "true" : "false");   // true
    printf("Output (10): %s\n", reorderedPowerOf2(n2) ? "true" : "false"); // false
    printf("Output (821): %s\n", reorderedPowerOf2(n3) ? "true" : "false"); // true

    return 0;
}

/*
========= OUTPUT =========
Output (1): true
Output (10): false
Output (821): true
==========================
*/
