/*
Problem: Self Crossing

You are given an array `x` of positive integers. Starting at (0,0), you move:
- x[0] units north,
- x[1] units west,
- x[2] units south,
- x[3] units east,
... and so on, turning counter-clockwise.

Return `true` if your path crosses itself at any point, otherwise `false`.

Example:
x = [2, 1, 1, 2]  -> true  (4th move crosses the 1st)
x = [1, 2, 3, 4]  -> false (simple spiral)
x = [1, 1, 1, 1]  -> true  (simple square)
*/

#include <stdio.h>
#include <stdbool.h>

bool isSelfCrossing(int* x, int size) {
    if (size < 4) return false;
    for (int i = 3; i < size; ++i) {
        if (x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) return true;
        if (i >= 4 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2]) return true;
        if (i >= 5 &&
            x[i - 2] >= x[i - 4] &&
            x[i - 1] <= x[i - 3] &&
            x[i - 1] + x[i - 5] >= x[i - 3] &&
            x[i] >= x[i - 2] - x[i - 4]) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr1[] = {2, 1, 1, 2};
    int arr2[] = {1, 2, 3, 4};
    int arr3[] = {1, 1, 1, 1};

    printf("Test1 (crossing): %s\n", isSelfCrossing(arr1, 4) ? "true" : "false");
    printf("Test2 (spiral): %s\n", isSelfCrossing(arr2, 4) ? "true" : "false");
    printf("Test3 (square): %s\n", isSelfCrossing(arr3, 4) ? "true" : "false");

    return 0;
}
