/*
Problem: Boats to Save People 

Given an array of people's weights and a weight limit,
return the minimum number of boats to carry everyone.

Rules:
- Each boat can carry at most 2 people
- Combined weight ≤ limit

Approach:
- Sort weights
- Use two pointers: lightest + heaviest
- Try to pair them; else send heaviest alone

Time: O(n log n)
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int numRescueBoats(int* people, int peopleSize, int limit) {
    qsort(people, peopleSize, sizeof(int), compare);

    int i = 0, j = peopleSize - 1;
    int boats = 0;

    while (i <= j) {
        if (people[i] + people[j] <= limit) {
            i++;
        }
        j--;
        boats++;
    }

    return boats;
}

// Test
int main() {
    int people[] = {3, 2, 2, 1};
    int limit = 3;
    int size = sizeof(people) / sizeof(people[0]);

    int result = numRescueBoats(people, size, limit);
    printf("Output: %d\n", result);  // Expected: 3

    return 0;
}

/*
========= OUTPUT =========
Output: 3
==========================
*/
