/*
Problem:
Eliminate Maximum Number of Monsters

You are given an array `dist` of distances of monsters from a city and an array `speed` where each element represents how fast each monster is moving.
You can eliminate one monster per minute. Return the **maximum number** of monsters you can eliminate before any of them reach the city.

Approach:
- Calculate time = distance / speed for each monster.
- Sort the time array.
- If any monster reaches the city before your turn (i.e., time[i] <= i), you must stop.

Example:
Input: dist = [1,3,4], speed = [1,1,1]
Output: 3

Explanation:
- Monster 1 arrives in 1 minute
- Monster 2 in 3 minutes
- Monster 3 in 4 minutes
You can eliminate them in order: 1st, 2nd, and 3rd minute => All eliminated.
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    float fa = *(float*)a;
    float fb = *(float*)b;
    return (fa > fb) - (fa < fb);
}

int eliminateMaximum(int* dist, int distSize, int* speed, int speedSize) {
    float time[distSize];
    for (int i = 0; i < distSize; i++) {
        time[i] = (float)dist[i] / speed[i];
    }

    qsort(time, distSize, sizeof(float), cmp);

    for (int i = 0; i < distSize; i++) {
        if (time[i] <= i)
            return i;
    }
    return distSize;
}

/*
Sample Input:
dist = [1,3,4], speed = [1,1,1]

Sample Output:
3
*/
