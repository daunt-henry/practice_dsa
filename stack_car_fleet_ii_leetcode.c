/*
Title: Car Fleet II

Description:
  There are N cars on a one-lane road. Each car is described by a position and speed.
  When a car catches up to the car in front, they form a fleet and move together at the same speed.
  You need to return an array where each element represents the time at which the ith car will collide
  with the next car in front. If it will never collide, return -1 for that car.

Example:
  Input: cars = [[1,2],[2,1],[4,3],[7,2]]
  Output: [1.00000,-1.00000,3.00000,-1.00000]

Approach:
  - Use a stack to keep track of the indices of cars that are potentially collidable.
  - Check relative speeds and collision time, prune invalid ones.
*/

#include <stdio.h>
#include <stdlib.h>

double* getCollisionTimes(int** cars, int carsSize, int* carsColSize, int* returnSize) {
    double* res = (double*)malloc(sizeof(double) * carsSize);
    int* stack = (int*)malloc(sizeof(int) * carsSize);
    int top = -1;

    for (int i = carsSize - 1; i >= 0; --i) {
        int pos = cars[i][0], speed = cars[i][1];
        res[i] = -1;

        while (top >= 0) {
            int j = stack[top];
            double t = (double)(cars[j][0] - pos) / (speed - cars[j][1]);

            if (speed <= cars[j][1] || (res[j] > 0 && t >= res[j])) {
                top--;
            } else {
                res[i] = t;
                break;
            }
        }

        stack[++top] = i;
    }

    *returnSize = carsSize;
    return res;
}

int main() {
    int data[][2] = {{1,2},{2,1},{4,3},{7,2}};
    int size = sizeof(data) / sizeof(data[0]);
    int* carsColSize = malloc(sizeof(int) * size);
    int** cars = malloc(sizeof(int*) * size);

    for (int i = 0; i < size; i++) {
        cars[i] = malloc(sizeof(int) * 2);
        cars[i][0] = data[i][0];
        cars[i][1] = data[i][1];
        carsColSize[i] = 2;
    }

    int returnSize;
    double* res = getCollisionTimes(cars, size, carsColSize, &returnSize);
    printf("Collision times:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%.5f ", res[i]);
    }
    printf("\n");

    // Cleanup
    for (int i = 0; i < size; i++) free(cars[i]);
    free(cars);
    free(carsColSize);
    free(res);
    return 0;
}
