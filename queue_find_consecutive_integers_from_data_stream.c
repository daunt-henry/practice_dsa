/*
Title: Find Consecutive Integers from a Data Stream

Description:
For a stream of integers, return true if the last `k` integers are all equal to a specific target `value`.

You are given two integers `value` and `k`. Implement a `DataStream` class:
- `DataStream(int value, int k)` initializes the object with integers `value` and `k`.
- `boolean consec(int num)` checks if the last `k` integers (including this one) are equal to `value`.

Example:
Input:
["DataStream", "consec", "consec", "consec", "consec"]
[[4, 3], [4], [4], [4], [3]]

Output:
[null, false, false, true, false]

Explanation:
DataStream stream = new DataStream(4, 3); // target value is 4, and we need 3 consecutive 4s
stream.consec(4); // false
stream.consec(4); // false
stream.consec(4); // true
stream.consec(3); // false
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int value;
    int k;
    int count;
} DataStream;

DataStream* dataStreamCreate(int value, int k) {
    DataStream* obj = (DataStream*)malloc(sizeof(DataStream));
    obj->value = value;
    obj->k = k;
    obj->count = 0;
    return obj;
}

bool dataStreamConsec(DataStream* obj, int num) {
    if (num == obj->value) {
        obj->count++;
    } else {
        obj->count = 0;
    }
    return obj->count >= obj->k;
}

void dataStreamFree(DataStream* obj) {
    free(obj);
}

int main() {
    DataStream* stream = dataStreamCreate(4, 3);

    printf("%s\n", dataStreamConsec(stream, 4) ? "true" : "false"); // false
    printf("%s\n", dataStreamConsec(stream, 4) ? "true" : "false"); // false
    printf("%s\n", dataStreamConsec(stream, 4) ? "true" : "false"); // true
    printf("%s\n", dataStreamConsec(stream, 3) ? "true" : "false"); // false

    dataStreamFree(stream);
    return 0;
}
