/*
Problem:
GCD Sort of an Array

Given an array, return true if it can be sorted in non-decreasing order by 
swapping any pair of elements that have GCD greater than 1.

Approach:
- Use Union Find (DSU) to group elements that share prime factors.
- Preprocess using sieve to get smallest prime factors.
- Union each number with its prime factors.
- After grouping, if two numbers share the same root, they can be swapped.
- Finally, check if each element can be swapped to its sorted position.

Example:
Input: nums = [7,21,3]
Output: true

Input: nums = [5,2,6,2]
Output: false
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100001

int parent[MAX];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py)
        parent[px] = py;
}

bool isPrime[MAX];
int spf[MAX];

void sieve() {
    for (int i = 0; i < MAX; ++i) {
        isPrime[i] = true;
        spf[i] = i;
    }
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                isPrime[j] = false;
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

void unionFactors(int num) {
    int original = num;
    while (num > 1) {
        int prime = spf[num];
        unite(original, prime);
        while (num % prime == 0)
            num /= prime;
    }
}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool gcdSort(int* nums, int numsSize) {
    sieve();

    for (int i = 0; i < MAX; ++i)
        parent[i] = i;

    for (int i = 0; i < numsSize; ++i)
        unionFactors(nums[i]);

    int* sorted = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; ++i)
        sorted[i] = nums[i];
    qsort(sorted, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize; ++i) {
        if (find(nums[i]) != find(sorted[i])) {
            free(sorted);
            return false;
        }
    }

    free(sorted);
    return true;
}

/*
Sample Input:
nums = [7,21,3]
Output: true

nums = [5,2,6,2]
Output: false
*/
