/*
Problem:
Create Sorted Array Through Instructions:
Insert each number into a container (initially empty) and 
pay cost = min(count of elements < num, count > num).
Return total cost modulo 10^9+7.

Approach:
Use a Fenwick Tree (BIT) to track frequency of inserted numbers:

- Update for each insertion is O(log M), query is O(log M),
  where M is the max instruction value.

Time Complexity: O(N log M)
Space Complexity: O(M)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MOD 1000000007

int lowbit(int x) { return x & -x; }

void fenwick_add(int* bit, int size, int idx, int v) {
    while (idx <= size) {
        bit[idx] += v;
        idx += lowbit(idx);
    }
}

int fenwick_query(int* bit, int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= lowbit(idx);
    }
    return sum;
}

int createSortedArray(int* instructions, int n) {
    int maxVal = 0;
    for (int i = 0; i < n; ++i)
        if (instructions[i] > maxVal)
            maxVal = instructions[i];

    int* bit = calloc(maxVal + 1, sizeof(int));
    long cost = 0;

    for (int i = 0; i < n; ++i) {
        int x = instructions[i];
        int less = fenwick_query(bit, x - 1);
        int greater = i - fenwick_query(bit, x);
        cost = (cost + (less < greater ? less : greater)) % MOD;
        fenwick_add(bit, maxVal, x, 1);
    }

    free(bit);
    return (int) cost;
}

int main() {
    int instr1[] = {1, 5, 6, 2};
    printf("Cost: %d\n", createSortedArray(instr1, 4)); // 1

    int instr2[] = {1, 2, 3, 6, 5, 4};
    printf("Cost: %d\n", createSortedArray(instr2, 6)); // 3

    int instr3[] = {1, 3, 3, 3, 2, 4, 2, 1, 2};
    printf("Cost: %d\n", createSortedArray(instr3, 9)); // 4

    return 0;
}
