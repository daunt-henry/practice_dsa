/*
Problem:
Return the k-th permutation sequence of numbers from 1 to n.

Approach:
Math-based solution using factorial number system:
- Fix each digit one by one.
- Use (n-1)! to determine the block of permutations starting with a digit.

Time Complexity: O(n^2)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* getPermutation(int n, int k) {
    int factorial[10];
    factorial[0] = 1;
    for (int i = 1; i < n; i++)
        factorial[i] = factorial[i - 1] * i;

    bool used[10] = {false};
    char* res = malloc(sizeof(char) * (n + 1));
    res[n] = '\0';
    k--;  // Convert to 0-based index

    for (int i = 0; i < n; i++) {
        int blockSize = factorial[n - 1 - i];
        int index = k / blockSize;
        k %= blockSize;

        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (!used[j]) {
                if (count == index) {
                    res[i] = j + '0';
                    used[j] = true;
                    break;
                }
                count++;
            }
        }
    }

    return res;
}

// Demo
int main() {
    int n = 4, k = 9;
    char* result = getPermutation(n, k);
    printf("The %d-th permutation of 1 to %d is: %s\n", k, n, result);
    free(result);
    return 0;
}
