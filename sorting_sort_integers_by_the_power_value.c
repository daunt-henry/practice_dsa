/*
Sort Integers by The Power Value

Problem:
- For a number x, define its "power value" as:
    if x is even: x = x / 2
    if x is odd: x = 3 * x + 1
  Repeat until x == 1. The power value is the number of steps taken.

- Given a range [lo, hi], return the k-th integer when sorted by power value.
  If two numbers have the same power value, return the smaller one.

Approach:
- For each number in the range, compute power value.
- Sort using a custom comparator on (powerValue, value).
- Return the (k-1)-th element.

Time: O((hi-lo+1) * log(hi-lo+1) + steps for power calc)
Space: O(hi-lo+1)

Example:
Input: lo = 12, hi = 15, k = 2
Power values: {12:9, 13:9, 14:17, 15:17}
Sorted: [12,13,14,15]
Output: 13
*/

#include <stdlib.h>

int power(int x) {
    int steps = 0;
    while (x != 1) {
        x = (x % 2 == 0) ? x / 2 : 3 * x + 1;
        steps++;
    }
    return steps;
}

typedef struct {
    int value;
    int powerVal;
} NumPower;

int cmp(const void *a, const void *b) {
    NumPower *n1 = (NumPower *)a;
    NumPower *n2 = (NumPower *)b;
    if (n1->powerVal == n2->powerVal)
        return n1->value - n2->value;
    return n1->powerVal - n2->powerVal;
}

int getKth(int lo, int hi, int k) {
    int size = hi - lo + 1;
    NumPower *arr = malloc(size * sizeof(NumPower));
    for (int i = 0; i < size; i++) {
        arr[i].value = lo + i;
        arr[i].powerVal = power(lo + i);
    }

    qsort(arr, size, sizeof(NumPower), cmp);
    int result = arr[k - 1].value;
    free(arr);
    return result;
}
