/*
Problem:
You are given an array of integers beans, where each integer represents the number of magic beans in a bag.
You must remove beans from some of the bags so that all remaining non-empty bags have the same number of beans.
Return the minimum number of beans you have to remove.

Example:
Input: beans = [4,1,6,5]
Output: 4

Explanation:
Remove 1 bean from the bag with 4 beans, and 3 beans from the bag with 6 beans, for a total of 4 beans removed.
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

long long minimumRemoval(int* beans, int beansSize){
    qsort(beans, beansSize, sizeof(int), compare);
    
    long long total = 0;
    for (int i = 0; i < beansSize; i++) {
        total += beans[i];
    }

    long long min_removal = total;
    for (int i = 0; i < beansSize; i++) {
        long long remaining = (long long)beans[i] * (beansSize - i);
        long long removed = total - remaining;
        if (removed < min_removal) {
            min_removal = removed;
        }
    }

    return min_removal;
}

/*
Test Cases:
Input: [4,1,6,5]
Output: 4

Input: [2,10,3,2]
Output: 7
*/
