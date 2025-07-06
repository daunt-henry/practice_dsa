/*
Problem:
You have n bags numbered from 0 to n - 1. Each bag has a capacity[i] and currently contains rocks[i] rocks.
You also have additionalRocks extra rocks. You can place them in any of the bags.
Return the maximum number of bags that can be filled to their capacity.

Approach:
- Calculate the remaining space in each bag (capacity - rocks).
- Sort the space required in ascending order.
- Try filling the bags with the smallest space first using the additional rocks.

Example:
Input: capacity = [2,3,4], rocks = [1,2,4], additionalRocks = 2
Output: 3
Explanation: Fill 1 more rock in bag 0 and 1 more in bag 1.
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maximumBags(int* capacity, int capacitySize, int* rocks, int rocksSize, int additionalRocks) {
    int *space = (int *)malloc(sizeof(int) * capacitySize);
    
    for (int i = 0; i < capacitySize; i++) {
        space[i] = capacity[i] - rocks[i];
    }

    qsort(space, capacitySize, sizeof(int), cmp);

    int count = 0;
    for (int i = 0; i < capacitySize; i++) {
        if (space[i] == 0) {
            count++;
        } else if (additionalRocks >= space[i]) {
            additionalRocks -= space[i];
            count++;
        } else {
            break;
        }
    }

    free(space);
    return count;
}

/*
Output:
Input: capacity = [2,3,4], rocks = [1,2,4], additionalRocks = 2
Output: 3
*/
