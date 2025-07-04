/*
Reducing Dishes

Problem:
- Each dish has a satisfaction value.
- You can prepare the dishes in any order or skip them.
- Like-time coefficient = time * satisfaction.
- Maximize the total like-time coefficient.

Approach:
- Sort satisfaction in descending order.
- Greedily include dishes one by one while the running sum stays positive.
- Once adding a dish drops the sum below zero, stop.

Time: O(n log n)
Space: O(1)

Example:
Input: [-1,-8,0,5,-9]
Sorted: [5, 0, -1, -8, -9]
Only [5,0,-1] contribute positively
Output: 14
*/

#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);  // descending order
}

int maxSatisfaction(int* satisfaction, int satisfactionSize) {
    qsort(satisfaction, satisfactionSize, sizeof(int), cmp);
    int sum = 0, total = 0;
    for (int i = 0; i < satisfactionSize; i++) {
        sum += satisfaction[i];
        if (sum > 0)
            total += sum;
        else
            break;
    }
    return total;
}

