/*
Problem: Baseball Game (LeetCode 682)
URL: https://leetcode.com/problems/baseball-game/

Given a list of operations for a baseball game:
- Integer: Add that score.
- "+": Add sum of previous two scores.
- "D": Add double the previous score.
- "C": Remove the previous score.

Return the total of scores after processing all operations.

Example:
Input: ["5", "2", "C", "D", "+"]
Output: 30
 Steps:
 5 → [5]
 2 → [5,2]
 C → [5]
 D → [5,10]
 + → [5,10,15]
 Total: 30
*/

#include <stdio.h>
#include <stdlib.h>

int calPoints(char** operations, int operationsSize) {
    int* stack = malloc(operationsSize * sizeof(int));
    int top = 0;

    for (int i = 0; i < operationsSize; i++) {
        char* op = operations[i];
        if (op[0] == '+') {
            stack[top] = stack[top - 1] + stack[top - 2];
            top++;
        } else if (op[0] == 'D') {
            stack[top] = 2 * stack[top - 1];
            top++;
        } else if (op[0] == 'C') {
            top--;
        } else {
            stack[top] = atoi(op);
            top++;
        }
    }

    int total = 0;
    for (int i = 0; i < top; i++) total += stack[i];
    free(stack);
    return total;
}

int main(void) {
    char* ops1[] = {"5", "2", "C", "D", "+"};
    printf("Output: %d (expected 30)\n", calPoints(ops1, 5));

    char* ops2[] = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    printf("Output: %d (expected 27)\n", calPoints(ops2, 8));

    return 0;
}
