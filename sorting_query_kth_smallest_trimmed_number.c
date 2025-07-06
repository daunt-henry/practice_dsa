/*
Question:
You are given a list of strings `nums`, where each string is the same length and represents a number.
You are also given a 2D array `queries` where each query is of the form [k, trim].

Each query asks: 
  - Trim the last `trim` digits from each number in `nums`.
  - Find the k-th smallest trimmed number and return its **original index** in the input array.

Approach:
- Extract trimmed suffixes.
- Sort based on trimmed string and original index.
- Return the index of the k-th smallest.

Example:
Input:
nums = ["102","473","251","814"]
queries = [[1,1],[2,3],[4,2],[1,2]]
Output: [2,2,1,0]
*/

int cmp(const void* a, const void* b) {
    char** x = (char**)a;
    char** y = (char**)b;
    return strcmp(*x, *y);
}

int* smallestTrimmedNumbers(char ** nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    *returnSize = queriesSize;
    int* result = (int*)malloc(sizeof(int) * queriesSize);

    for (int i = 0; i < queriesSize; i++) {
        int k = queries[i][0];
        int trim = queries[i][1];

        char** trimmed = (char**)malloc(sizeof(char*) * numsSize);
        for (int j = 0; j < numsSize; j++) {
            trimmed[j] = nums[j] + strlen(nums[j]) - trim;
        }

        int* indices = (int*)malloc(sizeof(int) * numsSize);
        for (int j = 0; j < numsSize; j++) indices[j] = j;

        // Simple bubble sort on trimmed
        for (int x = 0; x < numsSize - 1; x++) {
            for (int y = x + 1; y < numsSize; y++) {
                if (strcmp(trimmed[x], trimmed[y]) > 0 || (strcmp(trimmed[x], trimmed[y]) == 0 && indices[x] > indices[y])) {
                    char* tempStr = trimmed[x];
                    trimmed[x] = trimmed[y];
                    trimmed[y] = tempStr;

                    int tempIdx = indices[x];
                    indices[x] = indices[y];
                    indices[y] = tempIdx;
                }
            }
        }

        result[i] = indices[k - 1];
        free(trimmed);
        free(indices);
    }

    return result;
}

/*
Output:
Input: nums = ["102","473","251","814"], queries = [[1,1],[2,3],[4,2],[1,2]]
Output: [2,2,1,0]
*/
