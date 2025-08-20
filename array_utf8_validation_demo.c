/*
UTF-8 Validation (LeetCode 393)

Task:
Given an integer array 'data', where each integer represents a byte (0–255),
determine if it forms a valid UTF-8 encoding sequence.

UTF-8 Rules:
- 1-byte char: 0xxxxxxx
- 2-byte char: 110xxxxx 10xxxxxx
- 3-byte char: 1110xxxx 10xxxxxx 10xxxxxx
- 4-byte char: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

All continuation bytes must start with '10'.

Example:
data = [197, 130, 1]
197 -> 11000101 (2-byte start)
130 -> 10000010 (continuation)
1   -> 00000001 (1-byte)
Valid: returns true

Invalid example:
[235, 140, 4] -> false (last byte doesn’t start with '10')
*/

#include <stdio.h>
#include <stdbool.h>

bool validUtf8(int* data, int dataSize) {
    int remaining = 0;
    for (int i = 0; i < dataSize; i++) {
        int byte = data[i];
        if (remaining > 0) {
            if ((byte >> 6) != 0b10) return false;
            remaining--;
        } else {
            if ((byte >> 5) == 0b110) remaining = 1;
            else if ((byte >> 4) == 0b1110) remaining = 2;
            else if ((byte >> 3) == 0b11110) remaining = 3;
            else if ((byte >> 7) == 0) remaining = 0;
            else return false;
        }
    }
    return remaining == 0;
}

int main(void) {
    int data1[] = {197, 130, 1};
    int data2[] = {235, 140, 4};

    printf("Example 1: %s\n", validUtf8(data1, 3) ? "true" : "false");
    printf("Example 2: %s\n", validUtf8(data2, 3) ? "true" : "false");
    return 0;
}
