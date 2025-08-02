/*
Problem: Summary Ranges

Given a sorted integer array without duplicates, return the summary of its ranges.

Example:
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
*/

#include <stdio.h>
#include <stdlib.h>

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char** res = (char**)malloc(sizeof(char*) * numsSize);
    *returnSize = 0;

    int i = 0;
    while (i < numsSize) {
        int start = i;
        while (i + 1 < numsSize && nums[i + 1] == nums[i] + 1) i++;
        
        char* range = (char*)malloc(32);
        if (start == i)
            sprintf(range, "%d", nums[start]);
        else
            sprintf(range, "%d->%d", nums[start], nums[i]);
        
        res[(*returnSize)++] = range;
        i++;
    }
    return res;
}

int main() {
    int nums[] = {0,1,2,4,5,7};
    int returnSize;
    char** result = summaryRanges(nums, 6, &returnSize);
    
    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("\"%s\"", result[i]);
        if (i < returnSize - 1) printf(", ");
        free(result[i]);
    }
    printf("]\n");

    free(result);
    return 0;
}
