/*
Problem:
You're given an array `happiness[]` where `happiness[i]` is the happiness a child gives if chosen first.
If a child is chosen after `t` other children, their happiness becomes `max(0, happiness[i] - t)`.

Select exactly `k` children to **maximize total happiness**.

Return the maximum possible total happiness.

Example Input:
happiness = [1, 2, 3], k = 2

Expected Output:
4

Explanation:
Choose children with happiness 3 and 2:
- 3 → first → 3
- 2 → second → 2 - 1 = 1  
Total = 4
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
    qsort(happiness, happinessSize, sizeof(int), cmp);

    long long total = 0;
    for (int i = 0; i < k; ++i) {
        int value = happiness[i] - i;
        if (value > 0)
            total += value;
    }

    return total;
}

int main() {
    int happiness[] = {1, 2, 3};
    int k = 2;

    long long result = maximumHappinessSum(happiness, 3, k);
    printf("Maximum happiness: %lld\n", result);  // Output: 4

    return 0;
}
