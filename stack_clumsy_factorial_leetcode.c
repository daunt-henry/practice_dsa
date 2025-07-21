/*
Title: Clumsy Factorial

Description:
  The clumsy factorial of a positive integer N is calculated using this pattern:
    N * (N-1) / (N-2) + (N-3) - (N-4) * (N-5) / (N-6) + (N-7) ...
  The operations repeat with *, /, +, - in this cycle, and standard precedence is followed.

Example Input:
  N = 10

Example Output:
  12

Explanation:
  clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1 = 12
*/

#include <stdio.h>

int clumsy(int N) {
    int stack[10000];
    int top = -1;
    stack[++top] = N;
    N--;

    int index = 0;
    while (N > 0) {
        if (index % 4 == 0) {
            stack[top] = stack[top] * N;
        } else if (index % 4 == 1) {
            stack[top] = stack[top] / N;
        } else if (index % 4 == 2) {
            stack[++top] = N;
        } else {
            stack[++top] = -N;
        }
        index++;
        N--;
    }

    int result = 0;
    for (int i = 0; i <= top; i++) {
        result += stack[i];
    }
    return result;
}

int main() {
    int N1 = 10;
    printf("Input: %d\n", N1);
    printf("Clumsy Factorial: %d\n", clumsy(N1)); // Expected: 12

    int N2 = 4;
    printf("Input: %d\n", N2);
    printf("Clumsy Factorial: %d\n", clumsy(N2)); // Expected: 7

    int N3 = 1;
    printf("Input: %d\n", N3);
    printf("Clumsy Factorial: %d\n", clumsy(N3)); // Expected: 1

    return 0;
}
