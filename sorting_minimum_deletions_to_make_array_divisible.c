/*
Question:
You are given two integer arrays nums and numsDivide. 
You can delete elements from nums. 
Return the minimum number of deletions such that the smallest element in nums divides all elements in numsDivide. 
If it is not possible, return -1.

Approach:
1. Compute the GCD of all numbers in numsDivide.
2. Sort nums and find the first number that divides the GCD.
3. Return the index (number of deletions before it).
4. If no such number exists, return -1.

Example:
Input: nums = [3,7,9,5,6], numsDivide = [30,72,81,90,72,72]
Output: 1
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int minOperations(int* nums, int numsSize, int* numsDivide, int numsDivideSize) {
    int g = numsDivide[0];
    for (int i = 1; i < numsDivideSize; i++) {
        g = gcd(g, numsDivide[i]);
    }

    qsort(nums, numsSize, sizeof(int), compare);
    
    for (int i = 0; i < numsSize; i++) {
        if (g % nums[i] == 0) return i;
        while (i + 1 < numsSize && nums[i] == nums[i + 1]) i++;
    }

    return -1;
}

/*
Output:
Input: nums = [3,7,9,5,6], numsDivide = [30,72,81,90,72,72]
Output: 1
*/
