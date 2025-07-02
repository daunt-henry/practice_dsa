/*
Problem: Queue Reconstruction by Height

Description:
Given a list of people with [height, k] where k is the number of people
taller or equal in front, reconstruct the original queue.

Approach:
1. Sort people by height descending, then k ascending
2. Insert each person at index = k

Time: O(n^2)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;

    if (p1[0] != p2[0])
        return p2[0] - p1[0]; // height descending
    return p1[1] - p2[1];     // k ascending
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes) {
    qsort(people, peopleSize, sizeof(int*), cmp);

    int** result = malloc(sizeof(int*) * peopleSize);
    int count = 0;

    for (int i = 0; i < peopleSize; i++) {
        int k = people[i][1];
        for (int j = count; j > k; j--) {
            result[j] = result[j - 1];
        }
        result[k] = malloc(2 * sizeof(int));
        result[k][0] = people[i][0];
        result[k][1] = people[i][1];
        count++;
    }

    *returnSize = peopleSize;
    *returnColumnSizes = malloc(sizeof(int) * peopleSize);
    for (int i = 0; i < peopleSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}

// Test
int main() {
    int input[][2] = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    int size = sizeof(input) / sizeof(input[0]);

    int** people = malloc(sizeof(int*) * size);
    int* colSizes = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        people[i] = malloc(2 * sizeof(int));
        people[i][0] = input[i][0];
        people[i][1] = input[i][1];
        colSizes[i] = 2;
    }

    int returnSize;
    int* returnColSizes;
    int** result = reconstructQueue(people, size, colSizes, &returnSize, &returnColSizes);

    printf("Reconstructed Queue:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d] ", result[i][0], result[i][1]);
        free(result[i]);
    }
    printf("\n");

    free(result);
    for (int i = 0; i < size; i++) free(people[i]);
    free(people);
    free(colSizes);
    free(returnColSizes);
    return 0;
}

/*
========= OUTPUT =========
Reconstructed Queue:
[5, 0] [7, 0] [5, 2] [6, 1] [4, 4] [7, 1]
==========================
*/
