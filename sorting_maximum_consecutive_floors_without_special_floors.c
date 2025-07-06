// maximum_consecutive_floors_without_special_floors.c

/*
Problem:
You are given two integers bottom and top, representing the lowest and highest numbered floors of a building.
You are also given an integer array special, where special[i] denotes a special floor.
Return the maximum number of consecutive floors without any special floor.

Approach:
- Sort the special array.
- Iterate through the sorted list and compute the gaps between special floors and the bounds.
- Return the largest such gap.

Example:
Input: bottom = 2, top = 9, special = [4,6]
Output: 3
Explanation: The consecutive non-special floors are [2,3], [5], and [7,8,9]. The maximum length is 3.
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxConsecutive(int bottom, int top, int* special, int specialSize) {
    qsort(special, specialSize, sizeof(int), cmp);

    int maxGap = 0;
    int prev = bottom - 1;

    for (int i = 0; i < specialSize; i++) {
        int gap = special[i] - prev - 1;
        if (gap > maxGap) maxGap = gap;
        prev = special[i];
    }

    if (top - special[specialSize - 1] > maxGap) {
        maxGap = top - special[specialSize - 1];
    }

    return maxGap;
}

/*
Output:
Input: bottom = 2, top = 9, special = [4,6]
Output: 3
*/
