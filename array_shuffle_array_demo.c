/*
Shuffle an Array – Fisher–Yates (Durstenfeld) Shuffle

Problem: Given an array of integers, implement two operations:
  - reset(): returns the array to its original configuration
  - shuffle(): returns a random permutation of the array, with all permutations equally likely

Algorithmic Insight:
  Use the Fisher–Yates shuffle, which runs in O(n) time and does in-place shuffling by swapping each element
  with a randomly chosen element among the unshuffled portion. This method is unbiased. 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int* original;
    int size;
} ShuffleArray;

// Initialize with original array
ShuffleArray* createShuffleArray(int* nums, int numsSize) {
    srand((unsigned)time(NULL));
    ShuffleArray* sa = malloc(sizeof(ShuffleArray));
    sa->size = numsSize;
    sa->original = malloc(numsSize * sizeof(int));
    memcpy(sa->original, nums, numsSize * sizeof(int));
    return sa;
}

// Reset to original
int* resetArr(ShuffleArray* sa) {
    int* arr = malloc(sa->size * sizeof(int));
    memcpy(arr, sa->original, sa->size * sizeof(int));
    return arr;
}

// Fisher–Yates shuffle
int* shuffleArr(ShuffleArray* sa) {
    int* arr = malloc(sa->size * sizeof(int));
    memcpy(arr, sa->original, sa->size * sizeof(int));
    for (int i = sa->size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    return arr;
}

// Demo
int main(void) {
    int nums[] = {1, 2, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    ShuffleArray* sa = createShuffleArray(nums, n);

    printf("Original: ");
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\n");

    int* shuf = shuffleArr(sa);
    printf("Shuffled: ");
    for (int i = 0; i < n; i++) printf("%d ", shuf[i]);
    printf("\n");
    free(shuf);

    int* rst = resetArr(sa);
    printf("Reset to original: ");
    for (int i = 0; i < n; i++) printf("%d ", rst[i]);
    printf("\n");
    free(rst);

    free(sa->original);
    free(sa);
    return 0;
}
