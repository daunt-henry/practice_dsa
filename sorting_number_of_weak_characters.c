/*
Problem:
The Number of Weak Characters in the Game

Each character has an attack and defense value. A character is weak if there's another
character with both higher attack and higher defense.

Approach:
- Sort characters:
  - Descending by attack
  - If attack is same, ascending by defense
- Traverse and keep track of max defense seen so far.
- Count a character as weak if its defense is less than max seen.

Example:
Input: properties = [[5,5],[6,3],[3,6]]
Output: 0

Input: properties = [[2,2],[3,3]]
Output: 1
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    if (x[0] != y[0])
        return y[0] - x[0]; // Sort by attack descending
    return x[1] - y[1];     // Sort by defense ascending
}

int numberOfWeakCharacters(int** properties, int propertiesSize, int* propertiesColSize) {
    qsort(properties, propertiesSize, sizeof(int*), compare);

    int maxDefense = 0;
    int weakCount = 0;

    for (int i = 0; i < propertiesSize; ++i) {
        int attack = properties[i][0];
        int defense = properties[i][1];

        if (defense < maxDefense)
            weakCount++;
        else
            maxDefense = defense;
    }

    return weakCount;
}

/*
Sample Input:
properties = [[2,2],[3,3]]
Output: 1

properties = [[5,5],[6,3],[3,6]]
Output: 0
*/
