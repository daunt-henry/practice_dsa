/*
Title: Time Needed to Buy Tickets


You have a queue of people, each wants to buy a number of tickets.
The person at index `k` is you.

Every person buys one ticket at a time from the front of the queue.
If someone still needs tickets, they move to the back of the queue.

Return how many seconds it takes until you finish buying all your tickets.

Example:
Input: tickets = [2,3,2], k = 2
Output: 6

Explanation:
- Round 1: everyone buys 1 ticket → [1,2,1]
- Round 2: everyone buys 1 ticket → [0,1,0]
- You are at index 2 and finished at time = 6

Constraints:
- tickets.length <= 100
- 1 <= tickets[i] <= 100
- 0 <= k < tickets.length
*/

#include <stdio.h>

int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int time = 0;
    for (int i = 0; i < ticketsSize; i++) {
        if (i <= k)
            time += tickets[i] < tickets[k] ? tickets[i] : tickets[k];
        else
            time += tickets[i] < tickets[k] ? tickets[i] : tickets[k] - 1;
    }
    return time;
}

// Sample test
int main() {
    int tickets[] = {2, 3, 2};
    int k = 2;

    int result = timeRequiredToBuy(tickets, 3, k);
    printf("Time needed to buy all tickets: %d\n", result);  // Output: 6

    return 0;
}
