/*
Title: Validate Stack Sequences

Description:
  Given two integer arrays pushed and popped, check whether the given popped sequence 
  can be the result of popping elements from a stack that is being pushed in the order of pushed.

Example Input:
  pushed = [1,2,3,4,5]
  popped = [4,5,3,2,1]

Example Output:
  true

Explanation:
  Push 1, 2, 3, 4 -> pop 4, push 5 -> pop 5, pop 3, pop 2, pop 1 — valid sequence.
*/

#include <stdio.h>
#include <stdbool.h>

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    int stack[pushedSize];
    int top = -1, j = 0;

    for (int i = 0; i < pushedSize; ++i) {
        stack[++top] = pushed[i];
        while (top >= 0 && j < poppedSize && stack[top] == popped[j]) {
            top--;
            j++;
        }
    }

    return top == -1;
}

int main() {
    int pushed1[] = {1, 2, 3, 4, 5};
    int popped1[] = {4, 5, 3, 2, 1};
    printf("Test 1 - Expected: true, Got: %s\n",
           validateStackSequences(pushed1, 5, popped1, 5) ? "true" : "false");

    int pushed2[] = {1, 2, 3, 4, 5};
    int popped2[] = {4, 3, 5, 1, 2};
    printf("Test 2 - Expected: false, Got: %s\n",
           validateStackSequences(pushed2, 5, popped2, 5) ? "true" : "false");

    return 0;
}
