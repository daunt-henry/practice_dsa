/*
Problem: Random Point in Non-overlapping Rectangles

You are given a list of non-overlapping axis-aligned rectangles. 
Each rectangle is represented as [x1, y1, x2, y2].
Pick a random integer point uniformly from all rectangles.

Example:
Input:
rects = [[1,1,5,5]]
Output:
Random point inside [1,1,5,5], e.g. [3,4]

Input:
rects = [[-2,-2,-1,-1],[1,0,3,0]]
Output:
Random point from either rectangle.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int** rects;
    int rectsSize;
    int* rectsColSize;
    int* prefix;
    int totalPoints;
} Solution;

Solution* solutionCreate(int** rects, int rectsSize, int* rectsColSize) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->rects = rects;
    obj->rectsSize = rectsSize;
    obj->rectsColSize = rectsColSize;
    obj->prefix = (int*)malloc(sizeof(int) * rectsSize);
    obj->totalPoints = 0;

    for (int i = 0; i < rectsSize; i++) {
        int* r = rects[i];
        int count = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
        obj->totalPoints += count;
        obj->prefix[i] = obj->totalPoints;
    }
    return obj;
}

int* solutionPick(Solution* obj, int* retSize) {
    int rnd = rand() % obj->totalPoints;
    int l = 0, r = obj->rectsSize - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (rnd < obj->prefix[m]) r = m;
        else l = m + 1;
    }

    int* rect = obj->rects[l];
    int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
    int prev = (l == 0) ? 0 : obj->prefix[l - 1];
    int offset = rnd - prev;
    int width = x2 - x1 + 1;

    int* res = (int*)malloc(sizeof(int) * 2);
    res[0] = x1 + offset % width;
    res[1] = y1 + offset / width;
    *retSize = 2;
    return res;
}

void solutionFree(Solution* obj) {
    free(obj->prefix);
    free(obj);
}

int main() {
    srand(time(NULL));

    int rect1[] = {1, 1, 5, 5};
    int rect2[] = {-2, -2, -1, -1};
    int rect3[] = {1, 0, 3, 0};

    int* rects[] = {rect1, rect2, rect3};
    int rectsColSize[] = {4, 4, 4};

    Solution* obj = solutionCreate(rects, 3, rectsColSize);

    for (int i = 0; i < 5; i++) {
        int retSize;
        int* point = solutionPick(obj, &retSize);
        printf("Random Point: [%d, %d]\n", point[0], point[1]);
        free(point);
    }

    solutionFree(obj);
    return 0;
}
