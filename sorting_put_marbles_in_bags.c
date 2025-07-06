/*
🔹 Problem: Put Marbles in Bags

You have `n` bags of weights. You want to divide them into `k` groups, placing consecutive weights in each group. 
Calculate the difference between the maximum and minimum possible total scores.
Score of a group = weight[first] + weight[last]

🔸 Example:
Input: weights = [1,3,5,1], k = 2  
Output: 4

Explanation:
All possible splits: 
[1][3,5,1] → score = 1+1 = 2
[1,3][5,1] → score = 1+3 + 5+1 = 10
[1,3,5][1] → score = 1+5 + 1+1 = 8  
max - min = 10 - 6 = 4
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

long long putMarbles(int* weights, int weightsSize, int k){
    if (k == 1 || k == weightsSize) return 0;

    int pairSums[weightsSize - 1];
    for (int i = 0; i < weightsSize - 1; i++) {
        pairSums[i] = weights[i] + weights[i + 1];
    }

    qsort(pairSums, weightsSize - 1, sizeof(int), cmp);

    long long minSum = 0, maxSum = 0;
    for (int i = 0; i < k - 1; i++) {
        minSum += pairSums[i];
        maxSum += pairSums[weightsSize - 2 - i];
    }

    return maxSum - minSum;
}

/*
🔸 Test Case:
Input:
weights = [1, 3, 5, 1], k = 2
Output:
4
*/
