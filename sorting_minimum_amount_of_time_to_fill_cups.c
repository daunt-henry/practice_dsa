/*
Question:
You have a water dispenser with 3 types of cups: cold, warm, and hot.
Each second, you can:
- Fill two different types of cups, or
- Fill one cup of any type.
Return the minimum number of seconds to fill all cups.

Approach:
- sum = total number of cups
- max = the maximum cups of a single type
- The minimum time is max between max and ceil(sum / 2)
  because you can fill at most two cups per second.

Example:
Input: amount = [1, 4, 2]
Output: 4
*/

int fillCups(int* amount, int amountSize){
    int max = 0, sum = 0;
    for (int i = 0; i < amountSize; i++) {
        sum += amount[i];
        if (amount[i] > max)
            max = amount[i];
    }
    return (sum + 1) / 2 > max ? (sum + 1) / 2 : max;
}

/*
Output:
Input: [1, 4, 2]
Output: 4
*/
