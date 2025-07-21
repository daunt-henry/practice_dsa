/*
Asteroid Collision

We are given an array of integers representing asteroids in a row.
- Positive values move to the right.
- Negative values move to the left.
When two asteroids collide, the smaller one explodes. If they are the same size, both explode.
Return the state of the asteroids after all collisions.

Example:
Input: asteroids = [5, 10, -5]
Output: [5, 10]

Input: asteroids = [8, -8]
Output: []

Input: asteroids = [10, 2, -5]
Output: [10]

*/

#include <stdio.h>
#include <stdlib.h>

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* stack = (int*)malloc(sizeof(int) * asteroidsSize);
    int top = -1;

    for (int i = 0; i < asteroidsSize; ++i) {
        int current = asteroids[i];
        int collision = 1;

        while (top >= 0 && current < 0 && stack[top] > 0) {
            if (stack[top] < -current) {
                top--;
            } else if (stack[top] == -current) {
                top--;
                collision = 0;
                break;
            } else {
                collision = 0;
                break;
            }
        }

        if (collision) {
            stack[++top] = current;
        }
    }

    *returnSize = top + 1;
    return stack;
}

int main() {
    int asteroids[] = {5, 10, -5};
    int size = sizeof(asteroids) / sizeof(asteroids[0]);
    int returnSize;
    int* result = asteroidCollision(asteroids, size, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; ++i) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    free(result);
    return 0;
}
