/*
Title: Car Fleet

Description:
  There are n cars going to the same destination along a one-lane road.
  Each car has a position and speed. A car fleet is formed when one car catches up to another.
  You are to return the number of car fleets that will arrive at the destination.

Example Input:
  target = 12
  position = [10, 8, 0, 5, 3]
  speed = [2, 4, 1, 1, 3]

Example Output:
  3

Explanation:
  - Car at 10 reaches in 1 hour.
  - Car at 8 reaches in 1 hour.
  - They form a fleet.
  - Car at 0 takes 12 hours. Car at 5 takes 7 hours. Car at 3 takes 3 hours.
  - Final fleet count: 3
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    double time;
} Car;

int compare(const void *a, const void *b) {
    return ((Car *)b)->position - ((Car *)a)->position;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    Car* cars = (Car *)malloc(sizeof(Car) * positionSize);
    for (int i = 0; i < positionSize; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, positionSize, sizeof(Car), compare);

    int fleets = 0;
    double currTime = 0;
    for (int i = 0; i < positionSize; i++) {
        if (cars[i].time > currTime) {
            fleets++;
            currTime = cars[i].time;
        }
    }

    free(cars);
    return fleets;
}

int main() {
    int target = 12;
    int pos[] = {10, 8, 0, 5, 3};
    int spd[] = {2, 4, 1, 1, 3};
    int n = sizeof(pos) / sizeof(pos[0]);

    int result = carFleet(target, pos, n, spd, n);
    printf("Car fleets reaching the destination: %d\n", result); // Expected: 3

    return 0;
}
