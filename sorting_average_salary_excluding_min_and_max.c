/*
Average Salary Excluding the Minimum and Maximum Salary

Problem:
- Given an integer array salary where salary[i] is the salary of the ith employee,
  return the average salary excluding the minimum and maximum salary.

Approach:
1. Iterate through the array to calculate total sum, min, and max.
2. Subtract min and max from the sum.
3. Divide the result by (n - 2) to get average.

Time: O(n)
Space: O(1)

Example:
Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Excluding min = 1000 and max = 4000, sum = 3000 + 2000 = 5000; average = 5000 / 2 = 2500.
*/

#include <stdio.h>

double average(int* salary, int salarySize) {
    int min = salary[0], max = salary[0], sum = 0;
    for (int i = 0; i < salarySize; i++) {
        if (salary[i] < min) min = salary[i];
        if (salary[i] > max) max = salary[i];
        sum += salary[i];
    }
    sum -= (min + max);
    return (double)sum / (salarySize - 2);
}
