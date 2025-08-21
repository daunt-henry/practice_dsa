/*
Heaters (LeetCode 475)

Given positions of houses and heaters on a number line, find the minimum radius
'R' so that every house is within 'R' units of at least one heater.

Approach:
1. Sort houses and heaters.
2. Use a single pointer (j) on heaters.
   For each house:
     - Advance j while the next heater is closer to the house.
     - The distance between the house and heater[j] is the minimal needed.
3. The maximum of these distances across all houses is the answer.

Complexity: O(n log n + m log m), with n = number of houses, m = number of heaters.
*/

#include <stdio.h>
#include <stdlib.h>

int cmpInt(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
    qsort(houses, housesSize, sizeof(int), cmpInt);
    qsort(heaters, heatersSize, sizeof(int), cmpInt);

    int res = 0;
    for (int i = 0, j = 0; i < housesSize; i++) {
        int house = houses[i];
        while (j + 1 < heatersSize &&
               abs(heaters[j + 1] - house) <= abs(heaters[j] - house)) {
            j++;
        }
        int dist = abs(heaters[j] - house);
        if (dist > res) res = dist;
    }
    return res;
}

int main(void) {
    int houses1[] = {1, 2, 3};
    int heaters1[] = {2};
    printf("Radius: %d (expected 1)\n",
           findRadius(houses1, 3, heaters1, 1));

    int houses2[] = {1, 2, 3, 4};
    int heaters2[] = {1, 4};
    printf("Radius: %d (expected 1)\n",
           findRadius(houses2, 4, heaters2, 2));

    int houses3[] = {1, 5};
    int heaters3[] = {2};
    printf("Radius: %d (expected 3)\n",
           findRadius(houses3, 2, heaters3, 1));

    return 0;
}
