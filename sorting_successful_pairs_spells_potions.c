/*
Problem:
You are given two integer arrays spells and potions of length n and m respectively, 
and an integer success. A pair (spell, potion) is successful if spell * potion >= success.
Return an array of length n where result[i] is the number of potions that 
will form a successful pair with the ith spell.

Approach:
- Sort the potions array.
- For each spell, use binary search to count the number of potions
  that meet or exceed the threshold (success / spell).
- This ensures time efficiency by avoiding brute-force checking.

Example:
Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
*/

#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int binarySearch(int* potions, int potionsSize, long long threshold) {
    int left = 0, right = potionsSize;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if ((long long)potions[mid] < threshold)
            left = mid + 1;
        else
            right = mid;
    }
    return potionsSize - left;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    qsort(potions, potionsSize, sizeof(int), compare);
    
    int* result = (int*)malloc(sizeof(int) * spellsSize);
    for (int i = 0; i < spellsSize; i++) {
        long long threshold = (success + spells[i] - 1) / spells[i]; // ceil division
        result[i] = binarySearch(potions, potionsSize, threshold);
    }

    *returnSize = spellsSize;
    return result;
}

/*
Output:
Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
*/
