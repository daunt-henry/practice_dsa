/*
Problem:
You are given an array of `names` and a corresponding array of `heights`.
Sort the people in descending order by their height.

Return the names reordered according to height.

Example Input:
names = ["Mary","John","Emma"]
heights = [180,165,170]

Expected Output:
["Mary","Emma","John"]

Explanation:
Sorted by heights descending: 180 (Mary), 170 (Emma), 165 (John)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;
    return p2[1] - p1[1];
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    int** pairs = malloc(sizeof(int*) * namesSize);
    for (int i = 0; i < namesSize; ++i) {
        pairs[i] = malloc(sizeof(int) * 2);
        pairs[i][0] = i;
        pairs[i][1] = heights[i];
    }

    qsort(pairs, namesSize, sizeof(int*), cmp);

    char** res = malloc(sizeof(char*) * namesSize);
    for (int i = 0; i < namesSize; ++i) {
        res[i] = names[pairs[i][0]];
        free(pairs[i]);
    }

    free(pairs);
    *returnSize = namesSize;
    return res;
}

int main() {
    char* names[] = {"Mary", "John", "Emma"};
    int heights[] = {180, 165, 170};
    int returnSize;

    char** sorted = sortPeople(names, 3, heights, 3, &returnSize);

    printf("Sorted names by height:\n");
    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", sorted[i]);
    }

    free(sorted);
    return 0;
}
