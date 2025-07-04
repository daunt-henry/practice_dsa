/*
Mean of Array After Removing Some Elements

Problem:
Remove the smallest 5% and largest 5% of the elements from the array,
then return the mean of the remaining elements.

Steps:
1. Sort the array.
2. Remove the smallest and largest 5% elements.
3. Compute the sum of the remaining and return the average.

Time Complexity: O(n log n) due to sorting
Space Complexity: O(1)

Example:
Input: arr = [6,0,7,0,7,5,7,8,3,4]
Output: 4.0
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

double trimMean(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), compare);

    int removeCount = arrSize * 0.05;
    int sum = 0;
    for (int i = removeCount; i < arrSize - removeCount; i++) {
        sum += arr[i];
    }

    return (double)sum / (arrSize - 2 * removeCount);
}
