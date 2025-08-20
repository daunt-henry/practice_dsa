/*
Number of Boomerangs (LeetCode 447)

A boomerang is a tuple (i, j, k) where distance(i, j) == distance(i, k),
and j/k order matters. Given an array of points, count all boomerangs.

Approach: For each point i, build a distance frequency map to all other points.
Each distance with count c contributes c × (c − 1) boomerangs.

Time: O(n^2), Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *keys, *counts;
    int size;
} HashMap;

void initMap(HashMap* m, int n) {
    m->size = n;
    m->keys = calloc(n, sizeof(int));
    m->counts = calloc(n, sizeof(int));
}

void incMap(HashMap* m, int key) {
    int idx = (key % m->size + m->size) % m->size;
    while (m->counts[idx] && m->keys[idx] != key) {
        idx = (idx + 1) % m->size;
    }
    m->keys[idx] = key;
    m->counts[idx]++;
}

void freeMap(HashMap* m) {
    free(m->keys);
    free(m->counts);
}

int numberOfBoomerangs(int** points, int n, int* colSize) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        HashMap map;
        initMap(&map, n * 2 + 1);
        for (int j = 0; j < n; j++) {
            int dx = points[i][0] - points[j][0];
            int dy = points[i][1] - points[j][1];
            int dist = dx * dx + dy * dy;
            incMap(&map, dist);
        }
        for (int k = 0; k < map.size; k++) {
            int c = map.counts[k];
            if (c > 1) ans += c * (c - 1);
        }
        freeMap(&map);
    }
    return ans;
}

int main(void) {
    int pts1[3][2] = {{0,0}, {1,0}, {2,0}};
    int* points1[3];
    for (int i = 0; i < 3; i++) points1[i] = pts1[i];
    int col = 2;
    printf("Boomerangs: %d (expected 2)\n", numberOfBoomerangs(points1, 3, &col));

    int pts2[4][2] = {{0,0}, {1,0}, {1,1}, {0,1}};
    int* points2[4];
    for (int i = 0; i < 4; i++) points2[i] = pts2[i];
    printf("Boomerangs: %d (expected 8)\n", numberOfBoomerangs(points2, 4, &col));

    return 0;
}
