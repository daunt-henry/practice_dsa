/*
Random Pick with Weight (LeetCode 528)

Design a class that:
- Initializes with an array of positive weights `w`.
- Supports `pickIndex()` to randomly return index i with probability w[i]/sum(w).

Solution approach:
1. Build a prefix sum array of weights.
2. On pick:
   - Generate random number `target` in [1, total weight].
   - Use binary search to find index where prefix >= target.

Time Complexity:
- init: O(n)
- pickIndex(): O(log n)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int* prefix;
    int size;
} Solution;

Solution* solutionCreate(int* w, int wSize) {
    Solution* obj = malloc(sizeof(Solution));
    obj->prefix = malloc(wSize * sizeof(int));
    obj->size = wSize;
    int cum = 0;
    for (int i = 0; i < wSize; i++) {
        cum += w[i];
        obj->prefix[i] = cum;
    }
    return obj;
}

int solutionPickIndex(Solution* obj) {
    int total = obj->prefix[obj->size - 1];
    int target = rand() % total + 1;
    int l = 0, r = obj->size - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (obj->prefix[mid] >= target) r = mid;
        else l = mid + 1;
    }
    return l;
}

void solutionFree(Solution* obj) {
    free(obj->prefix);
    free(obj);
}

int main(void) {
    srand((unsigned)time(NULL));

    int w1[] = {1, 3, 2};
    int n1 = sizeof(w1) / sizeof(w1[0]);
    Solution* sol1 = solutionCreate(w1, n1);

    printf("Random picks (weighted):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", solutionPickIndex(sol1));
    }
    printf("\n(Expect index 1 to appear most frequently)\n");

    solutionFree(sol1);
    return 0;
}
