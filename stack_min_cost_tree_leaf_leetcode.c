/*
Title: Minimum Cost Tree From Leaf Values

Description:
  Given an array arr of positive integers representing the values of leaves in an in-order traversal,
  you need to construct a binary tree where each node is either a leaf node or has two children.
  The value of each non-leaf node is equal to the product of the largest leaf values in its left and right subtree.

  Return the minimum possible sum of the values of each non-leaf node.

Example Input:
  arr = [6, 2, 4]

Example Output:
  32

Explanation:
  There are two ways to build the tree:
  - (6*(2*4)) = 24 + 8 = 32
  - (6*2 + 6*4) = 12 + 24 = 36 → not minimum
  The optimal cost is 32.
*/

#include <stdio.h>
#include <limits.h>

int mctFromLeafValues(int* arr, int arrSize) {
    int stack[100], top = -1, res = 0;
    stack[++top] = INT_MAX;

    for (int i = 0; i < arrSize; ++i) {
        while (stack[top] <= arr[i]) {
            int mid = stack[top--];
            res += mid * (stack[top] < arr[i] ? stack[top] : arr[i]);
        }
        stack[++top] = arr[i];
    }

    while (top > 1) {
        res += stack[top] * stack[top - 1];
        top--;
    }

    return res;
}

int main() {
    int arr[] = {6, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = mctFromLeafValues(arr, size);
    printf("Input: [6, 2, 4]\n");
    printf("Output: %d\n", result);  // Expected: 32

    return 0;
}
