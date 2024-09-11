/*
Asked in Amazon, Microsoft, OYO Rooms, Goldman Sachs
Problem of the Day: Minimum Cost of ropes
Problem Description: https://medium.com/@pradeepsooryavanshee1210/minimum-cost-of-ropes-geeksforgeeks-solution-414c77026e4a
*/

class Solution
{
public:
    long long minCost(std::vector<long long> &arr)
    {
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minHeap(arr.begin(), arr.end());

        long long totalCost = 0;

        while (minHeap.size() > 1)
        {
            long long first = minHeap.top();
            minHeap.pop();
            long long second = minHeap.top();
            minHeap.pop();

            long long cost = first + second;
            totalCost += cost;

            minHeap.push(cost);
        }

        return totalCost;
    }
};