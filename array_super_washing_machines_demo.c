/*
Problem: Super Washing Machines (LeetCode 517)

You have n washing machines in a line, each with some number of dresses.
In one move, any number of machines can pass one dress to an adjacent machine.
Find the minimum number of moves to make all machines have the same count.
Return -1 if impossible.

Example:
Input: machines = [1, 0, 5]
Output: 3
Explanation:
 Move 1: [1, 1, 4]
 Move 2: [2, 1, 3]
 Move 3: [2, 2, 2]
*/

#include <stdio.h>
#include <stdlib.h>

int findMinMoves(int* machines, int machinesSize) {
    long total = 0;
    for (int i = 0; i < machinesSize; i++) total += machines[i];

    if (total % machinesSize != 0) return -1;
    int avg = total / machinesSize;

    long balance = 0;
    int result = 0;
    for (int i = 0; i < machinesSize; i++) {
        int diff = machines[i] - avg;
        balance += diff;
        int need = abs((int)balance);
        if (need > result) result = need;
        if (diff > result) result = diff;
    }
    return result;
}

int main(void) {
    int m1[] = {1, 0, 5};
    printf("Moves needed: %d (expected 3)\n", findMinMoves(m1, 3));

    int m2[] = {0, 3, 0};
    printf("Moves needed: %d (expected 2)\n", findMinMoves(m2, 3));

    int m3[] = {0, 2, 0};
    printf("Moves needed: %d (expected -1)\n", findMinMoves(m3, 3));

    return 0;
}
