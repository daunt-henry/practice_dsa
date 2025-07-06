/*
Problem:
You are given an integer array `cost` where cost[i] is the cost of the i-th candy. Every time you buy two candies, you get a third one for free (of equal or lesser price). Return the minimum total cost to buy all candies.

Approach:
Sort the array in descending order.
Pick 2, skip 1 (as free), and repeat.
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a); // Descending order
}

int minimumCost(int* cost, int costSize) {
    qsort(cost, costSize, sizeof(int), compare);

    int total = 0;
    for (int i = 0; i < costSize; ++i) {
        if ((i + 1) % 3 != 0) {
            total += cost[i];
        }
    }
    return total;
}

// Example usage
int main() {
    int cost[] = {6, 5, 7, 9, 2, 2};
    int n = sizeof(cost) / sizeof(cost[0]);
    int result = minimumCost(cost, n);
    printf("Minimum cost: %d\n", result);  // Output: 23
    return 0;
}
