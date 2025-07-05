/*
Problem: Maximum Building Height

You are given an integer n and a list of restrictions where each restriction[i] = [id, maxHeight].
Buildings must:
1. Start at building 1 with height 0.
2. End at building n.
3. Have height difference between adjacent buildings at most 1.
4. Respect given maxHeight at restricted building ids.

Return the maximum possible height of any building.

Example:
Input: n = 5, restrictions = [[2,1],[4,1]]
Output: 2

Explanation: Build heights like [0,1,2,1,2].

Approach:
- Add virtual restrictions at building 1 (height 0) and n (height n-1).
- Sort all restrictions.
- Apply forward and backward passes to tighten constraints.
- Use math to calculate max possible height between each restriction.

Time Complexity: O(m log m) + O(m)
Space Complexity: O(m)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int height;
} Restriction;

int cmp(const void *a, const void *b) {
    return ((Restriction *)a)->id - ((Restriction *)b)->id;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int maxBuilding(int n, int** restrictions, int restrictionsSize, int* restrictionsColSize){
    if (restrictionsSize == 0) {
        return n - 1;
    }

    Restriction* res = (Restriction*)malloc(sizeof(Restriction) * (restrictionsSize + 2));
    int size = 0;

    for (int i = 0; i < restrictionsSize; i++) {
        res[size].id = restrictions[i][0];
        res[size].height = restrictions[i][1];
        size++;
    }

    res[size++] = (Restriction){1, 0};
    res[size++] = (Restriction){n, n - 1};

    qsort(res, size, sizeof(Restriction), cmp);

    for (int i = 1; i < size; i++) {
        int d = res[i].id - res[i - 1].id;
        res[i].height = min(res[i].height, res[i - 1].height + d);
    }

    for (int i = size - 2; i >= 0; i--) {
        int d = res[i + 1].id - res[i].id;
        res[i].height = min(res[i].height, res[i + 1].height + d);
    }

    int ans = 0;
    for (int i = 1; i < size; i++) {
        int d = res[i].id - res[i - 1].id;
        int h1 = res[i - 1].height;
        int h2 = res[i].height;
        int maxH = (h1 + h2 + d) / 2;
        ans = max(ans, maxH);
    }

    free(res);
    return ans;
}
